#include<bits/stdc++.h>
#define SIZE 1001
using namespace std;
int arr[SIZE] = {0};
int dp[2][SIZE] = {0};
int N, ans;
int main() {
    ios_base::sync_with_stdio(false);
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> arr[i];
	for (int i = 1; i <= N; i++) {
		dp[0][i] = 1;
		dp[1][N - i + 1] = 1;
		for (int j = 1; j < i; j++) {
			if (arr[i] > arr[j] && dp[0][j] + 1 > dp[0][i]) {
				dp[0][i] = dp[0][j] + 1;
			}
			if (arr[N - i + 1] > arr[N - j + 1] && dp[1][N - j + 1] + 1 > dp[1][N - i + 1]) {
				dp[1][N - i + 1] = dp[1][N - j + 1] + 1;
			}
		}
	}
	ans = 0;
	for (int i = 1; i <= N; i++) {
		ans = max(ans, dp[0][i] + dp[1][i] - 1);
	}
	cout << ans << "\n";
	return 0;
}