#include<bits/stdc++.h>
using namespace std;
char arr[1024][1024];
int N,M;
void star(int n, int x, int y) {
	n/=2;
	if(n == 0) {
		arr[x][y] = '*';
		return ;
	}
	star(n,x,y);
	star(n,x+n,y);
	star(n,x,y+n);
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>N;
	fill(&arr[0][0],&arr[1023][1024],' ');
	M = 1<<N;
	star(M,0,0);
	for(int i=0;i<M;i++) {
		for(int j=0;j<M-i;j++) {
			cout<<arr[i][j];
		}
		cout<<"\n";
	}
	return 0;
}