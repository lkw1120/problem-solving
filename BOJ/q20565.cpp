#include<bits/stdc++.h>
using namespace std;
int N,M;
double ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>M;
    if(M < N) {
        ans = 0.0;
    }
    else {
        int q = M/N;
        int r = M%N;
        ans = 1.0;
        for(int i=0;i<N-r;i++) {
            ans*=q;
        }
        for(int i=0;i<r;i++) {
            ans*=(q+1);
        }
        for(int i=0;i<N;i++) {
            ans/=6.0;
        }
    }
    cout<<fixed<<setprecision(6);
    cout<<ans<<"\n";
    return 0;
}