#include<bits/stdc++.h>
using namespace std;
int T,N;
double R,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>T;
    for(int t=1;t<=T;t++) {
        cin>>R>>N;
        ans = R*sin(M_PI/N)/(1+sin(M_PI/N));
        cout<<"Scenario #"<<t<<":"<<"\n";
        cout.precision(3);
        cout<<fixed;
        cout<<ans<<"\n\n";
    }
    return 0;
}