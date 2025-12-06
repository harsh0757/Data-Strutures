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
    
    
    if(lemonadeChange(arr)){
        cout<<"All lemons are sold out"<<endl;
    } else {
        cout<<"lemons are still in the stock"<<endl;
    }
    
    cout<<"The averaged time for shorestJobFirst is : "<<shorestJobFirst(processes)<<endl;
}
