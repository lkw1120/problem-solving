#include<bits/stdc++.h>
using namespace std;
int dX[8] = {-2,-1,1,2,2,1,-1,-2};
int dY[8] = {1,2,2,1,-1,-2,-2,-1};
char arr[151][151];
int X,Y,A,B,C,D,ans;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>Y>>X;
	for(int i=1;i<=X;i++) {
		for(int j=1;j<=Y;j++) {
			cin>>arr[i][j];
			if(arr[i][j] == 'K') {
				A = i,B = j;	
			}
			if(arr[i][j] == 'H') {
				C = i,D = j;	
			}
		}
	}
	queue<pair<pair<int,int>,int>> q;
	q.push({{A,B},0});
	while(!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int d = q.front().second;
		q.pop();
		if(x == C && y == D) {
			ans = d;
			break;
		}
		for(int i=0;i<8;i++) {
			int dx = x+dX[i];
			int dy = y+dY[i];
			if(0 < dx && dx <= X && 0 < dy && dy <= Y && 
			   (arr[dx][dy] == '.' || arr[dx][dy] == 'H')) {
				arr[dx][dy] = '*';
				q.push({{dx,dy},d+1});
			}
		}
	}
	cout<<ans<<"\n";
	return 0;
}