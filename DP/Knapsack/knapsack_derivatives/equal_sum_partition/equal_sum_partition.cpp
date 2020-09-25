#include <bits/stdc++.h>
using namespace std;

/*

Given an array, we need to find out whether it is possible to partition the array in such way, that the sum of each partition is equal
    
Here, basically, we need to check if the sum of the total array is an even number. Iff sum is even, then their paritition is possible.
EG: [1, 5, 5, 11]
sum = 22. Therefore there will be two subsets of equal sum = 11 ie (22/2). 
In case sum is odd, then it is not possible to divide the whole array into two equal subsets.

So, in this approach, we will be passing the array;
checking if the sum of the total array is even. 
then only pass find 1 subset with the sum total_sum / 2. (obviously, the other subset would have an equal sum of total - 1st subset sum OR total_sum/s). 
So, basically, the problem is reduced to the subset sum problem after all!
*/

// considering max constraints of 0 < n < 100 and 0 < S < 100

//dp array declaration
bool dp[100][100];

bool subset_sum(vector<int> nums, int S, int n) {
	
    //initialization of the first places
    for(int i = 0; i < n+1; i++) {
	for(int j = 0; j < S+1; j++) {
	    if(i == 0 && j == 0)
		dp[i][j] = true;
	    else if(i == 0)	
		dp[i][j] = false;
	    else if(j == 0) 
		dp[i][j] = true;
	    }
    }
	
    //rest of the things are same as the knapsack problem only make the following changes:
    // 1. When only a single array will be given as input, ignore the value array, only weight array will be considered
    // 2. Sum value (S here) = W in knapsack
    for(int i = 1; i < n+1; i++) {
	for(int j = 1; j < S+1; j++) {
	    //considering the value to be put into knapsack / put into out subset
	    if(nums[i-1] <= j) {
	        // for true/false, there is no sense of max(), use OR (||) here.
	        dp[i][j] = dp[i-1][j - nums[i-1]] || dp[i-1][j]; 
	    }
			
	    // if nums[i] > S, that value can be ignored
	    else if(nums[i-1] > j) {
		dp[i][j] = dp[i-1][j];
	    }
	}
    }	
    return dp[n][S];
}

int main() {
    int n, S;
    printf("Enter the number of elements in the set: ");
    scanf("%d", &n);
    vector<int> nums(n);
    int sum = 0;
    for(int i = 0; i < n; ++i) {
    	int x;
        scanf("%d", &x);
        nums[i] = x;
        sum += x;
    }
    if(sum % 2 == 0) {
       bool possible = subset_sum(nums, sum/2, n);
       if(possible == true)     printf("Yes\n");
       else			printf("No\n");
    } else {
        printf("No\n");
    }
       
}
