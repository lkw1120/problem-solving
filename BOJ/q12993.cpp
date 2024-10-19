#include<bits/stdc++.h>
using namespace std;
int X,Y,ans;
int find(int x, int y, int t) {
    if(X == x && Y == y) {
        return 1;
    }
    if(X < x || Y < y) {
        return 0;
    }
    int p = 1;
    for(int i=0;i<t;i++) {
        p*=3;
    }
    if(p <= X && find(x+p,y,t+1)) {
        return 1;
    }
    if(p <= Y && find(x,y+p,t+1)) {
        return 1;
    }
    return 0;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>X>>Y;
    ans = find(0,0,0);
    cout<<ans<<"\n";
    return 0;
}