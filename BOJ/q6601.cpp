#include<bits/stdc++.h>
using namespace std;
int dX[8] = {-2,-1,1,2,2,1,-1,-2};
int dY[8] = {1,2,2,1,-1,-2,-2,-1};
string A,B;
int ans;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	while(true) {
		cin>>A>>B;
		if(cin.eof()) break;
		int arr[8][8] = {0};
		int a,b,c,d;
		a = A[0]-'a';
		b = A[1]-'1';
		c = B[0]-'a';
		d = B[1]-'1';
		queue<pair<int,int>> q;
		q.push({a,b});
		while(!q.empty()) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();
			if(x == c && y == d) {
				ans = arr[x][y];
				break;
			}
			for(int i=0;i<8;i++) {
				int dx = x+dX[i];
				int dy = y+dY[i];
				if(0 <= dx && dx < 8 && 0 <= dy && dy < 8 && !arr[dx][dy]) {
					arr[dx][dy] = arr[x][y]+1;
					q.push({dx,dy});
				}
			}
		}
		cout<<"To get from "<<A<<" to "<<B<<" takes "<<ans<<" knight moves."<<"\n";
	}
	return 0;
}