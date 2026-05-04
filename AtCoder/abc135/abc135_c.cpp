#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll> A,B;
ll N,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    A.resize(N+1);
    B.resize(N);
    for(int i=0;i<=N;i++) {
        cin>>A[i];
    }
    for(int i=0;i<N;i++) {
        cin>>B[i];
    }
    ans = 0;
    for(int i=0;i<N;i++) {
        ll x = min(A[i],B[i]);
        A[i]-=x;
        B[i]-=x;
        ans+=x;
        ll y = min(A[i+1],B[i]);
        A[i+1]-=y;
        B[i]-=y;
        ans+=y;
    }
    cout<<ans<<"\n";
    return 0;
}