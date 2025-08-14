//scheduling policy that selects the waiting process with smallest
//execution time to execute next

#include<iostream>
using namespace std;

int sjf(vector<int>& process){
    int time = 0;
    int w_time = 0;
    sort(process.begin(), process.end());

    for(int i=0;i<process.size();i++){
        w_time += time;
        time += process[i];
    }
    return w_time/process.size();
}

int main(){
    vector<int> process = {4,3,7,1,2};
    cout<<"Shorest job time execution average : "<<sjf(process)<<endl;
}