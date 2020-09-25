#include <bits/stdc++.h>
using namespace std;

int knapsack(vector<int> w, vector<int> val, int W, int n) {
    //base condition (think of the smallest valid input and its probable output)
    if(n == 0 || W == 0) {
        return 0;
    }

    /*
    ///// choice diagram //////
            
            item weight (w1)
             /   \
            /     \
           /       \
       w1 <= W    w1 > W
        /  \          \
       /    \          \
      /      \          \
  select  no select   no select

    */

    //coding up the choice diagram
    //start from the last value of the array and check for the previous values recursively

    // selection case written ie if a value is chosen to be put in the knapsack
    if(w[n-1] <= W) {
        return max((val[n-1] + knapsack(w, val, W - w[n-1], n-1)) , knapsack(w, val, W, n-1));
    }

    // else coding for the not selected part (extreme right child of the above choice diagram
    else if (w[n-1] > W) {
        return knapsack(w, val, W, n-1);
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
