#include<bits/stdc++.h>
using namespace std;
int dp[1000] = {0};
int N,ans;
string input;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>N;
	cin>>input;
	for(int i=1;i<N;i++) {
		if(input[i] == 'O') dp[i] = i*i;
	}
	for(int i=1;i<N;i++) {
		if(!dp[i]) continue;
		for(int j=i+1;j<N;j++) {
			if((input[i] == 'B' && input[j] == 'O') ||
			   (input[i] == 'O' && input[j] == 'J') ||
			   (input[i] == 'J' && input[j] == 'B')) {
				dp[j] = dp[j] != 0? min(dp[j],dp[i]+(j-i)*(j-i)): dp[i]+(j-i)*(j-i);
			}
		}
	}
	ans = dp[N-1] != 0? dp[N-1]: -1;
	cout<<ans<<"\n";
	return 0;	
}