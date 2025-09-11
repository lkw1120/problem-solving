#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e9+7;
const int MAX_N = 200001;
ll arr[MAX_N];
ll multi[MAX_N];
ll N,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    for(int i=0;i<N;i++) {
        cin>>arr[i];
    }
    sort(arr,arr+N);
    multi[0] = 1;
    for(int i=1;i<N;i++) {
        multi[i] = (multi[i-1]*2)%MOD;
    }
    ans = 0;
    for(int i=0;i<N;i++) {
        ans = (ans+(arr[i]*multi[i])%MOD)%MOD;
    }
    cout<<ans<<"\n";
    return 0;
}