#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll x[3],y[3];
ll X,Y;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    for(int i=0;i<3;i++) {
        cin>>x[i]>>y[i];
    }
    ll ab2 = (x[0]-x[1])*(x[0]-x[1])+(y[0]-y[1])*(y[0]-y[1]);
    ll bc2 = (x[1]-x[2])*(x[1]-x[2])+(y[1]-y[2])*(y[1]-y[2]);
    ll ca2 = (x[2]-x[0])*(x[2]-x[0])+(y[2]-y[0])*(y[2]-y[0]);
    int p,q,r;
    if(ab2 >= bc2 && ab2 >= ca2) {
        p = 0,q = 1,r = 2;
    } 
    else if(bc2 >= ab2 && bc2 >= ca2) {
        p = 1,q = 2,r = 0;
    }
    else {
        p = 2,q = 0,r = 1;
    }
    X = x[p]+x[q]-x[r];
    Y = y[p]+y[q]-y[r];
    cout<<X<<" "<<Y<<"\n";
    return 0;
}