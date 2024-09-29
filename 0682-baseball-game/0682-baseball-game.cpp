class Solution {
public:
    int calPoints(vector<string>& operations) {
        /*stack<int>s;
        int sum=0,mul=0,value=0;
        for(const auto& element: operations){
        if(element == "C"){if (!s.empty()){s.pop();}}
        else if(element=="D"){if (!s.empty()){int value = s.top();s.push(value * 2);}
        else {if(element=="+"){ if (s.size() >= 2) {int lastScore = s.top();
                    s.pop();int secondLastScore = s.top();
                    s.push(lastScore);s.push(lastScore + secondLastScore);}}
             else{s.push(stoi(element));}}}
         return sum;
    }*/
        stack<int> s;int sum = 0;
        for (const auto& element : operations) {if (element == "C") {if (!s.empty()) {
                    s.pop();}}else if (element == "D") {if (!s.empty()) {
            int value = s.top();s.push(value * 2);}}else if (element == "+") {if (s.size() >= 2) {
                    int lastScore = s.top();
                    s.pop();
                    int secondLastScore = s.top();
                    s.push(lastScore);
                    s.push(lastScore + secondLastScore);
                }
            }
            else {
                s.push(stoi(element));
            }
        }
        while (!s.empty()) {
            sum += s.top(); 
            s.pop(); 
        }

        return sum;
    }
};