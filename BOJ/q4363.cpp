#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll hx,hy;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>hx>>hy;
    double sum = 0.0L;
    ll x1,x2,y1,y2;
    while(cin>>x1>>y1>>x2>>y2) {
        double dx = x1-x2;
        double dy = y1-y2;
        sum+=hypot(dx,dy);
    }
    ll total = (ll)(sum*0.006+0.5);
    ll H = total/60;
    ll M = total%60;
    cout<<H<<":"<<setw(2)<<setfill('0')<<M<<"\n";
    return 0;
}