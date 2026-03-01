#include<bits/stdc++.h>
using namespace std;
int N,T;
double F,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    cout<<fixed<<setprecision(6);
    for(int tc=1;tc<=N;tc++) {
        cin>>F>>T;
        double tmp = 1.0+F/2.0;
        ans = pow(tmp,(double)T);
        cout<<"Case #"<<tc<<": "<<ans<<"\n";
    }
    return 0;
}