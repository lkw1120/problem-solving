#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll S,T,ans;
ll find(int n) {
    ll sum = 0;
    for(int i=1;i<=n;i++) {
        if(i%2) {
            sum-=n/i;
        }
        else {
            sum+=n/i;
        }
    }
    return sum;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>S>>T;
    ans = find(T)-find(S-1);
    cout<<ans<<"\n";
    return 0;
}