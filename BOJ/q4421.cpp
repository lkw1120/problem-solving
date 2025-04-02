#include<bits/stdc++.h>
using namespace std;
int arr[101][101];
int dp[101][101];
int N,K,ans;
int find(int x, int y) {
    if(dp[x][y] != -1) {
        return dp[x][y];
    }
    int cnt = arr[x][y];
    for(int i=1;i<=K;i++) {
        if(x+i < N && arr[x+i][y] > arr[x][y]) {
            cnt = max(cnt, arr[x][y]+find(x+i,y));
        }
        if(x-i >= 0 && arr[x-i][y] > arr[x][y]) {
            cnt = max(cnt, arr[x][y]+find(x-i,y));
        }
        if(y+i < N && arr[x][y+i] > arr[x][y]) {
            cnt = max(cnt, arr[x][y]+find(x,y+i));
        }
        if(y-i >= 0 && arr[x][y-i] > arr[x][y]) {
            cnt = max(cnt, arr[x][y]+find(x,y-i));
        }
    }
    dp[x][y] = cnt;
    return cnt;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>N>>K;
    fill(&dp[0][0],&dp[100][101],-1);
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            cin>>arr[i][j];
        }
    }
    ans = find(0,0);
    cout<<ans<<"\n";
    return 0;
}