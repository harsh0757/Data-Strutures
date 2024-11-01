#include<iostream>
#include<thread>
using namespace std;

// void work(){
//     for(int i=0;i<10;i++){
//         cout<<i<<endl;
//     }
// }

int main(){
    int count = 0;
    const int ITERATIONS = 1000;

    thread t1([&count, ITERATIONS](){
        for(int i=0;i<ITERATIONS;i++){
            ++count;
        }
    });

    // thread t2([](){});

    t1.join();
    // t2.join();

    cout<<count<<endl;
    return 0;
}