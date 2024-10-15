#include<bits/stdc++.h>
using namespace std;
int N,M,K,ans;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>N>>M>>K;
    ans = min(log2(N),log2(K)+M);
    cout<<ans<<"\n";
    return 0;
}