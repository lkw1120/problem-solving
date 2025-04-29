#include<bits/stdc++.h>
using namespace std;
int N,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    if(N <= 9) {
        ans = 1;
    }
    else {
        int L = (N+8)/9;
        bool odd,even;
        odd = (L%2 == 1);
        even = (N%2 == 0);
        ans = (odd || even)? L: (L+1);
    }
    cout<<ans<<"\n";
    return 0;
}