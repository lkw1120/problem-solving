#include<bits/stdc++.h>
using namespace std;
int N;
double ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout<<fixed<<setprecision(5);
    while(cin>>N) {
        int n = N/2;
        double tmp = 1.0;
        for(int i=1;i<=n-1;i++) {
            tmp*=(2.0*i)/(2.0*i-1.0);
        }
        tmp/=(2.0*n-1.0);
        ans = tmp;
        cout<<ans<<"\n";
    }
    return 0;
}