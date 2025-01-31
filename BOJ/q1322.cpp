#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll X,K,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>X>>K;
    ans = 0;
    int idx = 0;
    for(int i=0;i<65;i++){
        if((X >> i) & 1LL) continue; 
        if((K >> idx) & 1LL) {
            ans|=(1LL << i);
        }
        idx++;
    }
    cout<<ans<<"\n";
    return 0;
}