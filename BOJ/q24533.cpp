#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll N,A,B,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>N;
    for(int i=0;i<N;i++) {
        ll a,b;
        cin>>a>>b;
        ans+=(A*b+B*a);
        A+=a;
        B+=b;
    }
    cout<<ans<<"\n";
    return 0;
}