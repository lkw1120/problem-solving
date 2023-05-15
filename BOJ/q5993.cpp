#include<bits/stdc++.h>
using namespace std;
int dX[8] = {0,1,1,1,0,-1,-1,-1};
int dY[8] = {1,1,0,-1,-1,-1,0,1};
int arr[101][101] = {0};
vector<string> v;
int X,Y,R,C,ans;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>X>>Y>>R>>C;
	v.resize(Y);
	for(int i=Y-1;i>=0;i--) {
		cin>>v[i];
	}
	fill(&arr[0][0],&arr[100][101],INT_MAX);
	queue<pair<int,int>> q;
	q.push({C-1,R-1});
	v[C-1][R-1] = 'M';
	arr[C-1][R-1] = 0;
	while(!q.empty()) {
		int x = q.front().second;
		int y = q.front().first;
		q.pop();
		ans = max(ans,arr[y][x]);
		for(int i=0;i<8;i++) {
			int dx = x+dX[i];
			int dy = y+dY[i];
			if(0 <= dx && dx < X && 0 <= dy && dy < Y && v[dy][dx] == '.') {
				arr[dy][dx] = min(arr[dy][dx],arr[y][x]+1);
				v[dy][dx] = 'M';
				q.push({dy,dx});
			}
		}
	}
	cout<<ans<<"\n";
	return 0;
}