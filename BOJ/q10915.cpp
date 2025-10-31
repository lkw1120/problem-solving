#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll N,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    if(N%2) {
        ans = (N-1)/2;
    }
    else {
        ans = N-1;
    }
    cout<<ans<<"\n";
    return 0;
}