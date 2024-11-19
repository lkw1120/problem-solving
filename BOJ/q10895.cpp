#include<bits/stdc++.h>
using namespace std;
int A,K,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>A>>K;
    if(A == 1) {
        ans = 1;
    }
    else if(K == 0) {
        ans = A;
    }
    else if(K != 0 && A%2 == 1) {
        ans = A;
    }
    else if(K != 0 && A%2 == 0) {
        ans = 1;
    }
    cout<<ans<<"\n";
    return 0;
}