#include<bits/stdc++.h>
using namespace std;
const int MAX = 31;
bool visit[MAX][MAX] = {false};
int dX[4] = {1,-1,0,0};
int dY[4] = {0,0,1,-1};
double prob[4] = {0};
int N;
double ans;
void dfs(int y, int x, double p, int cnt) {
    if(cnt == N) {
        ans+=p;
        return ;
    }
    for(int i=0;i<4;i++) {
        int nX = x+dX[i];
        int nY = y+dY[i];
        if(!visit[nY][nX]) {
            visit[nY][nX] = true;
            dfs(nY,nX,p*prob[i],cnt+1);
            visit[nY][nX] = false;
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>N;
    for(int i=0;i<4;i++) {
        cin>>prob[i];
        prob[i]/=100;
    }
    ans = 0;
    visit[15][15] = true;
    dfs(15,15,1,0);
    cout.precision(11);
    cout<<fixed;
    cout<<ans<<"\n";
    return 0;
}