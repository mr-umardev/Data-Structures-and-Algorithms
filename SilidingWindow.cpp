#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    int maxSum(vector<int>& w,int k){
        int n=w.size();
        int maxsum=0,windowsum=0;
        if(n<k){
            return -1;
        }
            for(int i=0;i<k;++i){
                windowsum+=w[i];
            }
            maxsum=windowsum;
            for(int i=k;i<n;++i){
                windowsum+=w[i]-w[i-k];
                maxsum=max(maxsum,windowsum);
            }
        return maxsum;
    }
};
int main(){
    int n=0,k=0;
    cout<<"Enter no of elements for vector:"<<endl;
    cin>>n;
    cout<<"Enter no of elements for k:"<<endl;
    cin>>k;
    vector<int>w(n);
    cout<<"Enter array elements:"<<endl;
    for(int i=0;i<n;++i){
        cout<<"Enter "<<n<<"vector elements"<<endl;
        cin>>w[i];
    }
    Solution sol;
    int result=sol.maxSum(w,k);
    cout<<result;
}
