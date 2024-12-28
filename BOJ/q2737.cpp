#include<bits/stdc++.h>
using namespace std;
int T,N,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>T;
    while(T--) {
        cin>>N;
        int n,cnt;
        n = cnt = 0;
        ans = 0;
        while(0 < N) {
            n++;
            N-=n;
            if(1 < n && N%n == 0) {
                ans++;
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}