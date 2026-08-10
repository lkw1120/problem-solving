#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll> a,b;
int N,M,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>M;
    a.resize(N);
    b.resize(M);
    for(int i=0;i<N;i++) {
        cin>>a[i];
    }
    for(int i=0;i<M;i++) {
        cin>>b[i];
    }
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    int shari = 0;
    int neta = 0;
    while(shari < N && neta < M) {
        if(b[neta] <= 2*a[shari]) {
            ans++;
            shari++;
            neta++;
        }
        else {
            shari++;
        }
    }
    cout<<ans<<"\n";
    return 0;
}