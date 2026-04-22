#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<pair<ll,ll>> v;
vector<ll> ep;
ll N,T,K;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    for(int i=0;i<N;i++) {
        ll a,b;
        cin>>a>>b;
        v.push_back({a,b});
        ep.push_back(a);
        ep.push_back(b);
    }
    sort(ep.begin(),ep.end());
    T = ep[(2LL*N-1)/2];
    K = 0;
    for(auto [a,b]: v) {
        if(T < a) {
            K+=(a-T);
        }
        else if(b < T) {
            K+=(T-b);
        }
    }
    cout<<T<<" "<<K<<"\n";
    return 0;
}