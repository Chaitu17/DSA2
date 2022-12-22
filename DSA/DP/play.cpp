#include<bits/stdc++.h>
using namespace std;

int minPathSum(vector<vector<int>> &mat, vector<vector<int>> &dp, int i, int j) {
	int m = mat.size();
	int n = mat[0].size();
	if(i >= m || j >= n) return INT_MAX; // if you are going outside the maze, INT_MAX forces you to change the direction
	if(i == m-1 && j == n-1) return mat[m-1][n-1];
	if(dp[i][j] != -1) return dp[i][j];
	dp[i][j] = mat[i][j] + min(minPathSum(mat, dp, i, j+1), minPathSum(mat, dp, i+1, j));
	return dp[i][j];
}

int main() {
	int m,n;
	cin >> m >> n;
	vector<vector<int>> mat(m, vector<int> (n, 0));
	for(int i=0; i<m; ++i) {
		for(int j=0; j<n; ++j) {
			cin >> mat[i][j];
		}
	}
	vector<vector<int>> dp(m, vector<int> (n, -1));
	cout << minPathSum(mat, dp, 0, 0) << "\n";
	for(int i=0; i<m; ++i) {
		for(int j=0; j<n; ++j) {
			cout << dp[i][j] << " ";
		}
		cout << "\n";
	}
	return 0; 
}