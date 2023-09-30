#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
ll dp[16] = {0};
ll N,ans;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	cin>>N;
	dp[1] = 2;
	for(int i=2;i<16;i++) {
		dp[i] = dp[i-1]*3;
	}
	ans = dp[N];
    cout<<ans<<"\n";
    return 0;
}