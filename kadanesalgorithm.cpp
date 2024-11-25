#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    int kadanealgorith(vector<int>& nums){
        int n=nums.size();
        int current_sum=0;
        int max_sum=INT_MIN;
        for(int i=0;i<n;++i){
            current_sum+=nums[i];
            if(current_sum<0){
            current_sum=0;
        }
        if(current_sum>max_sum){
            max_sum=current_sum;
        }
        }
        return max_sum;
    }
};
int main(){
    int n;
    cout<<"Enter no of elements:"<<endl;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;++i){
        cout<<"Enter "<<i<<"value of the vector:";
        cin>>arr[i];
    }
    Solution sol;
    int result=sol.kadanealgorith(arr);
    cout<<result;
}
