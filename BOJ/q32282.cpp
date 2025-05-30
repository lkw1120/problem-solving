#include<bits/stdc++.h>
using namespace std;
int X,Y,C,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>X>>Y>>C;
    int d = X*X+Y*Y;
    int c = C*C;
    if(d == 0) {
        ans = 0;
    }
    else if(d == c) {
        ans = 1;
    }
    else if(d < c) {
        ans = 2;
    }
    else {
        double tmp = sqrt((double)d);
        ans = ceil(tmp/C);
    }
    cout<<ans<<"\n";
    return 0;
}