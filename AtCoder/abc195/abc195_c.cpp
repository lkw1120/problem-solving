#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll N,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    ans = 0;
    for(ll i=1000;i<=N;i*=1000) {
        ans+=N-i+1;
    }
    cout<<ans<<"\n";
    return 0;
}