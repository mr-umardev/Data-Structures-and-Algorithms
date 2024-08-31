class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
    int n = customers.size();
    long long totalWaitingTime = 0;
    int currentTime = 0;
    
    for (const auto& customer : customers) {
        int arrivalTime = customer[0];
        int prepTime = customer[1];
        
        // If the chef is free before the customer arrives, wait for the customer
        if (currentTime < arrivalTime) {
            currentTime = arrivalTime;
        }
        
        // The chef finishes preparing the food at currentTime + prepTime
        currentTime += prepTime;
        
        // Calculate the waiting time for this customer
        totalWaitingTime += currentTime - arrivalTime;
    }
    
    return (double) totalWaitingTime / n;
}
};