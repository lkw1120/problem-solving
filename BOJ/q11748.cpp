#include<bits/stdc++.h>
using namespace std;
vector<double> r,v;
int N;
double ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    r.resize(N);
    for(int i=0;i<N;i++) {
        cin>>r[i];
    }
    v.resize(N);
    v[0] = 0.0;
    for(int i=1;i<N;i++) {
        double x = 0.0;
        for(int j=0;j<i;j++) {
            double d = 2.0*sqrt(r[i]*r[j]);
            x = max(x,v[j]+d);
        }
        v[i] = x;
    }
    double left = 1e100;
    double right = -1e100;
    for(int i = 0; i < N; i++) {
        left = min(left,v[i]-r[i]);
        right = max(right,v[i]+r[i]);
    }
    ans = right-left;
    cout<<fixed<<setprecision(10)<<ans<<"\n";
    return 0;
}