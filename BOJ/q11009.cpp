#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX = 61;
ll dp[MAX][MAX];
int T,N,M;
void init() {
    for(int i=0;i<MAX;i++) {
        dp[i][0] = 1;
        for(int j=1;j<=i;j++) {
            dp[i][j] = dp[i-1][j-1]+dp[i-1][j];
        }
    }
}
ll gcd(ll a, ll b) {
    return b == 0? a:gcd(b,a%b);
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    init();
    cin>>T;
    while(T--) {
        cin>>N>>M;
        ll a,b;
        a = 0;
        b = dp[N+M][N];
        for(int i=N+M-1;i>=0;i-=2) {
            a+=dp[i][N-1];
        }
        ll d = gcd(a,b);
        cout<<a/d<<"/"<<b/d<<"\n";
    }
    return 0;
}