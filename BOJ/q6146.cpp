#include<bits/stdc++.h>
using namespace std;
int arr[1001][1001];
int dX[4] = {0,1,0,-1};
int dY[4] = {1,0,-1,0};
int X,Y,N,A,B,ans;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>X>>Y>>N;
	X+=500;
	Y+=500;
	for(int i=0;i<N;i++) {
		cin>>A>>B;
		A+=500;
		B+=500;
		arr[A][B] = -1;
	}
	queue<pair<pair<int,int>,int>> q;
	q.push({{500,500},0});
	arr[500][500] = -1;
	while(!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int d = q.front().second;
		q.pop();
		if(x == X && y == Y) {
			ans = d;
			break;
		}
		for(int i=0;i<4;i++) {
			int dx = x+dX[i];
			int dy = y+dY[i];
			if(0 <= dx && dx <= 1000 && 0 <= dy && dy <= 1000 && arr[dx][dy] >= 0) {
				arr[dx][dy] = -1;
				q.push({{dx,dy},d+1});
			}
		}
	}
	cout<<ans<<"\n";
	return 0;
}