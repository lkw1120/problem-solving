#include<bits/stdc++.h>
using namespace std;
vector<int> v;
int dp[301] = {0};
int N,C,ans;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>N>>C;
	v.resize(C);
	for(int i=0;i<C;i++) {
	    cin>>v[i];
	}
	dp[0] = 1;
	for(int i=0;i<C;i++) {
	    for(int j=N;j>=0;j--) {
            if(dp[j]) {
                for(int k=1;;k++) {
                    if(N < j+v[i]*k) break;
                    dp[j+v[i]*k]+=dp[j];
                }
            }
	    }
	}
	ans = dp[N];
	cout<<ans<<"\n";
	return 0;	
}