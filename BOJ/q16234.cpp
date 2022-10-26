#include<bits/stdc++.h>
using namespace std;
int arr[50][50] = {0};
bool visited[50][50] = {0};
int dX[4] = {0,1,0,-1};
int dY[4] = {1,0,-1,0};
int N,L,R,ans;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>N>>L>>R;
	for(int i=0;i<N;i++) {
		for(int j=0;j<N;j++) {
			cin>>arr[i][j];	
		}
	}
	ans = 0;
	while(true) {
		fill(&visited[0][0],&visited[49][50],false);
		bool flag = false;
		for(int i=0;i<N;i++) {
			for(int j=0;j<N;j++) {
				if(!visited[i][j]) {
					queue<pair<int,int>> q;
					vector<pair<int,int>> v;
					q.push({i,j});
					visited[i][j] = true;
					int sum = 0;
					while(!q.empty()) {
						int x = q.front().first;
						int y = q.front().second;
						sum+=arr[x][y];
						v.push_back({x,y});
						q.pop();
						for(int k=0;k<4;k++) {
							int dx = x + dX[k];
							int dy = y + dY[k];
							int diff = abs(arr[x][y]-arr[dx][dy]);
							if((0 <= dx && dx < N && 0 <= dy && dy < N) &&
							   (L <= diff && diff <= R && !visited[dx][dy])) {
								visited[dx][dy] = true;
								q.push({dx,dy});
							}
						}
					}
					if(sum > arr[i][j]) {
						sum = sum/v.size();
						for(auto& item: v) {
							arr[item.first][item.second] = sum;
						}
						flag = true;
					}
				}
			}
		}
		if(flag) {
			ans++;	
		}
		else {
			break;	
		}
	}
	cout<<ans<<"\n";
	return 0;	
}