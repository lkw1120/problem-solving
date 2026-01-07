#include<bits/stdc++.h>
using namespace std;
int T,N,M;
double ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>T;
    while(T--) {
        cin>>M>>N;
        double vertical = (1.0*M*M-1.0)/(3.0*M);
        double horizontal = 1.0*N/2;
        ans = vertical + horizontal;
        cout<<fixed<<setprecision(1)<<ans<<"\n";
    }
    return 0;
}