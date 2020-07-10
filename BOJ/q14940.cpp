#include<bits/stdc++.h>
using namespace std;
const int MAX = 1000;
int matrix[MAX][MAX] = {0};
int visit[MAX][MAX] = {false};
int dX[4] = {0,1,0,-1};
int dY[4] = {1,0,-1,0};
pair<int,int> sp;
int N,M;
void solve(int y, int x) {
	queue<pair<int,int>> q;
	matrix[y][x] = 0;
	q.push({y,x});
	visit[y][x] = true;
	int nY,nX;
	while(!q.empty()) {
		y = q.front().first;
		x = q.front().second;
		q.pop();
		for(int i=0;i<4;i++) {
			nY = y+dY[i];
			nX = x+dX[i];
			if(0 <= nY && nY < N && 0 <= nX && nX < M
			&& matrix[nY][nX] && !visit[nY][nX]) {
				visit[nY][nX] = true;
				matrix[nY][nX] = matrix[y][x]+1;
				q.push({nY,nX});
			}
		}
	}
	for(int i=0;i<N;i++) {
		for(int j=0;j<M;j++) {
			if(!visit[i][j] && matrix[i][j] == 1) {
				matrix[i][j] = -1;
			}
		}
	}
}
int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>N>>M;
	for(int i=0;i<N;i++) {
		for(int j=0;j<M;j++) {
			cin>>matrix[i][j];
			if(matrix[i][j] == 2) {
				sp = {i,j};
			}
		}
	}
	solve(sp.first,sp.second);
	for(int i=0;i<N;i++) {
		for(int j=0;j<M;j++) {
			cout<<matrix[i][j]<<" ";
		}
		cout<<"\n";
	}
	cout<<"\n";
	return 0;
}