#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll N,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    ans = 0;
    if(3 <= N) {
        ll num = (N-1)*(N-2);
        if(N%3 == 0) {
            num+=4;
        }
        ans = num/6;
    }
    cout<<ans<<"\n";
    return 0;
}