#include<bits/stdc++.h>
using namespace std;
double N,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>N;
    ans = 0;
    for(int i=1;i<=N;i++) {
        ans+=(N/i);
    }
    cout<<fixed;
    cout.precision(9);
    cout<<ans<<"\n";
    return 0;
}