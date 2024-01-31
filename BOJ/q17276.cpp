#include<bits/stdc++.h>
using namespace std;
int arr[500][500];
int T,N,D;
void rotate() {
	vector<int> v[4];
	for(int i=0;i<N;i++) {
		v[0].push_back(arr[i][i]);
		v[1].push_back(arr[i][N/2]);
		v[2].push_back(arr[N-i-1][i]);
		v[3].push_back(arr[N/2][i]);
	}
	for(int i=0;i<N;i++) {
		arr[i][N-i-1] = v[1][i];
		arr[N/2][i] = v[2][i];
		arr[i][i] = v[3][i];
		arr[i][N/2] = v[0][i];
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>T;
	while(T--) {
		cin>>N>>D;
		for(int i=0;i<N;i++) {
			for(int j=0;j<N;j++) {
				cin>>arr[i][j];	
			}
		}
		int R = D/45;
		if(R < 0) R+=8;
		for(int i=0;i<R;i++) {
			rotate();
		}
		for(int i=0;i<N;i++) {
			for(int j=0;j<N;j++) {
				cout<<arr[i][j]<<" ";
			}
			cout<<"\n";
		}
	}
	return 0;
}