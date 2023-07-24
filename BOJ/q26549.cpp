#include<bits/stdc++.h>
using namespace std;
vector<string> v;
int dX[4] = {0,1,0,-1};
int dY[4] = {1,0,-1,0};
int T,R,C,sec,cnt;
void solve(int x, int y) {
	queue<pair<int,int>> q;
	q.push({x,y});
	v[x][y] = '#';
	sec++;
	while(!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		cnt++;
		q.pop();
		for(int i=0;i<4;i++) {
			int dx = x+dX[i];
			int dy = y+dY[i];
			if(0 <= dx && dx < R && 0 <= dy && dy < C && v[dx][dy] == '.') {
				v[dx][dy] = '#';
				q.push({dx,dy});
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>T;
	while(T--) {
		cin>>R>>C;
		v.resize(R);
		for(int i=0;i<R;i++) {
			cin>>v[i];	
		}
		sec = cnt = 0;
		for(int i=0;i<R;i++) {
			for(int j=0;j<C;j++) {
				if(v[i][j] == '.') {
					solve(i,j);
				}
			}
		}
		if(1 < sec || 0 == sec) {
			cout<<sec<<" sections, ";
		}
		else {
			cout<<sec<<" section, ";
		}
		if(1 < cnt || 0 == cnt) {
			cout<<cnt<<" spaces";
		}
		else {
			cout<<cnt<<" space";
		}
		cout<<"\n";
		v.clear();
	}
	return 0;
}