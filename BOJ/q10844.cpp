#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1000000000;
ll dp[101][11] = {0};
ll N,sum,ans;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	cin>>N;
	for(int i=1;i<=9;i++) {
		dp[1][i] = 1;
	}
	for(int i=2;i<=N;i++) {
		dp[i][0] = dp[i-1][1];
		for(int j=1;j<=9;j++) {
			dp[i][j] = (dp[i-1][j-1]+dp[i-1][j+1])%MOD;
		}
	}
    sum = 0;
	for(int i=0;i<10;i++) {
		sum+=dp[N][i];
	}
	ans = sum%MOD;
	cout<<ans<<"\n";
    return 0;
}