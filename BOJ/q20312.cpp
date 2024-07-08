#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e9+7;
int arr[500001];
ll N,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>N;
    for(int i=2;i<=N;i++) {
        cin>>arr[i];
    }
    ll tmp = 0;
    ans = 0;
    for(int i=2;i<=N;i++) {
        tmp = (tmp+1)*arr[i]%MOD;
        ans+=tmp;
    }
    ans%=MOD;
    cout<<ans<<"\n";
    return 0;
}