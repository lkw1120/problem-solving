#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll T,N,M,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>T;
    while(T--) {
        cin>>N>>M;
        ans = M;
        while(N) {
            N/=2;
            ans++;
        }
        cout<<ans<<"\n";
    }
    return 0;
}