#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;
ll N,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>N;
    ans = 1;
    while(N) {
        ans = (ans*N)%MOD;
        N--;
    }
    cout<<ans<<"\n";
    return 0;
}