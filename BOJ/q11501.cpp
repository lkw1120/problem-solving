#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
ll T,N,M,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>T;
    while(T--) {
        cin>>N;
        vector<int> v(N);
        for(int i=0;i<N;i++) {
            cin>>v[i];
        }
        ans = 0;
        M = 0;
        for(int i=N-1;i>=0;i--) {
            if(M < v[i]) {
                M = v[i];
            }
            else {
                ans+=(M-v[i]);
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}