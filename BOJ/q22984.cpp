#include <bits/stdc++.h>
using namespace std;
vector<double> p;
int N;
double ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    p.resize(N);
    for(int i=0;i<N;i++) {
        cin>>p[i];
    }
    ans = 0.0;
    for(int i=0;i<N;i++) {
        ans+=p[i];
    }
    for(int i=1;i<N;i++) {
        ans+=p[i]+p[i-1]-2.0*p[i]*p[i-1];
    }
    cout<<fixed<<setprecision(9)<<ans<<"\n";
    return 0;
}