#include<iostream>
#include<vector>
using namespace std;

// for printing maximum subarray of a array-----||------
void printSubArray(const vector<int>& arr){
    for(int i=0;i<arr.size();i++){
        for(int j=i;j<arr.size();j++){
            for(int k=i;k<=j;k++){
                cout<<arr[k];
            }
            cout<<endl;
        }
    }
    return;
}

// for printing maximum sum of sub array-----||-----||----
void printmaxsum(vector<int>& arr){
    if(arr.empty()){
        cout<<"0"<<endl;
        return;
    }
    int maxsum=INT_MIN;
    for(int i=0;i<arr.size();i++){
       int cursum=0;
        for(int j=i;j<arr.size();j++){
            cursum+=arr[j];
             maxsum=max(maxsum,cursum);
        }
    }
    cout<<maxsum<<endl;
    return;
}

// kadane's algorithm ----||-----||------||---
void kadaneAlgo(vector<int>& arr){
    if(arr.empty()) {
        cout<<"0"<<endl;
        return;
    }
    int maxsum=INT_MIN;
     int cursum=0;
    for(int i=0;i<arr.size();i++){
       cursum+=arr[i];
        maxsum=max(maxsum,cursum);
        if(cursum<0){
            cursum=0;
        }
    }
    cout<<maxsum<<endl;
    return;
}
// for finding majority element by boyer moore voting algorithm
int majorityele1(vector<int>& arr){
    int element=0;
    int count=0;
    for(int i=0;i<arr.size();i++){
        if(count==0){
            element=arr[i];
        }
        if(element==arr[i]){
            count++;
        }else{
            count--;
        }

    }
    return element;
}
int main(){
   vector<int>arr={1,2,2,1,1,2,2};
   cout<<majorityele1(arr)<<endl;
    return 0;
}