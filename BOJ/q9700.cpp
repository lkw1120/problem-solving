#include<bits/stdc++.h>
using namespace std;
int dX[8] = {0,1,1,1,0,-1,-1,-1};
int dY[8] = {1,1,0,-1,-1,-1,0,1};
vector<string> v;
int T,N,ans;
void solve(int x, int y) {
	queue<pair<int,int>> q;
	q.push({x,y});
	v[x][y] = '0';
	while(!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();
		for(int i=0;i<8;i++) {
			int dx = x+dX[i];
			int dy = y+dY[i];
			if(0 <= dx && dx < N && 0 <= dy && dy < N && v[dx][dy] == '1') {
				v[dx][dy] = '0';
				q.push({dx,dy});
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	T = 0;
	while(true) {
		cin>>N;
		if(cin.eof()) break;
		v.resize(N);
		for(int i=0;i<N;i++) {
			cin>>v[i];
		}
		ans = 0;
		for(int i=0;i<N;i++) {
			for(int j=0;j<N;j++) {
				if(v[i][j] == '1') {
					ans++;
					solve(i,j);
				}
			}
		}
		cout<<"Case #"<<++T<<": "<<ans<<"\n";
		v.clear();
	}
	return 0;
}