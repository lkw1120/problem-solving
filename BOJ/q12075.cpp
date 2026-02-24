#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll T,K,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>T;
    for(int tc=1;tc<=T;tc++) {
        cin >> K;
        ll p = 1;
        while(p <= K) {
            p<<=1;
        }
        ll mid = p>>1;
        int cnt = 0;
        while(K != mid) {
            if(K < mid) {
                p>>=1;
                mid>>=1;
            } 
            else {
                K = p-K;
                cnt++;
                p>>=1;
                mid>>=1;
            }
        }
        ans = cnt%2;
        cout<<"Case #"<<tc<<": "<<ans<<"\n";
    }
    return 0;
}