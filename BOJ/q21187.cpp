#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX_W = 20001;
ll arr[MAX_W];
ll prefix[MAX_W];
ll M,W,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>M;
    ll sum = 0;
    for(int i=0;i<M;i++) {
        cin>>W;
        arr[W]++;
        sum+=W;
    }
    for(int i=1;i<MAX_W;i++) {
        prefix[i] = prefix[i-1]+arr[i]*1LL*i;
    }
    for(int i=1;i<MAX_W;i++) {
        ll low = prefix[i-1];
        ll high = sum-prefix[i];
        if(low == high) {
            ans = i;
            break;
        }
    }
    cout<<ans<<"\n";
    return 0;
}