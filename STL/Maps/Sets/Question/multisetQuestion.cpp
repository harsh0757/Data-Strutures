//question link : https://www.hackerearth.com/practice/data-structures/trees/heapspriority-queues/practice-problems/algorithm/monk-and-the-magical-candy-bags/
#include<iostream>
#include<set>

using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
    //no. of bags and k minutes
        int n, k;
        cin>>n>>k;
        multiset<long long> bags;

        for(int i=0;i<n;i++){
            int candy_cnt;
            cin>>candy_cnt;
            bags.insert(candy_cnt);
        }
        long long total_candies = 0;
        for(int i=0;i<k;i++){
            auto last_it = (--bags.end()); //last iterator
            int candy_cnt = *last_it; //maximum candies count
            total_candies += candy_cnt;
        //when we provide the iterator it will be O(1) operation otherwise log(n)
            bags.erase(last_it);
            bags.insert(candy_cnt/2);
        }
        cout<<total_candies<<endl;
    }
}