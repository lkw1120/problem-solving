#include<bits/stdc++.h>
using namespace std;
vector<int> v;
int N,K;
double ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>K;
    v.resize(K);
    for(int i=0;i<K;i++) {
        cin>>v[i];
    }
    double p = 1.0;
    for(int i=0;i<K;i++) {
        double a = 1.0*v[i]/N;
        p = p*(1.0-2.0*a)+a;
    }
    ans = N*p;
    cout<<fixed<<setprecision(10)<<ans<<"\n";
    return 0;
}