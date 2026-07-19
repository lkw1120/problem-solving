#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll r1,c1,r2,c2;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>r1>>c1;
    cin>>r2>>c2;
    ll dr = abs(r1-r2);
    ll dc = abs(c1-c2);
    if(dr == 0 && dc == 0) {
        cout<<0<<"\n";
    }
    else if(dr == dc || dr+dc <= 3) {
        cout<<1<<"\n";
    }
    else if(
        (r1+c1)%2 == (r2+c2)%2 || dr+dc <= 6 ||
        abs((r1+c1)-(r2+c2)) <= 3 || abs((r1-c1)-(r2-c2)) <= 3
    ) {
        cout<<2<<"\n";
    }
    else {
        cout<<3<<"\n";
    }
    return 0;
}