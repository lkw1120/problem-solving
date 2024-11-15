#include<bits/stdc++.h>
using namespace std;
int X[3009];
int T[3009];
int N,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>N;
    for(int i=1;i<=N;i++) {
        cin>>X[i];
    }
    for(int i=1;i<=N;i++) {
        cin>>T[i];
    }
    ans = max(X[N],T[N]);
    for(int i=N-1;i>0;i--) {
        ans+=X[i+1]-X[i];
        if(ans < T[i]) {
            ans = T[i];
        }
    }
    ans+=X[1];
    cout<<ans<<"\n";
    return 0;
}