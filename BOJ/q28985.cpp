#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll N,ans;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    ans = 0;
    if(6 < N) {
        ll tmp = N*(N+1)/2;
        if(tmp%2 == 0) {
            ans = tmp;
        }
        else {
            ans = tmp-1;
        }
    }
    cout<<ans<<"\n";
    return 0;
}