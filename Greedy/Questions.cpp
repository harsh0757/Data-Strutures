#include <bits/stdc++.h>
using namespace std;

//Q6
class Job{
public:
  int id;
  int deadline;
  int profit;
};

pair<int, int> JobSequencing(vector<Job>& jobs){
    sort(jobs.begin(), jobs.end(), [](const Job& a, const Job& b){
        return a.profit > b.profit;
    });
    int totalProfit = 0;
    int maxDeadline = 0;
    int count = 0;
    
    for(auto j : jobs) maxDeadline = max(maxDeadline, j.deadline);
    
    vector<int> slots(maxDeadline + 1, -1);
    
    for(auto job : jobs){
        for(int i=min(maxDeadline, job.deadline); i >= 1; i--){ //i>=0 will add extra job which doesn't exists
            if(slots[i] == -1){
                count = count + 1;
                slots[i] = job.id;
                totalProfit += job.profit;
                break;
            }
        }
    }
    return {count, totalProfit};
}
//Q5
int jumpGame2_op(vector<int>& jumps){
    int totalJumps = 0;
    int leftp = 0;
    int rightp = 0;
    
    //we are traverse the every element once only --> so TC is O(N)
    while(rightp < jumps.size() - 1){ //this is the check if we reached the end or not
        int farthest = 0;
        for(int i = leftp; i<=rightp; i++){
            farthest = max(farthest, i + jumps[i]);
        }
        totalJumps = totalJumps + 1;
        leftp = rightp + 1;
        rightp = farthest;
    }
    return totalJumps;  
}

int jumpGame2(vector<int>& jumps, int index, int totalJumps){
    if(index >= jumps.size() - 1){
        return totalJumps;
    }
    
    int mini = INT_MAX;
    for(int i=1;i<=jumps[index];i++){    //don't start with zero it will go to same index
        mini = min(mini, jumpGame2(jumps, index + i, totalJumps + 1));
    }
    return mini;
}
//Q4
bool jumpGame1(vector<int>& jumps){
    int maxIndex = 0;
    
    for(int i=0;i<jumps.size();i++){
        if(i > maxIndex) return false;
        
        maxIndex = max(maxIndex, i + jumps[i]);
        if(maxIndex >= jumps.size() - 1) return true;
    }
    return true;
}
//Q3
int shorestJobFirst(vector<int>& processes){
    int time = 0;
    int waitTime = 0;
    
    sort(processes.begin(), processes.end());
    
    for(int i=0;i<processes.size();i++){
        waitTime = waitTime + time;
        time += processes[i];
    }
    return waitTime/processes.size();
}

//Q2
bool lemonadeChange(vector<int>& bills){
    int count5 = 0;
    int count10 = 0;
    
    for(int i=0;i<bills.size();i++){
        if(bills[i] == 5) {
            count5++;
        }else if(bills[i] == 10) {
            if(count5 > 0){
                count10++;
                count5--;
            } else {
                return false;
            }
        } else {
            if(count5 > 0 && count10 > 0){
                count5--;
                count10--;
            } else if(count5 >= 3){
                count5 -= 3;
            } else {
                return false;
            }
        }
    }
    return true;
}

//Q1
int assignCookies(vector<int> &greed, vector<int> &cookies){
    sort(greed.begin(), greed.end());
    sort(cookies.begin(), cookies.end());
    
    int n = greed.size(), m = cookies.size();
    
    int leftP = 0, rightP = 0;
    
    while(leftP < m && rightP < n){
        if(greed[rightP] <= cookies[leftP]){
            rightP = rightP + 1;
        }
        leftP = leftP + 1;
    }
    return rightP;
}

int main() {
    vector<int> greed = {1,5,3,3,4};
    vector<int> cookies = {4,2,1,2,1,3};
    vector<int> arr = {5,5,10,10,20};
    vector<int> processes = {4,3,7,1,2};

    vector<int> jumps = {2,3,1,4,1,1,1,2};
     vector<Job> jobs = {
        {1, 2, 100},
        {2, 1, 19},
        {3, 2, 27},
        {4, 1, 25},
        {5, 3, 15}
    };
    
    cout<<"Minimun number of jumps to reach end : "<<jumpGame2_op(jumps)<<endl;
    auto res = JobSequencing(jobs);
    cout << "Jobs scheduled: " << res.first << "\n";
    cout << "Total Profit: " << res.second << "\n";
    
    
    if(lemonadeChange(arr)){
        cout<<"All lemons are sold out"<<endl;
    } else {
        cout<<"lemons are still in the stock"<<endl;
    }
    
    cout<<"The averaged time for shorestJobFirst is : "<<shorestJobFirst(processes)<<endl;
}
