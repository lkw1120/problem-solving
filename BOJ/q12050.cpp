#include<bits/stdc++.h>
using namespace std;
int dX[4] = {0,1,0,-1};
int dY[4] = {1,0,-1,0};
bool visited[100][100] = {0};
vector<string> v;
int T,R,C,X,Y,Z,N;
char ch;
void bfs(int x, int y) {
	queue<pair<int,int>> q;
	q.push({x,y});
	visited[x][y] = true;
	while(!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();
		for(int i=0;i<4;i++) {
			int dx = x+dX[i];
			int dy = y+dY[i];
			if(0 <= dx && dx < R && 0 <= dy && dy < C &&
			   v[dx][dy] == '1' && visited[dx][dy] == false) {
				visited[dx][dy] = true;
				q.push({dx,dy});
			}
		}
	}
}
int check() {
	int cnt = 0;
	for(int i=0;i<R;i++) {
		for(int j=0;j<C;j++) {
			if(v[i][j] == '1' && !visited[i][j]) {
				bfs(i,j);
				cnt++;
			}
		}
	}
	return cnt;
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>T;
	for(int t=1;t<=T;t++) {
		v.clear();
		cin>>R>>C;
		v.resize(R);
		for(int i=0;i<R;i++) {
			cin>>v[i];	
		}
		cin>>N;
		cout<<"Case #"<<t<<":"<<"\n";
		for(int i=0;i<N;i++) {
			fill(&visited[0][0],&visited[99][100],false);
			cin>>ch;
			if(ch == 'M') {
				cin>>X>>Y>>Z;
				v[X][Y] = '0'+Z;
			}
			else {
				cout<<check()<<"\n";
			}
		}
	}
	return 0;
}