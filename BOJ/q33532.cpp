#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll N,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    ans = 0;
    while(N > 0) {
        N/=5;
        ans+=N;
    }
    cout<<ans<<"\n";
    return 0;
}