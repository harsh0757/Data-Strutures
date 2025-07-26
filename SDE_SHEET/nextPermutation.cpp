#include<iostream>
#include<algorithm>
using namespace std;

//how many possible rearrangments are possible all these ways called permutation 
//n! and write in a dictonary order
//after writing all the possible ways return the next permutation and if not go back to first

// brute force
// 1.Generate all the permutation in sorted order
// 2.Do a linear serach in order to find the answer
// 3.Next index will be my answer if not return 1st one
//*NOTE* It is will take a time complexity of very high order TC -> (N! * N)

//optimal implement next permutation in STL
// arr --> {2,1,5,4,3,0,0}
//1.longer perfix match and find the break point
//  ---> a[i] < a[i+1]
// 2.find someone greater than 1 but the samllest one that tyou stay close
//3.Try to place remaining in sorted order

// TC ---> O(3N)  SC --> O(1)
vector<int> nextPerm_OP(vector<int>& arr){
    int index = -1;
    int n = arr.size();
    for(int i=n-2;i>=0;i--){
        if(arr[i] < arr[i+1]){
            index = i;
            break;
        }
    }
    if(index == -1){
        reverse(arr.begin(), arr.end());
        return arr;
    }

    for(int i=n-1;i>index;i--){
        if(arr[i] > arr[index]){
            swap(arr[i], arr[index]);
            break;
        }
    }
    reverse(arr.begin() + index + 1, arr.end());
    return arr;
}


//better solution using STL
vector<int> nextPerm(vector<int> arr){
    next_permutation(arr.begin(), arr.end());
    return arr;
}

int main(){
    vector<int> arr = {2,1,5,4,3,0,0};
    vector<int> result = nextPerm_OP(arr);
    for(int i=0;i<result.size();i++){
        cout<<result[i]<<" ";
    }
    cout<<endl;
    return 0;
}