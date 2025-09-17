#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
priority_queue<ll,vector<ll>,greater<ll>> pq;
vector<pair<ll,ll>> v;
ll N,K,M,ans;
bool compare(pair<ll,ll> a, pair<ll,ll> b) {
    if(a.first != b.first) {
        return a.first < b.first;
    }
    else {
        return a.second > b.second;
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>M>>K;
    for(int i=0;i<K;i++) {
        int a,b;
        cin>>b>>a;
        v.push_back({a,b});
    }
    sort(v.begin(),v.end(),compare);
    ll sum = 0;
    ans = -1;
    for(auto [a,b]: v) {
        pq.push(b);
        sum+=b;
        if(N < pq.size()) {
            sum-=pq.top();
            pq.pop();
        }
        if(pq.size() == N && M <= sum) {
            ans = a;
            break;
        }
    }
    cout<<ans<<"\n";
    return 0;
}