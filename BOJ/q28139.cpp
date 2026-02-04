#include<bits/stdc++.h>
using namespace std;
vector<double> x,y;
int N;
double ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    x.resize(N);
    y.resize(N);
    for(int i=0;i<N;i++) {
        cin>>x[i]>>y[i];
    }
    double sum = 0.0;
    for(int i=0;i<N;i++) {
        for(int j=i+1;j<N;j++) {
            double dx = x[i]-x[j];
            double dy = y[i]-y[j];
            sum+=sqrt(dx*dx+dy*dy);
        }
    }
    ans = (2.0/N)*sum;
    cout<<fixed<<setprecision(10)<<ans<<"\n";
    return 0;
}