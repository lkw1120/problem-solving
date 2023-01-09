#include<bits/stdc++.h>
using namespace std;
int dX[8] = {-2,-2,-1,-1,1,1,2,2};
int dY[8] = {-1,1,-2,2,-2,2,-1,1};
int arr[501][501] = {0};
int N,M,X,Y,A,B;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>N>>M;
	cin>>X>>Y;
	queue<pair<pair<int,int>,int>> q;
	bool visited[501][501] = {false};
	q.push({{X,Y},0});
	visited[X][Y] = true;
	while(!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int cnt = q.front().second;
		q.pop();
		arr[x][y] = cnt;
		for(int i=0;i<8;i++) {
			int dx = x+dX[i];
			int dy = y+dY[i];
			if(0 < dx && dx <= N && 0 < dy && dy <= N) {
				if(visited[dx][dy]) continue;
				visited[dx][dy] = true;
				q.push({{dx,dy},cnt+1});
			}
		}
	}
	while(M--) {
		cin>>A>>B;
		cout<<arr[A][B]<<" ";
	}
	cout<<"\n";
	return 0;	
}