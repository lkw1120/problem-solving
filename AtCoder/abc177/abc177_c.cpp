#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e9+7;
ll N,A,sum,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    ans = sum = 0;
    for(int i=0;i<N;i++) {
        cin>>A;
        A%=MOD;
        ans = (ans+A*sum)%MOD;
        sum = (sum+A)%MOD;
    }
    cout<<ans<<"\n";
    return 0;
}