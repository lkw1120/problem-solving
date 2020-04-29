#include<bits/stdc++.h>
#define INF 99999999
#define MAX 51
using namespace std;
int dX[4] = {0,1,0,-1};
int dY[4] = {1,0,-1,0};
int maze[MAX][MAX] = {0};
int dist[MAX][MAX] = {0};
bool visited[MAX][MAX] = {false};
int N,ans;
int main() {
    ios_base::sync_with_stdio(false);
    fill(&dist[0][0],&dist[MAX-1][MAX],INF);
    cin>>N;
    string str;
    for(int i=1;i<=N;i++) {
        cin>>str;
        for(int j=1;j<=N;j++) {
            maze[i][j] = str[j-1] == '0'? 1 : 0;
        }
    }
    priority_queue<pair<int,pair<int,int>>> pq;
    pq.push({0,{1,1}});
    dist[1][1] = 0;
    visited[1][1] = true;
    while(!pq.empty()) {
        int nowY = pq.top().second.first;
        int nowX = pq.top().second.second;
        int nowCost = -pq.top().first;
        pq.pop();
        if(dist[nowY][nowX] < nowCost) continue;
        for(int i=0;i<4;i++) {
            int nextY = nowY+dY[i];
            int nextX = nowX+dX[i];
            if(0 < nextY && nextY <= N
            && 0 < nextX && nextX <= N
            && !visited[nextY][nextX]) {
                int nextCost = nowCost + maze[nextY][nextX];
                if(dist[nextY][nextX] > nextCost) {
                    dist[nextY][nextX] = nextCost;
                    pq.push({-nextCost, {nextY,nextX}});
                }
            }
        }
    }
    ans = dist[N][N];
    cout<<ans<<"\n";
    return 0;
}