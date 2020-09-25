#include <bits/stdc++.h>
using namespace std;

/*
refer to the recursive approach to learn how to create the recursive function.

-In this case, we are just going to find out which are the values which are changing.
-Accordingly, we would be creating a matrix of the same size.
-For this problem (knapsack), we can see that the value of W and n are only changing. 
-Therefore, for these 2 values we would be creating a global matrix of size dp[n+1][W+1] (also can look at the n and W constraints and declare their sizes)
-After that we just need to 
    i. Memoize the results
   ii. Query for any given value before entering recursion

DISADVANTAGE OF MEMOIZATION:    Stack size can keep on increaseing (but very minimal problem (seldom occurs))
*/


// creating the global matrix
// say in our case we had the following constraints:    0 < n < 100; 0 < W < 100 (ie, no of items and max knapsack capacity can be 100)

int dp[101][101];

int knapsack(vector<int> w, vector<int> val, int W, int n) {
    //memsetting all the values to -1
    memset(dp, -1, sizeof(dp));

    //base condition (think of the smallest valid input and its probable output)
    if(n == 0 || W == 0) {
        return 0;
    }
    // before entering recursion loop check if the value is memoized
    if(dp[n][W] != -1) {
        return dp[n][W];
    }

    // condition for when an item is selected
    if(w[n-1] <= W) {
        // memoize at each step before returning the function call
        return dp[n][W] = max((val[n-1] + knapsack(w, val, W - w[n-1], n-1)) , knapsack(w, val, W, n-1));
    }

    // condition for when an item is not being selected
    else if (w[n-1] > W) {
        // memoize at each step before returning the function call
        return dp[n][W] = knapsack(w, val, W, n-1);
    }
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
