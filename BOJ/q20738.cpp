#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll N;
double ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    ll sum = 0;
    for(int i=0;i<N;i++) {
        ll x,y;
        cin>>x>>y;
        sum+=(y-x);
    }
    ans = 1.0*sum/N;
    cout<<fixed<<setprecision(6)<<ans<<"\n";
    return 0;
}