#include<bits/stdc++.h>
using namespace std;
const int INF = 987654321;
int arr[16][16] = {0};
int dp[16][1<<16] = {0};
int N,ans;
int dfs(int cur, int visit){
    if(visit == (1<<N)-1) {
        if(arr[cur][0] == 0) {
            return INF;
		}
        return arr[cur][0];
    }
    if(dp[cur][visit] != -1) {
        return dp[cur][visit];
	}
    dp[cur][visit] = INF;
    for(int i=0;i<N;i++) {
        if(arr[cur][i]==0) {
            continue;
		}
        if((visit & (1<<i)) == (1<<i)) {
            continue;
		}
        dp[cur][visit] = min(dp[cur][visit], arr[cur][i] + dfs(i, visit | 1<<i));
    }
    
    return dp[cur][visit];
}

int main() {
    ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    cin>>N;
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            cin>>arr[i][j];
        }
    }
    memset(dp,-1,sizeof(dp));
	ans = dfs(0,1);
    cout<<ans<<"\n";
    return 0;
}