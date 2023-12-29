#include<bits/stdc++.h>
using namespace std;
const int MAX = 1e5+1;
int arr[MAX][3];
int N,ans;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>N;
	char ch;
	for(int i=1;i<=N;i++) {
		cin>>ch;
		if(ch == 'H') {
			arr[i][0] = arr[i-1][0]+1;
			arr[i][1] = arr[i-1][1];
			arr[i][2] = arr[i-1][2];
		}
		if(ch == 'P') {
			arr[i][0] = arr[i-1][0];
			arr[i][1] = arr[i-1][1]+1;
			arr[i][2] = arr[i-1][2];
		}
		if(ch == 'S') {
			arr[i][0] = arr[i-1][0];
			arr[i][1] = arr[i-1][1];
			arr[i][2] = arr[i-1][2]+1;
		}
	}
	ans = 0;
	for(int i=1;i<=N;i++) {
		ans = max(ans,arr[i][0]+(arr[N][1]-arr[i][1]));
		ans = max(ans,arr[i][0]+(arr[N][2]-arr[i][2]));
		ans = max(ans,arr[i][1]+(arr[N][0]-arr[i][0]));
		ans = max(ans,arr[i][1]+(arr[N][2]-arr[i][2]));
		ans = max(ans,arr[i][2]+(arr[N][0]-arr[i][0]));
		ans = max(ans,arr[i][2]+(arr[N][1]-arr[i][1]));
	}
	cout<<ans<<"\n";
	return 0;
}