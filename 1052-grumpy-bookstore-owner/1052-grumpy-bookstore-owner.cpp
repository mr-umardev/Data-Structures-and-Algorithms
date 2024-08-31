class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n = customers.size();
    int satisfiedCustomers = 0;

    // Calculate the number of initially satisfied customers
    for (int i = 0; i < n; ++i) {
        if (grumpy[i] == 0) {
            satisfiedCustomers += customers[i];
        }
    }

    // Use a sliding window to find the maximum number of additional customers
    // that can be satisfied by choosing the best `minutes`-long window
    int maxAdditionalCustomers = 0;
    int currentAdditionalCustomers = 0;

    // Calculate the initial window
    for (int i = 0; i < minutes; ++i) {
        if (grumpy[i] == 1) {
            currentAdditionalCustomers += customers[i];
        }
    }
    maxAdditionalCustomers = currentAdditionalCustomers;

    // Slide the window across the rest of the array
    for (int i = minutes; i < n; ++i) {
        if (grumpy[i] == 1) {
            currentAdditionalCustomers += customers[i];
        }
        if (grumpy[i - minutes] == 1) {
            currentAdditionalCustomers -= customers[i - minutes];
        }
        maxAdditionalCustomers = max(maxAdditionalCustomers, currentAdditionalCustomers);
    }

    return satisfiedCustomers + maxAdditionalCustomers;
        
    }
};