#include<bits/stdc++.h>
using namespace std;
const double PI = acos(-1.0);
int T,N;
double ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>T;
    cout<<fixed<<setprecision(5);
    while(T--) {
        cin>>N;
        double s = sin(PI/(double)N);
        ans = 10000.0/(s*s);
        cout<<ans<<"\n";
    }
    return 0;
}