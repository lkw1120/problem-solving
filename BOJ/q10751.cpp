#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX = 1e5+1;
ll dp[3][MAX];
string str;
ll N,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>N>>str;
    if(str[0] == 'C') {
        dp[0][0] = 1;
    }
    for(int i=1;i<N;i++) {
        dp[0][i]+=dp[0][i-1];
        dp[1][i]+=dp[1][i-1];
        dp[2][i]+=dp[2][i-1];
        if(str[i] == 'C') {
            dp[0][i]++;
        }
        if(str[i] == 'O') {
            dp[1][i]+=dp[0][i-1];
        }
        if(str[i] == 'W') {
            dp[2][i]+=dp[1][i-1];
        }
    }
    ans = dp[2][N-1];
    cout<<ans<<"\n";
    return 0;
}