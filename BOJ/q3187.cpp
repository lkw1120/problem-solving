#include<bits/stdc++.h>
using namespace std;
int dX[4] = {0,1,0,-1};
int dY[4] = {1,0,-1,0};
vector<string> town;
int R,C,V,K;
void solve(int x, int y) {
	int v,k;
	queue<pair<pair<int,int>,pair<int,int>>> q;
	if(town[x][y] == 'v') {
		q.push({{x,y},{1,0}});
	}
	if(town[x][y] == 'k') {
		q.push({{x,y},{0,1}});
	}
	town[x][y] = '#';
	v = k = 0;
	while(!q.empty()) {
		x = q.front().first.first;
		y = q.front().first.second;
		v += q.front().second.first;
		k += q.front().second.second;
		q.pop();
		for(int i=0;i<4;i++) {
			int dx = x+dX[i];
			int dy = y+dY[i];
			if((0 <= dx && dx < R) && (0 <= dy && dy < C) && town[dx][dy] != '#') {
				if(town[dx][dy] == 'v') {
					q.push({{dx,dy},{1,0}});
				}
				if(town[dx][dy] == 'k') {
					q.push({{dx,dy},{0,1}});
				}
				if(town[dx][dy] == '.') {
					q.push({{dx,dy},{0,0}});
				}
				town[dx][dy] = '#';
			}
		}
	}
	if(v < k) {
		K+=k;	
	}
	else {
		V+=v;
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>R>>C;
	for(int i=0;i<R;i++) {
		string input;
		cin>>input;
		town.push_back(input);
	}
	V = K = 0;
	for(int i=0;i<R;i++) {
		for(int j=0;j<C;j++) {
			if(town[i][j] == 'v' || town[i][j] == 'k') {
				solve(i,j);
			}
		}
	}
	cout<<K<<" "<<V<<"\n";
	return 0;	
}