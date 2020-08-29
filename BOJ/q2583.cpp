#include<bits/stdc++.h>
using namespace std;
const int MAX = 101;
priority_queue<int> pq;
bool paper[MAX][MAX] = {false};
int dX[4] = {0,1,0,-1};
int dY[4] = {1,0,-1,0};
int M,N,K,ans;
int bfs(int x, int y) {
    queue<pair<int,int>> q;
    q.push({x,y});
    paper[x][y] = true;
    int sum = 1;
    while(!q.empty()) {
        x = q.front().first;
        y = q.front().second;
        q.pop();
        for(int i=0;i<4;i++) {
            if(0 <= x+dX[i] && x+dX[i] < M
            && 0 <= y+dY[i] && y+dY[i] < N
            && !paper[x+dX[i]][y+dY[i]]) {
                paper[x+dX[i]][y+dY[i]] = true;
                q.push({x+dX[i],y+dY[i]});
                sum++;
            }
        }
    }
    return sum*-1;
}
int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    cin>>M>>N>>K;
    for(int i=0;i<K;i++) {
        int x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;
        for(int k=y1;k<y2;k++) {
            for(int j=x1;j<x2;j++) {
                paper[k][j] = true;
            }
        }
    }
    for(int i=0;i<M;i++) {
        for(int j=0;j<N;j++) {
            if(!paper[i][j]) {
                pq.push(bfs(i,j));
            }
        }
    }
    ans = pq.size();
    cout<<ans<<"\n";
    while(!pq.empty()) {
        cout<<-pq.top()<<" ";
        pq.pop();
    }
    cout<<"\n";
	return 0;
}