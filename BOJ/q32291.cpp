#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll> v;
ll X;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>X;
    ll N = X+1;
    ll tmp = floor(sqrtl(N));
    for(ll i=1;i<=tmp;i++) {
        if(N%i == 0) {
            if(i <= X) {
                v.push_back(i);
            }
            ll j = N/i;
            if(j != i && j <= X) { 
                v.push_back(j);
            }
        }
    }
    sort(v.begin(),v.end());
    for(auto item: v) {
        cout<<item<<" ";
    }
    cout<<"\n";
    return 0;
}