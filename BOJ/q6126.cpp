#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
vector<ll> v;
ll dp[10001] = {0};
ll V,N,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>V>>N;
    v.resize(V);
    for(int i=0;i<V;i++) {
        cin>>v[i];
    }
    dp[0] = 1;
    for(int i=0;i<V;i++) {
        for(int j=N;j>=0;j--) {
            if(dp[j]) {
                for(int k=1;;k++) {
                    if(N < j+v[i]*k) break;
                    dp[j+v[i]*k]+=dp[j];
                }
            }
        }
    }
    ans = dp[N];
    cout<<ans<<"\n";
    return 0;
}