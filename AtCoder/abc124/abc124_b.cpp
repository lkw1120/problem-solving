#include<bits/stdc++.h>
using namespace std;
int N,H,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    int high = 0;
    for(int i=0;i<N;i++) {
        cin>>H;
        if(high <= H) {
            ans++;
            high = H;
        }
    }
    cout<<ans<<"\n";
    return 0;
}