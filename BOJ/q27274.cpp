#include<bits/stdc++.h>
using namespace std;
string dp[1001];
int N;
string add(string a, string b) {
    int sum = 0;
	string res;
	while(!a.empty() || !b.empty() || sum) {
		if(!a.empty()) {
			sum+=a.back()-'0';
			a.pop_back();
		}
		if(!b.empty()) {
			sum+=b.back()-'0';
			b.pop_back();
		}
		res.push_back((sum%10)+'0');
		sum/=10;
	}
	reverse(res.begin(),res.end());
    return res;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    fill(dp,dp+1001,"0");
    dp[0] = "1";
    for(int i=1;i<=N;i+=2) {
        for(int j=i;j<=N;j++) {
            dp[j] = add(dp[j],dp[j-i]);
        }
    }
    cout<<dp[N]<<"\n";
    return 0;
}