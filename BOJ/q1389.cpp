#include<bits/stdc++.h>
#define MAX 100+1
using namespace std;
int friends[MAX][MAX] = {0,};
int member[MAX] = {0,};
int M,N,ans;
void bfs(int a) {
    int checked[MAX] = {0,};
    queue<pair<int,int>> q;
    checked[a]++;
    q.push({a,0});
    while(!q.empty()) {
        pair<int,int> p = q.front();
        q.pop();
        member[a]+=p.second;
        for(int i=1;i<=N;i++) {
            if(friends[p.first][i] == 1 && checked[i] == 0) {
                checked[i]++;
                q.push({i,p.second+1});
            }
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin>>N>>M;
    int x,y;
    for(int i=0;i<M;i++) {
        cin>>x>>y;
        friends[x][y] = 1;
        friends[y][x] = 1;
    }
    for(int i=1;i<=N;i++) {
        bfs(i);
    }
    ans = 0;
    for(int i=1;i<=N;i++) {
        if(ans == 0 || member[ans] > member[i]) ans = i;
    }
    cout<<ans<<"\n";
    return 0;
}