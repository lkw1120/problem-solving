#include<bits/stdc++.h>
using namespace std;
double N,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    ans = N*(N-1)/4.0;
    cout<<fixed<<setprecision(10)<<ans<<"\n";
    return 0;
}