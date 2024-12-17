#include<bits/stdc++.h>
using namespace std;
int T,S,F,ans;
int find(int n) {
    int tmp = n%4;
    if(tmp == 0) return n;
    else if(tmp == 1) return 1;
    else if(tmp == 2) return n+1;
    return 0;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>T;
    while(T--) {
        cin>>S>>F;
        ans = find(S-1)^find(F);
        cout<<ans<<"\n";
    }
    return 0;
}