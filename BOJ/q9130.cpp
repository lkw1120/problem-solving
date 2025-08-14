#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll T,N,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>T;
    while(T--) {
        cin>>N;
        if(N == 0) {
            ans = 1;
        }
        else if(N == 1) {
            ans = 2;
        }
        else {
            ans = 2*N*N-4*N+5;
        }
        cout<<ans<<"\n";
    }
    return 0;
}