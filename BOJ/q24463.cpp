#include<bits/stdc++.h>
using namespace std;
vector<string> v;
bool visited[2002][2002];
int dX[4] = {0,1,0,-1};
int dY[4] = {1,0,-1,0};
int N,M;
void dfs(pair<int,int> start, int x, int y) {
	if((start.first != x && (y == 0 || y == M-1)) || 
	   (start.second != y && (x == 0 || x == N-1))) {
		for(int i=0;i<N;i++) {
			for(int j=0;j<M;j++) {
				if(v[i][j] == '.' && !visited[i][j]) v[i][j] = '@';	
			}
		}
		return ;
	}
	for(int i=0;i<4;i++) {
		int dx = x+dX[i];
		int dy = y+dY[i];
		if(0 <= dx && dx < N && 0 <= dy && dy < M &&
		   v[dx][dy] == '.' && !visited[dx][dy]) {
			visited[dx][dy] = true;
			dfs(start,dx,dy);
			visited[dx][dy] = false;
		}
	}
}
void solve() {
	pair<int,int> start;
	for(int i=0;i<N;i++) {
		if(v[i][0] == '.') {
			start = {i,0};
			break;
		}
		if(v[i][M-1] == '.') {
			start = {i,M-1};
			break;
		}
	}
	for(int j=0;j<M;j++) {
		if(v[0][j] == '.') {
			start = {0,j};
			break;
		}
		if(v[N-1][j] == '.') {
			start = {N-1,j};
			break;
		}
	}
	visited[start.first][start.second] = true;
	dfs(start,start.first,start.second);
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>N>>M;
	for(int i=0;i<N;i++) {
		string str;
		cin>>str;
		v.push_back(str);
	}
	for(int i=0;i<N;i++) {
		for(int j=0;j<M;j++) {
			visited[i][j] = (v[i][j] != '.');
		}
	}
	solve();
	for(auto str: v) {
		cout<<str<<"\n";	
	}
	return 0;
}