#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll T,N,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>T;
    while(T--) {
        cin>>N;
        ans = ((N-1)*(N-1))/4;
        cout<<ans<<"\n";
    }
    return 0;
}