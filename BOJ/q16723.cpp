#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll N,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>N;
    ans = 2*N;
    int p = 1;
    while(N) {
        N/=2;
        ans+=(1<<p)*N;
        p++;
    }
    cout<<ans<<"\n";    
    return 0;
}