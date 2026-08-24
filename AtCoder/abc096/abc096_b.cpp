#include<bits/stdc++.h>
using namespace std;
int A,B,C,K,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>A>>B>>C;
    cin>>K;
    int mx = max({A,B,C});
    int sum = A+B+C;
    for(int i=0;i<K;i++) {
        mx*=2;
    }
    ans = sum-max({A,B,C})+mx;
    cout<<ans<<"\n";
    return 0;
}