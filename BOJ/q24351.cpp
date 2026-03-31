#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string str;
ll dp[60];
ll N,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>str;
    int len = str.size();
    dp[len] = 1;
    for(int i=len-1;i>=0;i--) {
        dp[i] = dp[i+1];
        if(i+1 < len) {
            int tmp = (str[i]-'0')*10+(str[i+1]-'0');
            if(10 <= tmp && tmp <= 9+N) {
                dp[i]+=dp[i+2];
            }
        }
    }
    ans = dp[0];
    cout<<ans<<"\n";
    return 0;
}