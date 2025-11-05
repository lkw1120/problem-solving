#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX_N = 1e6+1;
vector<ll> node[MAX_N];
vector<ll> root;
ll N,E,C,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>E;
    for(int i=0;i<E;i++) {
        ll x;
        cin>>x;
        root.push_back(x);
    }
    for(int i=1;i<=N;i++) {
        cin>>C;
        for(int j=0;j<C;j++) {
            ll x;
            cin>>x;
            node[i].push_back(x);
        }
    }
    ans = 0;
    for(int i=0;i<E;i++) {
        queue<pair<ll,ll>> q;
        q.push({root[i],0});
        while(!q.empty()) {
            ll x = q.front().first;
            ll d = q.front().second;
            q.pop();
            if(!node[x].empty()) {
                for(auto next: node[x]) {
                    q.push({next,d+1});
                }
            }
            else {
                ans+=d*2;
            }
        }
    }
    cout<<ans<<"\n";
    return 0;
}