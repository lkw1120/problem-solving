#include<bits/stdc++.h>
using namespace std;
int arr[1024][1024] = {0};
int N,ans;
int solve(int x, int y) {
	vector<int> v;
	v.push_back(arr[x][y]);
	v.push_back(arr[x+1][y]);
	v.push_back(arr[x][y+1]);
	v.push_back(arr[x+1][y+1]);
	sort(v.begin(),v.end());
	return v[2];
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
	while(1 < N) {
		for(int i=0;i<N;i+=2) {
			for(int j=0;j<N;j+=2) {
				arr[i/2][j/2] = solve(i,j);
			}
		}
		N/=2;
	}
	ans = arr[0][0];
	cout<<ans<<"\n";
	return 0;
}