class Solution {
public:
    int countSeniors(vector<string>& details) {
        int count = 0;
            
                for (const auto& detail : details) {
                        // Extract the age substring (12th and 13th characters)
                                string ageStr = detail.substr(11, 2);
                                        
                                                // Convert age substring to integer
                                                        int age = stoi(ageStr);
                                                                
                                                                        // Check if age is greater than 60
                                                                                if (age > 60) {
                                                                                            count++;
                                                                                                    }
                                                                                                        }
                                                                                                            
                                                                                                                return count;
    }
};