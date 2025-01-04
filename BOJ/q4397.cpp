#include<bits/stdc++.h>
using namespace std;
int P,Q,R,S;
double ans;
double solve(int a, int b, int c, int d) {
    double res = 1;
    for(int i=1;i<=max(b,d);i++) {
        if(i <= b) {
            res*=(a-(b-i));
            res/=i;
        }
        if(i <= d) {
            res/=(c-(d-i));
            res*=i;
        }
    }
    return res;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    while(1) {
        cin>>P;
        if(cin.eof()) break;
        cin>>Q>>R>>S;
        ans = solve(P,Q,R,S);
        cout<<fixed;
        cout.precision(5);
        cout<<ans<<"\n";
    }
    return 0;
}