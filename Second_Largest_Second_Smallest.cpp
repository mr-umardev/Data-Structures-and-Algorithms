#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    int secondLargest(vector<int>& arr,int n){
        int maxele=arr[0],secondmax=INT_MIN;
        for(int i=1;i<n;++i){
            if(arr[i]>maxele){
                maxele=arr[i];
            }
        }
        for(int j=0;j<n;++j){
            if(arr[j]>secondmax && arr[j]!=maxele){
                secondmax=arr[j];
            }
        }
        return secondmax;
    }
    int secondSmallest(vector<int>& arr, int n){
        int minele=arr[0],secondmin=INT_MAX;
        for(int i=1;i<n;++i){
            if(arr[i]<minele){
                minele=arr[i];
            }
        }
        for(int j=0;j<n;++j){
            if(arr[j]<secondmin && arr[j]!=minele){
                secondmin=arr[j];
            }
        }
        return secondmin;
    }
};
int main(){
    vector<int>arr={1, 2, 4, 7, 7, 5};
    int n=arr.size();
    Solution sol;
    int res1=sol.secondLargest(arr,n);
    int res2=sol.secondSmallest(arr,n);
    cout<<res1<<" "<<res2;
}
