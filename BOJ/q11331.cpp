#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX_N = 1e6+1;
ll arr[MAX_N];
ll N,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    while(true) {
        fill(arr,arr+MAX_N,0LL);
        cin>>N;
        if(N == 0) break;
        int mx = 0;
        for(int i=0;i<N;i++) {
            int d;
            cin>>d;
            arr[d]++;
            mx = max(d,mx);
        }
        ll cnt = 0;
        ll best = 0;
        ans = 0;
        for(int i=mx;i>=0;i--) {
            cnt+=arr[i];
            ll tmp = 1LL*i*cnt;
            if(best < tmp || (best == tmp && i < ans)) {
                best = tmp;
                ans = i;
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}