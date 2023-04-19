#include<bits/stdc++.h>
using namespace std;
int dX[8] = {-2,-1,1,2,2,1,-1,-2};
int dY[8] = {1,2,2,1,-1,-2,-2,-1};
int arr[101][101] = {0};
int N,M,A,B,ans;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>N>>M>>A>>B;
	queue<pair<int,int>> q;
	q.push({1,1});
	ans = -1;
	while(!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		if(x == A && y == B) {
			ans = arr[x][y];
			break;
		}
		for(int i=0;i<8;i++) {
			int dx = x+dX[i];
			int dy = y+dY[i];
			if(0 < dx && dx <= N && 0 < dy && dy <= M && !arr[dx][dy]) {
				arr[dx][dy] = arr[x][y]+1;
				q.push({dx,dy});
			}
		}
	}
	if(ans < 0) {
		cout<<"NEVAR"<<"\n";
	}
	else {
		cout<<ans<<"\n";
	}
	return 0;
}