#include <bits/stdc++.h>
using namespace std;

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
	for(int i = 0; i < n; ++i) {
		scanf("%d", &nums[i]);
	}
	printf("Enter the sum: ");
	scanf("%d", &S);
	cout << "Possible or not?" << endl;
	if(subset_sum(nums, S, n) == true)	printf("Yes\n");
	else					printf("No\n");
}
