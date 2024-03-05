#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll> v;
ll T,N,ans;
void init() {
    ll n = 1;
    for(int i=0;i<=18;i++) {
        v.push_back(n);
        int size = v.size();
        for(int j=0;j<size;j++) {
            if(n+v[j] < 2*n) {
                v.push_back(n+v[j]);
            }
        }
        n*=10;
    }
    sort(v.begin(),v.end());
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    init();
    cin>>T;
    while(T--) {
        cin>>N;
        for(int i=0;i<v.size();i++) {
            if(v[i]%N == 0) {
                ans = v[i];
                break;
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}