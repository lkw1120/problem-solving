#include<bits/stdc++.h>
using namespace std;
int arr[64][64] = {0};
bool visited[64][64] = {false};
int N;
string ans;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>N;
	for(int i=0;i<N;i++) {
		for(int j=0;j<N;j++) {
			cin>>arr[i][j];	
		}
	}
	queue<pair<int,int>> q;
	q.push({0,0});
	ans = "Hing";
	while(!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		if(x+1 == N && y+1 == N) {
			ans = "HaruHaru";
			break;
		}
		if(x+arr[x][y] < N && !visited[x+arr[x][y]][y]) {
			visited[x+arr[x][y]][y] = true;
			q.push({x+arr[x][y],y});	
		}
		if(y+arr[x][y] < N && !visited[x][y+arr[x][y]]) {
			visited[x][y+arr[x][y]] = true;
			q.push({x,y+arr[x][y]});	
		}
	}
	cout<<ans<<"\n";
	return 0;	
}