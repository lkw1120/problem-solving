#include<bits/stdc++.h>
using namespace std;
int N,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>N;
    if(1 < N) {
        ans = 2*N-2;
    }
    else {
        ans = 1;
    }
    cout<<ans<<"\n";
    for(int i=1;i<=N;i++) {
        cout<<1<<" "<<i<<"\n";
    }
    for(int i=2;i<N;i++) {
        cout<<N<<" "<<i<<"\n";
    }
    return 0;
}