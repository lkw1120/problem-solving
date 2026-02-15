#include<bits/stdc++.h>
using namespace std;
int N,K;
double P,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>K>>P;
    if(K == N || 1.0 <= P) {
        ans = 1.0;
    }
    else {
        ans = P/(P+(1.0-P)*(double)(N-K)/N);
    }
    cout<<fixed<<setprecision(10)<<ans<<"\n";
    return 0;
}