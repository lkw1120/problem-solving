#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX = 100001;
ll arr[MAX][2];
ll N,T,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>N>>T;
    for(int i=0;i<N;i++) {
        cin>>arr[i][0]>>arr[i][1];
    }
    ans = 0;
    ll cur = LONG_LONG_MAX;
    for(int i=N-1;i>=0;i--) {
        ll tmp = arr[i][0]+arr[i][1]*T;
        if (tmp < cur) {
            ans++;
            cur = tmp;
        }
    }
    cout<<ans<<"\n";
    return 0;
}