git #include<iostream>
using namespace std;

bool linearSearch(int arr[], int size, int target){
    for(int i=0;i<size;i++){
        if(arr[i] == target)
            return true;
    }
    return false;
}

int main(){
    int arr[10] = {5,7,-2,10,22,-2,0,5,22,1};
    //whether key is present in it or not
    cout<<"Enter the element to search for : "<<endl;
    int target;
    cin>>target;
    
    bool found = linearSearch(arr, 10, target);

    if(found)
        cout<<"Element is present" <<endl;
    else
        cout<<"Element is not present"<<endl;
}