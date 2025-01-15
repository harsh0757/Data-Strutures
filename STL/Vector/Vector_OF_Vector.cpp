#include<iostream>
#include<vector>
using namespace std;

void print(vector<int> v){
    cout<<"Size : "<<v.size()<< endl;
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}

// int main(){
// //how to take input
//     vector<vector<int>> v;
//     int N;
//     cin>>N;
//     for(int i=0;i<N;i++){
//         int n;
//         cin>>n;
//         vector<int > temp;
//         for(int j=0;j<n;j++){
//             int x;
//             cin>>x;
//             // v[i].push_back(x);  cannot do this step because ith row doesn't exist
//             //we have to take input independently
//             temp.push_back(x);
//         }
//         v.push_back(temp);
//     }
//     for(int i=0;i<v.size();i++){
//         print(v[i]);
//     }
// }
//2nd method
int main(){
//how to take input
    vector<vector<int>> v;
    int N;
    cin>>N;
    for(int i=0;i<N;i++){
        int n;
        cin>>n;
        v.push_back(vector<int> () ); //here ith vector exists
        for(int j=0;j<n;j++){
            int x;
            cin>>x;
            // v[i].push_back(x);  cannot do this step because ith row doesn't exist
            //we have to take input independently
            v[i].push_back(x);
        }
    }
    for(int i=0;i<v.size();i++){
        print(v[i]);
    }
    cout<<v[0][1]; // see what the indexs are representing and use the fucntion accordingly
}