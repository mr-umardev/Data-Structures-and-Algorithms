class Solution {
public:
    int findClosest(int x, int y, int z) {
        int diff1=0, diff2=0;
        if(x>z){
            diff1=x-z;
        }
        if(x<z){
        diff1=z-x;
        }
        if(y<z){
        diff2=z-y;
        }
        if(y>z){
            diff2=y-z;
        }
        if(x==0){
            return x;
        }else if(y==0){
            return y;
        }
        if(diff1==diff2){
            return 0;
        }
        return diff1<diff2 ? 1 : 2;
    }
};