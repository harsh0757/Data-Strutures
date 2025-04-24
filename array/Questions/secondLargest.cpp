#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int optimal(vector<int> arr){
    int largest = arr[0], slargest = -1;
    for(int i=1;i<arr.size();i++){
        if(arr[i] > largest){
            slargest = largest;
            largest = arr[i];
        } else if(arr[i] < largest && arr[i] > slargest){
            slargest = arr[i];
        }
    }
    return slargest;
}

int better2(vector<int> arr){
    int largest = arr[0];
    for(int i=0;i<arr.size();i++){
        if(arr[i] >= largest){
            largest = arr[i];
        }
    }
    int slargest = -1;
    for(int i=0;i<arr.size();i++){
        if(arr[i] != largest && arr[i] > slargest){
            slargest = arr[i];
        }
    }
    return slargest;
}

int better(vector<int> &arr) 
{
    sort(arr.begin(), arr.end());
    int largest = arr[arr.size() - 1];
    int Slargest = -1;
    for (int i = arr.size() - 2; i >= 0; i--)
    {
        if (arr[i] != largest)
        {
            Slargest = arr[i];
            break;
        }
    }
    return Slargest;
}

int findSLargest(vector<int> arr)
{
    // if duplicate elements are there this will not work
    int size = arr.size();
    sort(arr.begin(), arr.end());

    return arr[size - 2];
}

int main()
{
    vector<int> arr = {5, 2, 1, 11, 45, 78, 20};
    cout << "The Second Largest element in the array is: " << optimal(arr) << endl;
}