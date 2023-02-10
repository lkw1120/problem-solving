#include<bits/stdc++.h>
using namespace std;
bool coin[101][101] = {false};
int dp[101][101] = {0};
int N,M,ans;
void flip(int n, int m) {
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            coin[i][j] = !coin[i][j];
        }
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>N>>M;
    for(int i=1;i<=N;i++) {
        string str;
        cin>>str;
        for(int j=1;j<=M;j++) {
            coin[i][j] = str[j-1] == '1';
        }
    }
    for(int i=N;i>0;i--) {
        for(int j=M;j>0;j--) {
            if(coin[i][j]) {
                flip(i,j);
                dp[i][j]++;
            }
        }
    }
    ans = 0;
    for(int i=1;i<=N;i++) {
        for(int j=1;j<=M;j++) {
            ans+=dp[i][j];
        }
    }
    cout<<ans<<"\n";
    return 0;
}