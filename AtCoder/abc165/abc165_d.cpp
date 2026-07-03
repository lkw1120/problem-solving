#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll A,B,N,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>A>>B>>N;
    ll x = min(B-1,N);
    ans = (A*x)/B;
    cout<<ans<<"\n";
    return 0;
}