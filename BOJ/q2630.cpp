#include<bits/stdc++.h>
using namespace std;
int arr[128][128] = {0};
int N,W,B;
void solve(int x, int y, int n) {
	int tmp = 0;
	for(int i=x;i<x+n;i++) {
		for(int j=y;j<y+n;j++) {
			if(arr[i][j]) tmp++;
		}
	}
	if(tmp == 0) W++;
	else if(tmp == n*n) B++;
	else {
		solve(x,y,n/2);
		solve(x,y+n/2,n/2);
		solve(x+n/2,y,n/2);
		solve(x+n/2,y+n/2,n/2);
	}
	return ;
}

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
	solve(0,0,N);
	cout<<W<<"\n";
	cout<<B<<"\n";
	return 0;
}