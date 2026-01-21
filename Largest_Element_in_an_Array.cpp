class Solution {
  public:
    int largest(vector<int> &arr) {
        // code here
        int maximum=-1;
        for(int i=0;i<arr.size();++i){
            if(arr[i]>maximum){
                maximum=max(maximum,arr[i]);
            }
        }
        return maximum;
    }
};
