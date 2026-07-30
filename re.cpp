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
int main(){
   vector<int>arr={1,2,3,4,5};
   printSubArray(arr);
    return 0;
}