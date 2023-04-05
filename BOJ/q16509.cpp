#include<bits/stdc++.h>
using namespace std;
int arr[10][9] = {0};
int dX[8] = {2,3,3,2,-2,-3,-3,-2};
int dY[8] = {3,2,-2,-3,-3,-2,2,3}; 
int nX[8] = {1,2,2,1,-1,-2,-2,-1};
int nY[8] = {2,1,-1,-2,-2,-1,1,2};
int A,B,C,D,ans;
bool moveCheck(int x, int y, int n) {
    int nx = x+nX[n];
    int ny = y+nY[n];
    if (nx == C && ny == D) return false;
    if (nx+nX[n] == C && ny+nY[n] == D) return false;
    return true;
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>A>>B;
	cin>>C>>D;
	queue<pair<int,int>> q;
	q.push({A,B});
	ans = -1;
	while(!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		if(x == C && y == D) {
			ans = arr[x][y];
			break;
		}
		for(int i=0;i<8;i++) {
			int dx = x+dX[i];
			int dy = y+dY[i];
			if(dx < 0 || 10 <= dx || dy < 0 || 9 <= dy) continue;
			if(!arr[dx][dy] && moveCheck(x,y,i)) {
				arr[dx][dy] = arr[x][y]+1;
				q.push({dx,dy});	
			}
		}
	}
	cout<<ans<<"\n";
	return 0;
}