#include<bits/stdc++.h>
using namespace std;
int dX[4] = {0,1,0,-1};
int dY[4] = {1,0,-1,0};
bool visited[1001][1001] = {false};
vector<string> v;
int R,C,X,Y,K;
void solve(int x, int y, int k) {
	queue<pair<int,int>> q;
	q.push({x,y});
	visited[x][y] = true;
	char c = v[x][y];
	v[x][y] = '0'+k;
	while(!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();
		for(int i=0;i<4;i++) {
			int dx = x+dX[i];
			int dy = y+dY[i];
			if(0 <= dx && dx < R && 0 <= dy && dy < C && 
			   v[dx][dy] == c && !visited[dx][dy]) {
				visited[dx][dy] = true;
				v[dx][dy] = '0'+k;
				q.push({dx,dy});
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>R>>C;
	v.resize(R);
	for(int i=0;i<R;i++) {
		cin>>v[i];
	}
	cin>>X>>Y>>K;
	solve(X,Y,K);
	for(int i=0;i<R;i++) {
		cout<<v[i]<<"\n";	
	}
	return 0;
}