#include<bits/stdc++.h>
using namespace std;
int A,B,H,M;
double ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>A>>B>>H>>M;
    double h = 30.0*H+0.5*M;
    double m = 6.0*M;
    double angle = abs(h-m);
    double r = angle*M_PI/180.0;
    ans = sqrt(A*A+B*B-2.0*A*B*cos(r));
    cout<<fixed<<setprecision(10)<<ans<<"\n";
    return 0;
}