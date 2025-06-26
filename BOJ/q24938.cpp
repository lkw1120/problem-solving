#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX_N = 200001;
ll arr[MAX_N];
ll N,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    ll sum = 0;
    for(int i=1;i<=N;i++) {
        cin>>arr[i];
        sum+=arr[i];
    }
    ll T = sum/N;
    ll tmp = 0;
    ans = 0;
    for(int i=1;i<=N;i++) {
        tmp+=arr[i]-T;
        ans+=llabs(tmp);
    }
    cout<<ans<<"\n";
    return 0;
}