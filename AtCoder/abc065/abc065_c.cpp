#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e9+7;
const int MAX = 100001;
ll cache[MAX];
ll N,M,ans;
void init() {
    cache[1] = 1;
    for(int i=2;i<MAX;i++) {
        cache[i] = (cache[i-1]*i)%MOD;
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    init();
    cin>>N>>M;
    ans = 0;
    if(abs(N-M) <= 1) {
        ans = (cache[N]*cache[M])%MOD;
        if(N == M) {
            ans = (ans*2)%MOD;
        }
    }
    cout<<ans<<"\n";
    return 0;
}