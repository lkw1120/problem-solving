#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll> A;
ll N,K,X,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>K>>X;
    A.resize(N);
    for(int i=0;i<N;i++) {
        cin>>A[i];
    }
    for(int i=0;i<N;i++) {
        ll cnt = min(K,A[i]/X);
        A[i]-=cnt*X;
        K-=cnt;
    }
    sort(A.begin(),A.end(),greater<ll>());
    for(int i=0;i<N;i++) {
        if(K > 0) {
            A[i] = 0;
            K--;
        }
    }
    ans = 0;
    for(int i=0;i<N;i++) {
        ans+=A[i];
    }
    cout<<ans<<"\n";
    return 0;
}