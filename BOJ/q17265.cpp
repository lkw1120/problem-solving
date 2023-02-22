#include<bits/stdc++.h>
using namespace std;
int N,ans1,ans2;
char mp[6][6];
void dfs(int x, int y, int n, char op) {
    if((x+y)%2) {
        op = mp[x][y];
    }
    else {
        switch(op) {
            case '+':
                n+=(mp[x][y]-'0');
                break;
            case '-':
                n-=(mp[x][y]-'0');
                break;
            case '*':
                n*=(mp[x][y]-'0');
                break;
            default :
                break;
        }
    }
    if(x == N && y == N) {
        ans1 = max(ans1,n);
        ans2 = min(ans2,n);
        return ;
    }
    if(x < N) {
        dfs(x+1,y,n,op);
    }
    if(y < N) {
        dfs(x,y+1,n,op);
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>N;
    for(int i=1;i<=N;i++) {
        for(int j=1;j<=N;j++) {
            cin>>mp[i][j];
        }
    }
    ans1 = INT_MIN;
    ans2 = INT_MAX;
    dfs(1,1,mp[1][1]-'0',' ');
    cout<<ans1<<" "<<ans2<<"\n";
    return 0;
}