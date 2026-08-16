#include<iostream>
#include<vector>
#include<algorithm>
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
int peakIndexInMountainArray(vector<int>& arr) {
    if(arr.empty()||arr.size()<3) return -1;
    int st=1;
    int end=arr.size()-2;
    while(st<=end){
        int mid = st+((end-st)/2);
        if(arr[mid-1]<arr[mid]&&arr[mid]>arr[mid+1]){
            return mid;
        }
        if(arr[mid-1]<arr[mid]){
            st=mid+1;
        }
        else{
            end=mid-1;
        }
    } 
    return -1;
}
int singleNonDuplicate(vector<int>& nums) {
    if(nums.empty()||nums.size()%2==0) return -1;
    if(nums.size()==1) return nums[0];
    int st=0;
    int end=nums.size()-1;
    while(st<=end){
        int mid=st+((end-st)/2);
        if((mid == 0 && nums[mid] != nums[mid+1]) ||
        (mid == nums.size()-1 && nums[mid] != nums[mid-1]) ||
        (mid > 0 && mid < nums.size()-1 &&
            nums[mid] != nums[mid-1] && nums[mid] != nums[mid+1])){
            return nums[mid];
        }
        if(mid%2==0){
            if(nums[mid]==nums[mid-1]){
                end=mid-1;
            }
            else{
                st=mid+1;
            }
        }else{
            if(nums[mid]==nums[mid+1]){
                end=mid-1;
            }
            else{
                st=mid+1;
            }
        }
    }
    return -1;
    
}
bool isvalidmid(const vector<int>& arr,int n,int k,int mid){
    int student=1;int pages=0;
    for(int i=0;i<n;i++){
        if(arr[i]>mid) return false;
        if(pages+arr[i]<=mid){
            pages+=arr[i];
        }else{
            student++;
            pages=arr[i];
        }
    }
    if(student<=k)return true;
    else return false;
}
int findPages(vector<int> &arr, int k) {
    // code here
    int n=arr.size();
    if(k>n) return -1;
    if(arr.empty()) return -1;
    int stvalue=0;int sum=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
        stvalue=max(stvalue,arr[i]);
    }
    int st=stvalue;int end=sum;
    while(st<=end){
        int mid=st+((end-st)/2);
        if(isvalidmid(arr,n,k,mid)){
            end=mid-1;
        }
        else{
            st=mid+1;
        }
    }
    return st;
}
bool isvalid(const vector<int>& arr,int n,int k,int mid){
    int painter=1;int boards=0;
    for(int i=0;i<n;i++){
        if(mid<arr[i]) return false;
        if(boards+arr[i]<=mid){
            boards+=arr[i];
        }
        else{
            painter++;
            boards=arr[i];
        }
    }
    if(painter<=k) return true;
    else return false;
}
int minTime(vector<int>& arr, int k) {
    // code here
    int n=arr.size();
    if(k>n) return -1;
    int stp=1;int sum=0;
    for(int i=0;i<n;i++){
        stp=max(stp,arr[i]);
        sum+=arr[i];
    }
    int st=stp;
    int end=sum;
    while(st<=end){
        int mid=st+((end-st)/2);
        if(isvalid(arr,n,k,mid)){
            end=mid-1;
        }
        else{
            st=mid+1;
        }
    }
    return st;
}
bool isvalid1(const int arr[],int n,int k,int mid){
    int cow=1;int stall=arr[0];
    for(int i=1;i<n;i++){
        if(arr[i]-stall>=mid){
            stall=arr[i];
            cow++;
        }
    }
    if(cow>=k) return true;
    else return false;
}
int aggressiveCows(int *arr, int n, int k) {
    // code here
    sort(arr, arr + n);
    int st = 1;
    int end = arr[n-1] - arr[0];
    while(st<=end){
        int mid=st+((end-st)/2);
        
        if(isvalid1(arr,n,k,mid)){
            st=mid+1;
        }
        else{
            end=mid-1;
        }
    }
    return end;
}
void sortColors(vector<int>& arr){
    int low=0;
    int mid=0;
    int high=arr.size()-1;
    while(mid<=high){
        if(arr[mid]==0){
            swap(arr[low],arr[mid]);
            low++;
            mid++;
        }else if(arr[mid]==1){
            mid++;
        }else{
            swap(arr[mid],arr[high]);
            high--;
        }
    }
    for(int val:arr){
        cout<<val<<" ";
    }
    return ;
}
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n){
    int end=(m+n)-1;
    int i=m-1;
    int j=n-1;
    while(i>=0&&j>=0){
        if(nums1[i]<=nums2[j]){
            nums1[end]=nums2[j];
            end--;j--;
        }
        else{
            nums1[end]=nums1[i];
            end--;i--;
        }
    }
    while(j>=0){
        nums1[end]=nums2[j];
        end--;j--;
    }

    return;
}
void nextPermutation(vector<int>& nums) {
    int n=nums.size();
    int pivot=-1;
    for(int i=n-2;i>=0;i--){
    if(nums[i]<nums[i+1]){
        pivot=i;
        break;
    }
    }  
    if(pivot==-1){
    reverse(nums.begin(),nums.end());
    return;
    }
    for(int i=n-1;i>pivot;i--){
    if(nums[pivot]<nums[i]){
        swap(nums[pivot],nums[i]);
        break;
    }

    
    }  
    reverse(nums.begin()+pivot+1,nums.end());
    return;
}
bool isPalindrome(string s) {
        if(s.empty()) return true;
int i=0,j=s.size()-1;
while(i<=j){
    if(!isalnum(s[i])){
        i++;
        continue;
    }
    if(!isalnum(s[j])){
            j--;
        continue;
    }

    if(tolower(s[i])!=tolower(s[j])) return false;
    i++;j--;
}

return true;
}
string removeOccurrences(string s, string part) {
while(true){
    size_t pos=s.find(part);
    if(pos==string::npos) return s;
        s.erase(pos,part.length());
    }
}
bool areArrayEqual(int a[],int b[]){
    for(int i=0;i<26;i++){
        if(a[i]!=b[i]){
            return false;
        }
    }
    return true;
}
bool checkInclusion(string s1, string s2) {
    int freq[26]={0};
    for(int i=0;i<s1.length();i++){
        freq[s1[i]-'a']++;
    }
    int i=0;
    while((i+s1.length()-1)<s2.length()){
        int s2freq[26]={0};
        for (int j=i;j<i+s1.length();j++){
            s2freq[s2[j]-'a']++;
        }
        if(areArrayEqual(freq,s2freq)){
            return true;
        }
        else {
            i++;
        }
    }
    return false;
}
bool checkInclusion(string s1, string s2) {
int freq[26] = {0};
int window[26] = {0};

for(char ch : s1) {
    freq[ch - 'a']++;
}

int k = s1.length();

for(int i = 0; i < s2.length(); i++) {
    window[s2[i] - 'a']++;

    if(i >= k) {
        window[s2[i - k] - 'a']--;
    }

    if(i >= k - 1 && areArrayEqual(freq, window)) {
        return true;
    }
}

return false;
}

int main(){
   vector<int>arr={5,10,30,20,15};
   cout<<minTime(arr,3);
    return 0;
}