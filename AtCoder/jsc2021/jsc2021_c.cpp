#include<bits/stdc++.h>
using namespace std;
int A,B,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>A>>B;
    for(int i=B;i>=1;i--) {
        int cnt = B/i-(A-1)/i;
        if(cnt >= 2) {
            ans = i;
            break;
        }
    }
    cout<<ans<<"\n";
    return 0;
}