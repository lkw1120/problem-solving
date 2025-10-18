#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll> r,c;
ll R[6],C[6];
ll N;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    r.resize(N);
    c.resize(N);
    for(int i=0;i<N;i++) {
        cin>>r[i];
    }
    for(int i=0;i<N;i++) {
        cin>>c[i];
    }
    ll mx,mn;
    mx = 0;
    mn = N*N;
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            mx+=min(r[i],c[j]);
        }
    }
    for(int i=0;i<N;i++) {
        int a,b;
        a = r[i];
        b = c[i];
        R[a]++;
        C[b]++;
    }
    for(int i=1;i<=5;i++) {
        mn+=max(R[i],C[i])*(i-1)*1LL;
    }
    cout<<mn<<" "<<mx<<"\n";
    return 0;
}