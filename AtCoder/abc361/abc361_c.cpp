#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll> A;
int N,K;
ll ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>K;
    A.resize(N);
    for(int i=0;i<N;i++) {
        cin>>A[i];
    }
    sort(A.begin(),A.end());
    int M = N-K;
    ans = LLONG_MAX;
    for(int i=0;i+M-1<N;i++) {
        ans = min(ans,A[i+M-1]-A[i]);
    }
    cout<<ans<<"\n";
    return 0;
}