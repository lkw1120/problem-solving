#include<bits/stdc++.h>
using namespace std;
vector<int> a,b,c;
int dp[1001][1001];
int m,g,n,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>m>>g>>n;
    a.resize(n);
    b.resize(n);
    c.resize(n);
    for(int i=0;i<n;i++) {
        cin>>a[i]>>b[i]>>c[i];
    }
    for(int i=0;i<n;i++) {
        for(int x=a[i];x<=m;x++) {
            for (int y=b[i];y<=g;y++) {
                dp[x][y] = max(dp[x][y],dp[x-a[i]][y-b[i]]+c[i]);
            }
        }
    }
    ans = dp[m][g];
    cout<<ans<<"\n";
    return 0;
}