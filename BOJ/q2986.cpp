#include<bits/stdc++.h>
using namespace std;
int N,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    ans = N-1;
    for(int i=2;i*i<=N;i++) {
        if(N%i == 0) {
            ans = N-N/i;
            break;
        }
    }
    cout<<ans<<"\n";
    return 0;
}