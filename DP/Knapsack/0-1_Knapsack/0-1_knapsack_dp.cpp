#include <bits/stdc++.h>
using namespace std;

//considering constraints: 0 < n < 100 and 0 < W < 100

int dp[100][100];

int knapsack(vector<int> w, vector<int> val, int W, int n) {
    //base condition of the recursive function will be converted into the initialization part of the top-down approach
    for(int i = 0; i < n+1; i++) {
    	for(int j = 0; j < W+1; j++) {
    		if(i == 0 || j == 0)
	    		dp[i][j] = 0;
    	}
    }
    	
    // while filling up the dp array, just take a look at the recusive function, everything will remain same, 
    // except n will be i, and W will be j
    // where ever there is the recursion call knapsack() -> it will change to dp[some_val][some_val]
    for(int i = 1; i < n+1; i++) {
    	for(int j = 1; j < W+1; j++) {
    		// condition for element being selected into the knapsack
    		if(w[i-1] <= j) {
    			// looking at every step and filling from previous subproblems
    			dp[i][j] = max((val[i-1] + dp[i-1][j - w[i-1]]),  dp[i-1][j]);
    		} 
    		
    		//condition where element is not selected into the knapsack
    		else if (w[i-1] > j) {
    			dp[i][j] = dp[i-1][j];
    		}
    	}
    }
    return dp[n][W];
}


int main() {
    int n, W;
    printf("Enter the number of items: ");
    scanf("%d", &n);
    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &W);
    vector<int> w(n), val(n);
    printf("Enter the weights of the items: \n");
    for(int i = 0; i < n; ++i) {
        printf("Enter weight of item %d: ", i+1);
        scanf("%d", &w[i]);
    }
    printf("Enter the price of the items: \n");
    for(int i = 0; i < n; ++i) {
        printf("Enter the price of item %d: ", i+1);
        scanf("%d", &val[i]);
    }
    
    // design the recursive function to find the maximum profit that can be generated from the above items:
    int max_profit = knapsack(w, val, W, n);
    printf("\n The maximum profit: $ %d\n", max_profit);
    return 0;
}
