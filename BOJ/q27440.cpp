#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
unordered_map<ll,ll> mp;
ll N,ans;
void find(ll n) {
    queue<ll> q;
    q.push(n);
    mp[n] = 0;
    while(!q.empty()) {
        ll x = q.front();
        q.pop();
        if(x == 1) {
            ans = mp[1];
            break;
        }
        if(x%3 == 0 && !mp[x/3]) {
            mp[x/3] = mp[x]+1;
            q.push(x/3);
        }
        if(x%2 == 0 && !mp[x/2]) {
            mp[x/2] = mp[x]+1;
            q.push(x/2);
        }
        if(1 <= x-1 && !mp[x-1]) {
            mp[x-1] = mp[x]+1;
            q.push(x-1);
        }
    }
    return ;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>N;
    find(N);
    cout<<ans<<"\n";
    return 0;
}