#include <bits/stdc++.h>

using namespace std;

int coinChangeRecursive(vector<int> &coins, int s, int n) {
	if(s == 0) return 1;
	if(n == 0) return 0;

	return (s < coins[n-1]) ? coinChangeRecursive(coins, s, n-1) :
	coinChangeRecursive(coins, s, n-1) + coinChangeRecursive(coins, s-coins[n-1], n); 
}

int coinChangeMemoized(vector<vector<int>> &dp, vector<int> &coins, int s, int n) {
	if(s == 0) return 1;
	if(n == 0) return 0;

	if(dp[n][s] != -1) return dp[n][s];

	dp[n][s] = (s < coins[n-1]) ? coinChangeMemoized(dp, coins, s, n-1) :
	coinChangeMemoized(dp, coins, s, n-1) + coinChangeMemoized(dp, coins, s-coins[n-1], n);

	return dp[n][s];
}

int coinChangeDp(vector<vector<int>> &dp, vector<int> &coins, int s, int n) {
	for(int i=0; i<=n; i++) dp[i][0]  = 1;

	for(int i=1; i<=n; i++)
		for(int j=1; j<=s; j++)
			dp[i][j] = (j < coins[i-1]) ? dp[i-1][j] : dp[i-1][j] + dp[i][j-coins[i-1]];

	return dp[n][s];
}

int main(){
	int n, s;
	cin >> n;
	vector<int> coins(n);
	for(int i=0; i<n; i++) cin >> coins[i];
	cin >> s;

	// Apply Recursive method
	cout << coinChangeRecursive(coins, s, n) << endl;

	// Apply Memoized method
	vector<vector<int>> dp(n+1, vector<int>(s+1, -1));
	cout << coinChangeMemoized(dp, coins, s, n) << endl;

	// Apply Dp method
	vector<vector<int>> dp1(n+1, vector<int>(s+1));
	cout << coinChangeDp(dp1, coins, s, n) << endl;

	return 0;
}