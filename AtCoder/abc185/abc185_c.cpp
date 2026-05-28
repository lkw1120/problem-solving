#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll L,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>L;
    ans = 1;
    for(int i=1;i<=11;i++) {
        ans*=(L-i);
        ans/=i;
    }
    cout<<ans<<"\n";
    return 0;
}