#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll N,even,odd,ans;
bool feasible(int l) {
    ll e = (l+1)/2;
    ll o = l/2;
    ll x = min(even,e);
    ll tmp = o+2LL*(e-x);
    if(odd < tmp) {
        return false;
    }
    return (odd-tmp)%2 == 0;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    even = odd = 0;
    for (int i = 0; i < N; ++i) {
        int a;
        cin>>a;
        if(a%2 == 0) {
            even++;
        }
        else {
            odd++;
        }
    }
    ans = 0;
    for(int i=N;i>=1;i--) {
        if(feasible(i)) { 
            ans = i;
            break;
        }
    }
    cout<<ans<<"\n";
    return 0;
}