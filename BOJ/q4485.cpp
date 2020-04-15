#include<bits/stdc++.h>
#define INF 99999999
#define MAX 126
using namespace std;
int dX[4] = {0,1,0,-1};
int dY[4] = {1,0,-1,0};
int graph[MAX][MAX];
int dist[MAX][MAX];
bool visited[MAX][MAX];
int N,cnt,ans;
int main(void) {
	ios_base::sync_with_stdio(false);
	cnt=1;
	while (true) {
        fill(&dist[0][0],&dist[MAX-1][MAX],INF);
        fill(&visited[0][0],&visited[MAX-1][MAX],false);
		cin>>N;
		if(N == 0) break;
		for (int i=0;i<N;i++) {
            for(int j=0;j<N;j++) {
                cin>>graph[i][j];
            }
        }
		priority_queue<pair<int,pair<int,int>>> pq;
		pq.push({0,{0,0}});
		visited[0][0] = true;

		while (!pq.empty()) {
			int nowY = pq.top().second.first;
			int nowX = pq.top().second.second;
			int nowCost = -pq.top().first;
			pq.pop();
			for (int i=0;i<4;i++) {
				int nextY = nowY + dY[i];
				int nextX = nowX + dX[i];
				int nextCost = nowCost + graph[nextY][nextX];
				if(0 <= nextY && nextY < N 
                && 0 <= nextX && nextX < N)
					if (!visited[nextY][nextX] 
                    && dist[nextY][nextX] > nextCost) {
						visited[nextY][nextX] = true;
						dist[nextY][nextX] = nextCost;
                        pq.push({ -nextCost,{nextY,nextX}});
					}
			}
		}
		cout<<"Problem "<<cnt++<<": "<<graph[0][0]+dist[N-1][N-1]<<"\n";
	}
	return 0;
}