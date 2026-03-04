#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX_N = 1e6+1;
ll spf[MAX_N];
ll T,N,ans;
void init() {
    for(int i=0;i<MAX_N;i++) {
        spf[i] = i;
    }
    for(int i=2;i*i<MAX_N;i++) {
        if(spf[i] == i) {
            for(int j=i*i;j<MAX_N;j+=i) {
                if(spf[j] == j) spf[j] = i;
            }
        }
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    init();
    cin>>T;
    while(T--) {
        cin>>N;
        ans = 0;
        while(N > 1) {
            ll p = spf[N];
            ll cnt = 0;
            while(N%p == 0) {
                N/=p;
                cnt++;
            }
            ans = max(ans,cnt);
        }
        cout<<ans<<"\n";
    }
    return 0;
}