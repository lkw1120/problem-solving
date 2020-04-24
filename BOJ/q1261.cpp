#include<bits/stdc++.h>
#define INF 99999999
#define MAX 101
using namespace std;
priority_queue<pair<int,pair<int,int>>> pq;
int room[MAX][MAX] = {0};
int dist[MAX][MAX] = {0};
int dX[4] = {0,1,0,-1};
int dY[4] = {1,0,-1,0};
int N,M,ans;
int main() {
    ios_base::sync_with_stdio(false);
    cin>>N>>M;
    string str;
    for(int i=1;i<=M;i++) {
        cin>>str;
        for(int j=1;j<=N;j++) {
            room[i][j] = str[j-1]-'0';
            dist[i][j] = INF;
        }
    }
    pq.push({0,{1,1}});
    dist[1][1] = 0;
    while(!pq.empty()) {
        int nowX = pq.top().second.second;
        int nowY = pq.top().second.first;
        int nowCost = -pq.top().first;
        pq.pop();
        if(dist[nowY][nowX] < nowCost) continue;
        for(int i=0;i<4;i++) {
            int nextX = nowX+dX[i];
            int nextY = nowY+dY[i];
            if(0 < nextY && nextY <= M
            && 0 < nextX && nextX <= N) {
                int nextCost = nowCost + room[nextY][nextX];
                if(nextCost < dist[nextY][nextX]) {
                    dist[nextY][nextX] = nextCost;
                    pq.push({-nextCost,{nextY,nextX}});
                }
            }
        }
    }
    ans = dist[M][N];
    cout<<ans<<"\n";
    return 0;
}