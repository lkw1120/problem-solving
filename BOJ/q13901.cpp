#include<bits/stdc++.h>
using namespace std;
const int INF = 987654321;
int arr[1000][1000];
int dX[4] = {-1,1,0,0};
int dY[4] = {0,0,-1,1};
int cmd[4];
int R,C,K,X,Y;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>R>>C;
	cin>>K;
	for(int i=0;i<K;i++) {
		cin>>X>>Y;
		arr[X][Y] = INF;
	}
	cin>>X>>Y;
	for(int i=0;i<4;i++) {
		cin>>cmd[i];	
	}
	int x,y;
	x = X;
	y = Y;
	for(int i=0;;i++) {
		bool flag = true;
		for(int j=0;j<4;j++) {
			int dx = x+dX[j];
			int dy = y+dY[j];
			if(0 <= dx && dx < R && 0 <= dy && dy < C && !arr[dx][dy]) {
				flag = false;
			}
		}
		if(flag) {
			break;
		}
		int d = cmd[i%4]-1;
		int dx = x+dX[d];
		int dy = y+dY[d];
		while(0 <= dx && dx < R && 0 <= dy && dy < C && !arr[dx][dy]) {
			arr[x][y] = INF;
			x = dx;
			y = dy;
			dx+=dX[d];
			dy+=dY[d];
		}
	}
	cout<<x<<" "<<y<<"\n";
	return 0;
}