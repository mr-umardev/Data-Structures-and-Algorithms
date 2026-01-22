#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    void leftRotate(vector<int>& arr,int n){
        int temp=arr[0];
        for(int i=1;i<n;++i){
            arr[i-1]=arr[i];
        }
        arr[n-1]=temp;
    }
};
int main(){
    vector<int>arr={1,2,3,4,5,6,7};
    int n=arr.size();
    Solution sol;
    sol.leftRotate(arr,n);
    //cout<<res1;
    for(int num: arr){
        cout<<num<<" ";
    }
}
