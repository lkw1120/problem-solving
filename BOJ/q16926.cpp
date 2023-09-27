#include<bits/stdc++.h>
using namespace std;
int arr[300][300] = {0};
int N,M,R;
void rotate() {
	for(int i=0;i<min(N,M)/2;i++) {
		int n = N-i-1;
		int m = M-i-1;
		int tmp = arr[i][i];
		for(int j=i;j<m;j++) {
			arr[i][j] = arr[i][j+1];
		}
		for(int j=i;j<n;j++) {
			arr[j][m] = arr[j+1][m];
		}
		for(int j=m;j>i;j--) {
			arr[n][j] = arr[n][j-1];
		}
		for(int j=n;j>i;j--) {
			arr[j][i] = arr[j-1][i];
		}
		arr[i+1][i] = tmp;
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>N>>M>>R;
	for(int i=0;i<N;i++) {
		for(int j=0;j<M;j++) {
			cin>>arr[i][j];	
		}
	}
	while(R--) {
		rotate();
	}
	for(int i=0;i<N;i++) {
		for(int j=0;j<M;j++) {
			cout<<arr[i][j]<<" ";
		}
		cout<<"\n";
	}
	return 0;
}