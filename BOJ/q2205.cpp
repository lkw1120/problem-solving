#include<bits/stdc++.h>
#define MAX 10001
using namespace std;
int dp[MAX] = {0};
int N;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>N;
	for(int i=N;i>0;i--) {
		if(dp[i]) continue;
		for(int j=N;j>0;j--) {
			if(!((i+j)&(i+j-1)) && !dp[j]) {
				dp[i] = j;
				dp[j] = i;
				break;
			}
		}
	}
	for(int i=1;i<=N;i++) {
		cout<<dp[i]<<"\n";
	}	
	return 0;	
}