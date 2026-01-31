#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll N,M;
double ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    M = min(N,25LL);
    double sum = 0.0;
    double tmp = 1.0;
    for(ll i=0;i<=M;i++) {
        if(i == 0) {
            tmp = 1.0;
        }
        else {
            tmp/=(double)i;
        }
        if(i%2 == 0) {
            sum+=tmp;
        }
        else {
            sum-=tmp;
        }
    }
    ans = 1.0-sum;
    cout<<fixed<<setprecision(10)<<ans<<"\n";
    return 0;
}