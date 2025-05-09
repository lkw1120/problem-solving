#include<bits/stdc++.h>
using namespace std;
int N,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    if(N == 2) {
        ans = 1;
    }
    else if(N == 3) {
        ans = 3;
    }
    else {
        ans = 3*N-4;
    }
    cout<<ans<<"\n";
    return 0;
}