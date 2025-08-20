#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX_N = 200001;
ll arr[MAX_N];
ll prefix[MAX_N];
ll N,Q,P,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    for(int i=0;i<N;i++) {
        cin>>arr[i];
    }
    sort(arr,arr+N,greater<ll>());
    ll tmp = 0;
    for(int i=0;i<N;i++) {
        tmp+=arr[i];
        prefix[i] = tmp;
    } 
    cin>>Q;
    while(Q--) {
        cin>>P;
        ans = (lower_bound(prefix,prefix+N,P)-prefix)+1;
        cout<<ans<<"\n";
    }
    return 0;
}