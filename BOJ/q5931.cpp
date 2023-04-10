#include<bits/stdc++.h>
using namespace std;
vector<string> v;
int arr[51][51] = {0};
int dX[4] = {0,1,0,-1};
int dY[4] = {1,0,-1,0};
int N,M,ans;
void labeling(int x, int y, char c) {
	queue<pair<int,int>> q;
	q.push({x,y});
	v[x][y] = c;
	while(!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();
		for(int i=0;i<4;i++) {
			int dx = x+dX[i];
			int dy = y+dY[i];
			if(0 <= dx && dx < N && 0 <= dy && dy < M && v[dx][dy] == 'X') {
				v[dx][dy] = c;
				q.push({dx,dy});
			}
		}
	}
}
void solve(int x, int y) {
	queue<pair<int,int>> q;
	q.push({x,y});
	while(!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();
		for(int i=0;i<4;i++) {
			int dx = x+dX[i];
			int dy = y+dY[i];
			if(0 <= dx && dx < N && 0 <= dy && dy < M && v[dx][dy] != 'a') {
				if(!arr[dx][dy] || arr[x][y]+1 < arr[dx][dy]) {
					arr[dx][dy] = arr[x][y]+1;
					q.push({dx,dy});
				}
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>N>>M;
	v.resize(N);
	for(int i=0;i<N;i++) {
		cin>>v[i];
	}
	char label = 'a';
	for(int i=0;i<N;i++) {
		for(int j=0;j<M;j++) {
			if(v[i][j] == 'X') {
				labeling(i,j,label++);
			}
		}
	}
	for(int i=0;i<N;i++) {
		for(int j=0;j<M;j++) {
			if(v[i][j] == 'a') {
				solve(i,j);	
			}
		}
	}
	ans = INT_MAX;
	for(int i=0;i<N;i++) {
		for(int j=0;j<M;j++) {
			if(v[i][j] == 'b') {
				ans = min(ans,arr[i][j]);
			}
		}
	}
	cout<<ans-1<<"\n";
	return 0;
}