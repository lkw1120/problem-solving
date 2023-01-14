#include<bits/stdc++.h>
using namespace std;
int dX[8] = {0,1,1,1,0,-1,-1,-1};
int dY[8] = {-1,-1,0,1,1,1,0,-1};
int arr[50][50] = {0};
bool checked[50][50] = {false};
queue<pair<pair<int,int>,int>> q;
int N,M,ans;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>N>>M;
	for(int i=0;i<N;i++) {
		for(int j=0;j<M;j++) {
			cin>>arr[i][j];
			if(arr[i][j]) {
				q.push({{i,j},0});
				checked[i][j] = true;
				arr[i][j] = 0;
			}
		}
	}
	ans = 0;
	while(!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int d = q.front().second;
		q.pop();
		for(int i=0;i<8;i++) {
			int dx = x+dX[i];
			int dy = y+dY[i];
			if(0 <= dx && dx < N && 0 <= dy && dy < M && !checked[dx][dy]){
				checked[dx][dy] = true;
				arr[dx][dy] = d+1;
				ans = max(arr[dx][dy],ans);
				q.push({{dx,dy},d+1});
			}
		}
	}
	cout<<ans<<"\n";
	return 0;	
}