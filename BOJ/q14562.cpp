#include<bits/stdc++.h>
using namespace std;
int C,S,T,ans;
void solve(int s, int t, int n) {
    if(s == t) {
        ans = min(ans,n);
        return ;
    }
    else if(s < t) {
        solve(s*2,t+3,n+1);
        solve(s+1,t,n+1);
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>C;
    while(C--) {
        cin>>S>>T;
        ans = INT_MAX;   
        solve(S,T,0);
        cout<<ans<<"\n";
    }
    return 0;
}