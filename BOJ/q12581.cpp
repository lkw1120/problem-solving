#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 100003;
int arr[26][26];
int res[26];
ll dp[26][26];
int T,N;
void init() {
    for(int i=0;i<=25;i++) {
        arr[i][0] = arr[i][i] = 1;
        for(int j=1;j<i;j++) {
            arr[i][j] = (arr[i-1][j-1]+arr[i-1][j])%MOD;
        }
    }
    dp[1][1] = 1;
    for(int i=2;i<26;i++) {
        dp[i][1] = 1;
        for(int j=2;j<i;j++) {
            ll sum = 0;
            for(int k=1;k<j;k++) {
            int tmp = arr[(i-1)-j][(j-1)-k];
            sum = (sum+1LL*dp[j][k]*tmp)%MOD;
            }
            dp[i][j] = sum;
        }
        for(int j=1;j<i;j++) {
            res[i] = (res[i]+dp[i][j])%MOD;
        }
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    init();
    cin>>T;
    for(int t=1;t<=T;t++) {
        cin>>N;
        cout<<"Case #"<<t<<": "<<res[N]<<"\n";
    }
    return 0;
}