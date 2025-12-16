#include <iostream>
#include <queue>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <chrono>

//with unbounded buffer

class UnboundedBuffer {
private:
    std::queue<int> buffer;
    std::mutex mtx;
    std::condition_variable cv_data_available;

public:
    // Producer never waits; it just pushes and notifies
    void produce(int item) {
        {
            std::lock_guard<std::mutex> lock(mtx);
            buffer.push(item);
            std::cout << "Produced: " << item << " | Buffer size: " << buffer.size() << std::endl;
        }
        cv_data_available.notify_one(); // Wake up one waiting consumer
    }

    // Consumer waits only if the buffer is empty
    int consume() {
        std::unique_lock<std::mutex> lock(mtx);
        
        // Wait until there is at least one item
        cv_data_available.wait(lock, [this]() { return !buffer.empty(); });

        int item = buffer.front();
        buffer.pop();
        std::cout << "Consumed: " << item << " | Buffer size: " << buffer.size() << std::endl;
        
        return item;
    }
};

void producer_thread(UnboundedBuffer& buf) {
    for (int i = 1; i <= 10; ++i) {
        buf.produce(i);
        std::this_thread::sleep_for(std::chrono::milliseconds(50)); // Fast production
    }
}

void consumer_thread(UnboundedBuffer& buf) {
    for (int i = 0; i < 10; ++i) {
        buf.consume();
        std::this_thread::sleep_for(std::chrono::milliseconds(150)); // Slow consumption
    }
}

int main() {
    UnboundedBuffer shared_buffer;

    std::thread t1(producer_thread, std::ref(shared_buffer));
    std::thread t2(consumer_thread, std::ref(shared_buffer));

    t1.join();
    t2.join();

    return 0;
}

// Key Differences in Unbounded Implementation

// One Condition Variable: You only need to signal the consumer. Since the producer never "waits" for space, a cv_not_full is unnecessary.
// Producer uses lock_guard: Because the producer doesn't need to wait and unlock inside a loop, std::lock_guard is cleaner and safer than std::unique_lock.
// Memory Warning: It can lead to memory exhaustion if the producer is much faster than the consumer over a long period.

//  Why choose this over Bounded?

// Simplicity: Use this when you are certain the consumer can eventually keep up and you want to reduce synchronization overhead.
// Performance: The producer is never blocked, ensuring the production side of your application stays high-performance and low-latency. 


//with bounded buffer
class BoundedBuffer {
private:
    std::queue<int> buffer;
    size_t capacity;
    std::mutex mtx;
    std::condition_variable cv_not_full;  // Signal when there's space to produce
    std::condition_variable cv_not_empty; // Signal when there's data to consume

public:
    explicit BoundedBuffer(size_t cap) : capacity(cap) {}

    void produce(int item) {
        std::unique_lock<std::mutex> lock(mtx);
        
        // Wait if buffer is full (while loop prevents spurious wakeups)
        cv_not_full.wait(lock, [this]() { return buffer.size() < capacity; });

        buffer.push(item);
        std::cout << "Produced: " << item << " | Buffer size: " << buffer.size() << std::endl;

        // Notify one waiting consumer that data is available
        cv_not_empty.notify_one();
    }

    int consume() {
        std::unique_lock<std::mutex> lock(mtx);

        // Wait if buffer is empty
        cv_not_empty.wait(lock, [this]() { return !buffer.empty(); });

        int item = buffer.front();
        buffer.pop();
        std::cout << "Consumed: " << item << " | Buffer size: " << buffer.size() << std::endl;

        // Notify one waiting producer that space is available
        cv_not_full.notify_one();
        return item;
    }
};

void producer_task(BoundedBuffer& buf) {
    for (int i = 1; i <= 10; ++i) {
        buf.produce(i);
        std::this_thread::sleep_for(std::chrono::milliseconds(100)); // Simulate work
    }
}

void consumer_task(BoundedBuffer& buf) {
    for (int i = 1; i <= 10; ++i) {
        buf.consume();
        std::this_thread::sleep_for(std::chrono::milliseconds(150)); // Simulate slow consumption
    }
}

int main() {
    BoundedBuffer shared_buffer(5); // Buffer with capacity of 5

    std::thread t1(producer_task, std::ref(shared_buffer));
    std::thread t2(consumer_task, std::ref(shared_buffer));

    t1.join();
    t2.join();

    return 0;
}


// Core Components
// 1. Synchronization Primitives
// std::mutex mtx: Ensures "Mutual Exclusion." Only one thread can modify the queue at a time.
// std::condition_variable cv_not_full: Used by the producer. If the buffer is at capacity, the producer "sleeps" here until a consumer removes an item.
// std::condition_variable cv_not_empty: Used by the consumer. If the buffer is empty, the consumer "sleeps" here until a producer adds an item. 

// 2. The Producer (produce method)
// Locking: It acquires a unique_lock on the mutex.
// Waiting: It checks if the buffer is full. The cv_not_full.wait function uses a Lambda function [this]() { return buffer.size() < capacity; }. If this returns false, the thread releases the lock and sleeps.
// Action: Once there is space, it pushes an item into the queue.
// Notification: It calls cv_not_empty.notify_one(), signaling a sleeping consumer that there is now data to read. 

// 3. The Consumer (consume method)
// Locking: It acquires the mutex lock.
// Waiting: It checks if the buffer is empty. If it is, cv_not_empty.wait puts the thread to sleep until the producer adds something.
// Action: It retrieves the front item and removes it from the queue.
// Notification: It calls cv_not_full.notify_one(), signaling a sleeping producer that there is now an empty slot available. 


// Execution Flow in main()
// Initialization: A buffer is created with a capacity of 5.
// Threads: Two threads are launched:
// Producer Task: Tries to add numbers 1-10 every 100ms.
// Consumer Task: Tries to remove numbers 1-10 every 150ms.


// The "Bounded" Behavior:
// Because the consumer (150ms) is slower than the producer (100ms), the buffer will eventually fill up.
// When the buffer reaches 5 items, the Producer thread will block (stop) at the cv_not_full.wait line.
// The producer will only wake up and add the 6th item after the consumer has removed the 1st item.
// Cleanup: t1.join() and t2.join() ensure the main program waits for both tasks to finish before exiting. 


// Why this is robust:
// Spurious Wakeups: The while loop logic inside the wait function (via the Lambda) ensures that if a thread wakes up accidentally without a signal, it checks the condition again and goes back to sleep if necessary.
// Thread Safety: The std::mutex prevents two threads from calling buffer.push and buffer.pop at the exact same microsecond, which would crash a standard std::queue. 
