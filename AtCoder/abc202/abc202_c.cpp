#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll> a,b,c;
ll cnt[100001];
ll N,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    a.resize(N);
    b.resize(N);
    c.resize(N);
    for(int i=0;i<N;i++) {
        cin>>a[i];
        cnt[a[i]]++;
    }
    for(int i=0;i<N;i++) {
        cin>>b[i];
    }
    for(int i=0;i<N;i++) {
        cin>>c[i];
    }
    ans = 0;
    for(int i=0;i<N;i++) {
        ll tmp = b[c[i]-1];
        ans+=cnt[tmp];
    }
    cout<<ans<<"\n";
    return 0;
}