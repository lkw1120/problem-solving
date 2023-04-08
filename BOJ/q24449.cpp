#include<bits/stdc++.h>
using namespace std;
vector<string> v;
int arr[501][501] = {0};
int dX[4] = {0,1,0,-1};
int dY[4] = {1,0,-1,0};
int H,W,ans;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>H>>W;
	v.resize(H);
	for(int i=0;i<H;i++) {
		cin>>v[i];
	}
	queue<pair<int,int>> q;
	q.push({0,0});
	ans = -1;
	while(!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		if(x == H-1 && y == W-1) {
			ans = arr[x][y];
			break;
		}
		for(int i=0;i<4;i++) {
			int dx = x+dX[i];
			int dy = y+dY[i];
			if(0 <= dx && dx < H && 0 <= dy && dy < W
				&& v[dx][dy] != v[x][y] && !arr[dx][dy]) {
				arr[dx][dy] = arr[x][y]+1;
				q.push({dx,dy});
			}
		}
	}
	cout<<ans<<"\n";
	return 0;
}