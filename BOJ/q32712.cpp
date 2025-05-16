#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX_N = 200003;
ll prefix[MAX_N];
ll arr[MAX_N];
ll N,K,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>K;
    for(int i=1;i<=N;i++) {
        cin>>arr[i];
        prefix[i] = prefix[i-1]+arr[i];
    }
    if(N == 1) {
        ans = arr[1]*K;
    }
    else {
        ll sum = prefix[N];
        for(int i=1;i<=N;i++) {
            ll d1,d2;
            d1 = i-1;
            d2 = N-d1;
            if(d1 <= K) {
                ans = max(ans,prefix[d1]+(K-d1)*arr[i]);
            }
            if(d2 <= K) {
                ans = max(ans,(sum-prefix[d1])+(K-d2)*arr[i]);
            }
        }
    }
    cout<<ans<<"\n";
    return 0;
}