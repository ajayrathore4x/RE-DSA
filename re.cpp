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
double myPow(double x, int n) {
    if(n==0) return 1.0;
    if(x==0) return 0.0;
    if(x==1) return 1.0;
    if(n==1) return x;
    if(x==-1 && n%2==0) return 1.0;
    if(x==-1 && n%2!=0) return -1.0;

    long binform=n;
    if (n<0){
        x=1/x;
        binform=-binform;
    }
    double ans=1;
    while(binform>0){
        if(binform % 2==1){
            ans*=x;
        }
        x*=x;
        binform/=2;
    }
    return ans;
}
int maxProfit(vector<int>& prices) {
    if(prices.empty()||prices.size()==1) return 0;
    int minprice=INT_MAX;
    int maxprofit=0;
    for(int i=0;i<prices.size();i++){
        if(minprice>prices[i]){
            minprice=prices[i];
        }
        else{
            int profit=prices[i]-minprice;
            maxprofit=max(profit,maxprofit);
        }
    
    }
    return maxprofit;
}
int maxArea(vector<int>& height) {
    int maxwater=0;
    int i=0;
    int j=height.size()-1;
    while(i<j){
        int hei=min(height[i],height[j]);
        int wid=j-i;
        int curwater=hei*wid;
        maxwater=max(maxwater,curwater);    
        if(height[i]<height[j]){
            i++;
        }
        else{
            j--;
        }
    }

    return maxwater;
}
vector<int> productExceptSelf(vector<int>& nums) {
    if(nums.empty()||nums.size()==1) return {};
    vector<int>ans(nums.size(),1);
    for(int i=1;i<nums.size();i++){
        ans[i]=nums[i-1]*ans[i-1];
    }
    int suffix=1;
    for(int i=nums.size()-1;i>=0;i--){
        ans[i]*=suffix;
        suffix*=nums[i];
    }
    return ans;
}
int search(vector<int>& nums, int target) {
    if(nums.empty()) return -1;
    int st=0;int end=nums.size()-1;
    while(st<=end){
        int mid=st+((end-st)/2);
        if(nums[mid]==target){
            return mid;
        }
        if(nums[mid]>=nums[st]){
        if(target>=nums[st]&&nums[mid]>target){
            end=mid-1;
        }else{
            st=mid+1;
        }
        }
        else{
        if(target<=nums[end]&&target>nums[mid]){
            st=mid+1;
        }
        else{
            end=mid-1;
        }
        }
    }
    return -1;
}

int main(){
   vector<int>arr={1,2,2,1,1,2,2};
   cout<<majorityele1(arr)<<endl;
    return 0;
}