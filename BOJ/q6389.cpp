#include<bits/stdc++.h>
using namespace std;
int T,M,N;
double ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>T;
    for(int tc=1;tc<=T;tc++) {
        cin>>M>>N;
        if((M*N)%2) {
            ans = 1.0*M*N-1.0+sqrt(2.0);
        }
        else {
            ans = 1.0*M*N;
        }
        cout<<"Scenario #"<<tc<<":"<<"\n";
        cout<<fixed<<setprecision(2)<<ans<<"\n\n";
    }
    return 0;
}