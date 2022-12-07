#include<bits/stdc++.h>
using namespace std;
int board[101][101] = {0};
string dp[101][101] = {""};
int N;
string ans;
string bigSum(string a, string b) {
	int c = 0;
    int la = a.size() - 1;
    int lb = b.size() - 1;
    string ans = "";
    while ((la >= 0) || (lb >= 0) || (c > 0)) {
        int v = c;
        if (la >= 0) v += a[la --] - '0';
        if (lb >= 0) v += b[lb --] - '0';
        ans = ((char)(48 + v % 10)) + ans;
        c = v/10;
    }
    return ans;
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>N;
	for(int i=0;i<N;i++) {
		for(int j=0;j<N;j++) {
			cin>>board[i][j];
		}
	}
	fill(&dp[0][0],&dp[100][101],"0");
    dp[0][0] = "1";
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            if (dp[i][j] == "0" || (i == N-1 && j == N-1)) {
                continue;
            }
            int dist = board[i][j];
            int down = dist + i;
            int right = dist + j;
            if (down < N) {
                dp[down][j] = bigSum(dp[down][j],dp[i][j]);
            }
            if (right < N) {
                dp[i][right] = bigSum(dp[i][right],dp[i][j]);
            }
        }
    }
    ans = dp[N-1][N-1];
	cout<<ans<<"\n";
	return 0;	
}