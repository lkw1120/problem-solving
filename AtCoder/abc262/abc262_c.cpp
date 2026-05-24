#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll> a;
ll N,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    a.resize(N+1);
    for(int i=1;i<=N;i++) {
        cin>>a[i];
    }
    ll tmp = 0;
    for(int i=1;i<=N;i++) {
        if(a[i] == i) tmp++;
    }
    ans = tmp*(tmp-1)/2;
    for(int i=1;i<=N;i++) {
        int j = a[i];
        if(i < j && a[j] == i) {
            ans++;
        }
    }
    cout<<ans<<"\n";
    return 0;
}