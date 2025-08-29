#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX_N = 1e6+1;
const ll NEG = LLONG_MIN/4;
ll arr[MAX_N];
ll N,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    for(int i=0;i<N;i++) {
        cin>>arr[i];
    }
    ll high = NEG;
    ll low = NEG;
    ans = NEG;
    for(ll i=0;i<N;i++) {
        high = max(high,arr[i]+i);
        low = max(low,arr[i]-i);
        ll a = (arr[i]+i)+low;
        ll b = (arr[i]-i)+high;
        ans = max(ans,max(a,b));
    }
    cout<<ans<<"\n";
    return 0;
}