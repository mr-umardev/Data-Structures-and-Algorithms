class Solution {
public:
    int maxArea(vector<int>& height) {
        //Consider an example [1,8,6,2,5,4,8,3,7]
        int n=height.size();//n=9
        int left=0;//Initially left=0 i.e 1
        int right=height.size()-1;//Initially right=8 i.e 7
        int max_value=0;
        while(left<right){
            max_value=max(max_value,(right-left)*min(height[left],height[right]));//First iteration,max(8-0)*min(1,7)->8*1=8
            if(height[left]<height[right]){
                left++;
            }
            else{
                right--;
            }
        }
        return max_value;
    }
};