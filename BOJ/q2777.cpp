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
        if(N == 1) {
            ans = 1;
        }
        else {
            int cnt = 0;
            for(int i=9;i>1;i--) {
                while(N%i == 0) {
                    N/=i;
                    cnt++;
                }
            }
            ans = N == 1? cnt:-1;
        }
        cout<<ans<<"\n";
    }
    
    return 0;
}