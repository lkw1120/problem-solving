#include<bits/stdc++.h>
using namespace std;
int arr[11][11] = {0};
bool isChecked[11] = {false};
int C,ans;
void solve(int n, int sum) {
	if(n == 11) {
		ans = max(ans,sum);
		return ;
	}
	for(int i=0;i<11;i++) {
		if(arr[n][i]!=0 && !isChecked[i]) {
			isChecked[i] = true;
			solve(n+1,sum+arr[n][i]);
			isChecked[i] = false;
		}
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>C;
	while(C--) {
		fill(&arr[0][0],&arr[10][11],0);
		for(int i=0;i<11;i++) {
			for(int j=0;j<11;j++) {
				cin>>arr[i][j];	
			}
		}
		ans = 0;
		solve(0,0);
		cout<<ans<<"\n";
	}
	return 0;	
}