#include<bits/stdc++.h>
#define INF 99999999
#define MAX 31
using namespace std;
char build[MAX][MAX][MAX];
int dist[MAX][MAX][MAX];
int dX[6] = {0,0,1,0,0,-1};
int dY[6] = {0,1,0,0,-1,0};
int dZ[6] = {1,0,0,-1,0,0};
tuple<int,int,int> start, escape;
int L,R,C,ans;
int dijkstra() {
    int x,y,z;
    priority_queue<pair<int,tuple<int,int,int>>> pq;
    z = get<0>(start);
    y = get<1>(start);
    x = get<2>(start);
    dist[x][y][z] = 0;
    pq.push({0,{z,y,x}});
    while(!pq.empty()) {
        int nowZ = get<0>(pq.top().second);
        int nowY = get<1>(pq.top().second);
        int nowX = get<2>(pq.top().second);
        int nowCost = -pq.top().first;
        pq.pop();
        if(nowCost > dist[nowZ][nowY][nowX]) continue;
        for(int i=0;i<6;i++) {
            int nextZ = nowZ+dZ[i];
            int nextY = nowY+dY[i];
            int nextX = nowX+dX[i];
            if(0 <= nextZ && nextZ < L
            && 0 <= nextY && nextY < R
            && 0 <= nextX && nextX < C
            && build[nextZ][nextY][nextX] != '#') {
                int nextCost = nowCost + 1;
                if(dist[nextZ][nextY][nextX] > nextCost) {
                    dist[nextZ][nextY][nextX] = nextCost;
                    pq.push({-nextCost,{nextZ,nextY,nextX}});
                }
            }
        }
    }
    z = get<0>(escape);
    y = get<1>(escape);
    x = get<2>(escape);
    return dist[z][y][x];
}
int main() {
    ios_base::sync_with_stdio(false);
    while(true) {
        cin>>L>>R>>C;
        if(!L && !R && !C) break;
        string str;
        for(int i=0;i<L;i++) {
            for(int j=0;j<R;j++) {
                cin>>str;
                for(int k=0;k<C;k++) {
                    dist[i][j][k] = INF;
                    build[i][j][k] = str[k];
                    if(str[k] == 'S') {
                        start = {i,j,k};
                    }
                    if(str[k] == 'E') {
                        escape = {i,j,k};
                    }
                }
            }
        }
        ans = dijkstra();
        if(ans != INF) {
            cout<<"Escaped in "<<ans<<" minute(s)."<<"\n";
        }
        else {
            cout<<"Trapped!"<<"\n";
        }
    }
    return 0;
}