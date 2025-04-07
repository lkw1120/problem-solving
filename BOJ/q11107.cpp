#include<bits/stdc++.h>
using namespace std;
double dp[101][101];
bool checked[101][101];
int N,X,Y;
double ans;
double go(int x, int y) {
    if(Y <= y) {
        return 1.0;
    }
    if(x == 0) {
        return 0.0;
    }
    if(checked[x][y]) {
        return dp[x][y];
    }
    double res = 0;
    res+=0.7*go(x-1,y);
    res+=0.2*go(x-1,y+1);
    res+=0.1*go(x,y+1);
    dp[x][y] = res;
    checked[x][y] = true;
    return res;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>N;
    cout.precision(3);
    cout<<fixed;
    while(N--) {
        fill(&checked[0][0],&checked[100][101],false);
        cin>>X>>Y;
        if(Y == 0) {
            ans = 1.0;
        }
        else if(X == 0) {
            ans = 0.0;
        }
        else {
            ans = go(X,0);
        }
        cout<<ans<<"\n";
    }
    return 0;
}