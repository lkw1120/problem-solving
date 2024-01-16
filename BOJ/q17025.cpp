#include<bits/stdc++.h>
using namespace std;
const int MAX = 1007;
char arr[MAX][MAX];
bool visited[MAX][MAX];
int dX[4] = {0,1,0,-1};
int dY[4] = {1,0,-1,0};
vector<pair<int,int>> v;
int N;
void bfs(int x, int y) {
	visited[x][y] = true;
	queue<pair<int,int>> q;
	q.push({x,y});
	int a,b;
	a = b = 0;
	while(!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		a++;
		q.pop();
		for(int i=0;i<4;i++) {
			int dx = x+dX[i];
			int dy = y+dY[i];
			if(0 < dx && dx <= N && 0 < dy && dy <= N && arr[dx][dy] == '#' && !visited[dx][dy]) {
				visited[dx][dy] = true;
				q.push({dx,dy});
			}
			else if(arr[dx][dy] == '.') {
				b++;
			}
		}
	}
	v.push_back({a,b});
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	fill(&arr[0][0],&arr[MAX-1][MAX],'.');
	cin>>N;
	for(int i=1;i<=N;i++) {
		for(int j=1;j<=N;j++) {
			cin>>arr[i][j];	
		}
	}
	for(int i=1;i<=N;i++) {
		for(int j=1;j<=N;j++) {
			if(arr[i][j] == '#' && !visited[i][j]) {
				bfs(i,j);
			}
		}
	}
	int area,border;
	area = border = 0;
	sort(v.begin(),v.end(),[](pair<int,int> a, pair<int,int> b) {
		if(a.first != b.first) {
			return a.first > b.first;
		}
		else {
			return a.second < b.second;	
		}
	});
	area = v[0].first;
	border = v[0].second;
	cout<<area<<" "<<border<<"\n";
	return 0;
}