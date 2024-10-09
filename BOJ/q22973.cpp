#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll K,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>K;
    K = abs(K);
    if(!K) {
        ans = 0;
    }
    else {
        if(K%2) {
            ll p = 0;
            ll jump = 1;
            ans = 0;
            while(p < K) {
                p+=jump;
                jump*=2;
                ans++;
            }
        }
        else {
            ans = -1;
        }
    }
    cout<<ans<<"\n";
    return 0;
}