#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MAX = 1e18;
vector<ll> v;
ll A,B,C,N,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>A>>B>>C>>N;
    for(int i=0;i<=60;i++) {
        for(int j=0;j<=60;j++) {
            for(int k=0;k<=60;k++) {
                ll X = pow(A,i)*pow(B,j)*pow(C,k);
                if(1 < X && X < MAX) {
                    v.push_back(X);
                }	
            }
        }
    }
    sort(v.begin(),v.end());
    ans = v[N-1];
    cout<<ans<<"\n";
    return 0;
}