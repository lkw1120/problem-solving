#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll N,K,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>K;
    int size = to_string(N).size();
    ll pow10d = 1%K;
    for(int i=0;i<size;i++) {
        pow10d = (pow10d*10)%K;
    }
    ll mod =N%K;
    ll r = 0;
    ans = -1;
    for(int i=1;i<=K;i++) {
        r = (r*pow10d+mod)%K;
        if(r == 0) {
            ans = i;
            break;
        }
    }
    cout<<ans<<"\n";
    return 0;
}