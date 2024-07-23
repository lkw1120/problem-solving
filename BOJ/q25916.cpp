#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll arr[500001];
ll N,M,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout.tie(0);
    cin>>N>>M;
    for(int i=1;i<=N;i++) {
        cin>>arr[i];
        arr[i]+=arr[i-1];
    }
    ll sum = 0;
    int j = 0;
    for(int i=1;i<=N;i++) {
        sum = arr[i]-arr[j];
        while(M < sum) {
            sum = arr[i]-arr[++j];
        }
        ans = max(ans,sum);
    }
    cout<<ans<<"\n";
    return 0;
}