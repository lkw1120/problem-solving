#include<bits/stdc++.h>
using namespace std;
int A,B,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>A>>B;
    if(A == 0 || B == 0) {
        ans = 1;
    }
    else {
        ans = B*log10(A)+1;
    }
    cout<<ans<<"\n";
    return 0;
}