#include<bits/stdc++.h>
using namespace std;
int N,M,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>N>>M;
    ans = (M-N)*(M-N+1)/2;
    cout<<ans<<"\n";
    return 0;
}