#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll> v;
ll N,S,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>S;
    v.resize(N);
    for(int i=0;i<N;i++) {
        cin>>v[i];
    }
    sort(v.begin(),v.end());
    int k = (N+1)/2;
    ll low,high;
    low = high = 0;
    for(int i=0;i<N;i++) {
        if(i < N-k) {
            low+=v[i];
        }
        else {
            high+=v[i];
        }
    }
    ll base = N%2? -S: S;
    ans = base+2LL*(high-low);
    cout<<ans<<"\n";
    return 0;
}