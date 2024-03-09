#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll> v;
ll N,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>N;
    v.resize(3*N);
    for(int i=0;i<3*N;i++) {
        cin>>v[i];
    }
    sort(v.begin(),v.end());
    ans = v[2*N-1]-v[N];
    cout<<ans<<"\n";
    return 0;
}