#include<bits/stdc++.h>
using namespace std;
const int MOD = 1e9+7;
const int MAX = 1001;
int dp[MAX][MAX];
int N;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>N;
    int num;
    for(int i=1;i<=N;i++) {
        for(int j=1;j<=N;j++) {
            cin>>num;
        }
    }
    dp[1][1] = 1;
    int a,b;
    a = 1;
    b = N*N;
    for(int i=1;i<=N;i++) {
        for(int j=1;j<=N;j++) {
            if(i != 1 || j != 1) {
                dp[i][j] = (dp[i-1][j]+dp[i][j-1])%MOD;
            }
            a = (a+dp[i][j])%MOD;
        }
    }
    cout<<a<<" "<<b<<"\n";
    return 0;
}