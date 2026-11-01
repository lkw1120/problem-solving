#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX = 1e5+7;
vector<ll> v1,v2;
ll N,H,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>H;
    v1.resize(N);
    v2.resize(N);
    for(ll i=0;i<N;i++) {
        cin>>v1[i]>>v2[i];
    }
    sort(v1.rbegin(),v1.rend());
    sort(v2.rbegin(),v2.rend());
    ll sum = 0;
    ans = LONG_MAX;
    for(ll i=0;i<N;i++) {
        sum+=v2[i];
        if(sum < H) {
            ll tmp = (i+1)+(H-sum)/v1[0];
            if((H-sum)%v1[0]) tmp++;
            ans = min(ans,tmp);
        }
        else {
            ans = min(ans,i+1);	
        }
    }
    cout<<ans<<"\n";
    return 0;
}