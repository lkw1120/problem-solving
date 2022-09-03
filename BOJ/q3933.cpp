#include<bits/stdc++.h>
#define MAX 32768
using namespace std;
int dp[MAX][5] = {0};
int N,ans;
void preload() {
	for(int i=1;i*i<MAX;i++) {
		dp[i*i][1] = 1;
		for(int j=i*i;j<MAX;j++) {
            dp[j][2]+=dp[j-i*i][1];
            dp[j][3]+=dp[j-i*i][2];
            dp[j][4]+=dp[j-i*i][3];
        }
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	preload();
	while(true) {
		cin>>N;
		if(N == 0) break;
		ans = 0;
		for(int i=1;i<5;i++) {
			ans+=dp[N][i];
		}
		cout<<ans<<"\n";
	}
	return 0;	
}