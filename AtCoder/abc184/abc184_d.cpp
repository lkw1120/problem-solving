#include<bits/stdc++.h>
using namespace std;
double dp[101][101][101];
int A,B,C;
double ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>A>>B>>C;
    for(int a=99;a>=A;a--) {
        for(int b=99;b>=B;b--) {
            for(int c=99;c>=C;c--) {
                int sum = a+b+c;
                dp[a][b][c] = 1.0;
                dp[a][b][c]+=(double)a/sum*dp[a+1][b][c];
                dp[a][b][c]+=(double)b/sum*dp[a][b+1][c];
                dp[a][b][c]+=(double)c/sum*dp[a][b][c+1];
            }
        }
    }
    ans = dp[A][B][C];
    cout<<fixed<<setprecision(10)<<ans<<"\n";
    return 0;
}