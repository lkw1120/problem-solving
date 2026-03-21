#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll> v;
ll N,X,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>X;
    v.resize(N);
    for(int i=0;i<N;i++) {
        cin>>v[i];
    }
    sort(v.begin(),v.end());
    int l,r;
    l = 0;
    r = N-1;
    ans = 0;
    while(l < r) {
        ll sum = v[l]+v[r];
        if(sum <= X) {
            ans = max(ans,sum);
            l++;
        }
        else {
            r--;
        }
    }
    cout<<ans<<"\n";
    return 0;
}