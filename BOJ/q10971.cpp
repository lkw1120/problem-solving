#include<bits/stdc++.h>
using namespace std;
int arr[11][11] = {0};
bool visited[11] = {false};
int N,ans;
void tsp(int n, int sum, int cnt) {
	if(cnt == N) {
		if(arr[n][1]) {
			sum+=arr[n][1];
			ans = min(ans,sum);
		}
		return ;
	}
	visited[n] = true;
	for(int i=1;i<=N;i++) {
		if(!visited[i] && arr[n][i] && sum+arr[n][i] < ans) {
			tsp(i,sum+arr[n][i],cnt+1);
		}
	}
	visited[n] = false;
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>N;
	for(int i=1;i<=N;i++) {
		for(int j=1;j<=N;j++) {
			cin>>arr[i][j];
		}
	}
	ans = INT_MAX;
	
	tsp(1,0,1);
	cout<<ans<<"\n";
	return 0;	
}