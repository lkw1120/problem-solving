#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll arr[10001];
ll N,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    for(int i=0;i<N;i++) {
        cin>>arr[i];
    }
    ans = 0;
    for(int i=0;i<N;i++) {
        ll tmp = arr[i];
        for(int j=i;j<N;j++) {
            tmp = min(tmp,arr[j]);
            ans = max(ans,tmp*(j-i+1));
        }
    }
    cout<<ans<<"\n";
    return 0;
}