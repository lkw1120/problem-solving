#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll> v;
ll N,M,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>M;
    v.resize(N);
    for(int i=0;i<N;i++) {
        cin>>v[i];
    }
    ll l,r,sum;
    l = r = sum = 0;
    ans = N+1;
    while(r < N) {
        sum+=v[r];
        while(l <= r && sum-v[l] >= M) {
            sum-=v[l];
            l++;
        }
        if(sum >= M) {
            ans = min(ans,r-l+1);
        }
        r++;
    }
    if(ans == N+1) {
        cout<<"NEPAVYKS"<<"\n";
    }
    else {
        cout<<ans<<"\n";
    }
    return 0;
}