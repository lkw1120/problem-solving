#include<bits/stdc++.h>
using namespace std;
const int MAX = 103;
char arr[MAX][MAX];
int dX[4] = {1,0,-1,0};
int dY[4] = {0,-1,0,1};
int N;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	fill(&arr[0][0],&arr[MAX-1][MAX],'#');
	cin>>N;
	int dir = 0;
	int x,y;
	x = y = 51;
	int a,b,c,d;
	a = b = 51;
	c = d = 51;
	arr[x][y] = '.';;
	for(int i=0;i<N;i++) {
		char op;
		cin>>op;
		if(op == 'R') {
			dir = (dir+1)%4;
		}
		else if(op == 'L') {
			dir = (dir+3)%4;
		}
		else {
			int dx = x+dX[dir];
			int dy = y+dY[dir];
			arr[dx][dy] = '.';
			x = dx;
			y = dy;
			a = min(a,x);
			b = min(b,y);
			c = max(c,x);
			d = max(d,y);
		}
	}
	for(int i=a;i<=c;i++) {
		for(int j=b;j<=d;j++) {
			cout<<arr[i][j];	
		}
		cout<<"\n";
	}
	return 0;
}