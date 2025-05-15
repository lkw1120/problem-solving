#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll N,K,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>K;
    ans = 0;
    for(int i=2;i<=N;i++) {
        ans = ans+ans/(K-1)+1;
    }
    cout<<ans<<"\n";
    return 0;
}