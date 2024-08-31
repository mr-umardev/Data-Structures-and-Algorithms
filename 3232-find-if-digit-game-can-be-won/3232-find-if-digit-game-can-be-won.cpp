class Solution {
public:
    bool canAliceWin(vector<int>& nums) {
        //First logic didn't work
       /* unordered_set<char>arraynums;
        for(int num:nums){
            string numStr=to_string(num);
            for(char digit:numStr){
                if(arraynums.find(digit)!=arraynums.end()){
                    return true;
                }
                arraynums.insert(digit);
            }
        }
        return false;
    }*/
   int singleDigitSum = 0, doubleSum = 0, total = 0;

    for (int num : nums) {
        total += num;
        if (num < 10) {
            singleDigitSum += num;
        } else if (num < 100) {
            doubleSum += num;
        }
    }

    int bobSingleDigitSum = total - singleDigitSum;
    int bobDoubleDigitSum = total - doubleSum;

    return (singleDigitSum > bobSingleDigitSum) || (doubleSum > bobDoubleDigitSum);
}
};