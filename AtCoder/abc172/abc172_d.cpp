#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll N,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    ans = 0;
    for(int i=1;i<=N;i++) {
        ll m = N/i;
        ans+=i*m*(m+1)/2;
    }
    cout<<ans<<"\n";
    return 0;
}