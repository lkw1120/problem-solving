#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e9+7;
int Z,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>Z;
    while(Z--) {
        string str;
        cin>>str;
        int size = str.size();
        vector<int> v,dp;
        v.resize(size+1);
        dp.resize(size+1);
        dp[0] = 1;
        v[0] = 1;
        for(int i=1;i<=size;i++) {
            ll tmp = 0;
            if(3 <= i && str[i-3] == 'k' && str[i-2] == 'o' && str[i-1] == 't') {
                if(i-4 >= 0) {
                    tmp = v[i-4];
                }
            }
            dp[i] = tmp%MOD;
            v[i] = (v[i-1]+dp[i])%MOD;
        }
        ans = v[size-1];
        cout<<ans<<"\n";
    }
    return 0;
}