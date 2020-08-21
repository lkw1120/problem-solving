#include<bits/stdc++.h>
using namespace std;
const int MAX = 1000001;
int dp[MAX] = {0};
int N,ans;
void solve(int x) {
	int cnt = 0;
	queue<pair<int,int>> q;
	q.push({x,cnt});
	while(!q.empty()) {
		x = q.front().first;
		cnt = q.front().second;
		q.pop();
		if(x == 1) {
			ans = min(ans,cnt);
		}
		else if(x > 1) {
			if(!(x%3) && !dp[x/3]) {
				dp[x/3] = x;		
				q.push({x/3,cnt+1});
			}
			if(!(x%2) && !dp[x/2]) {
				dp[x/2] = x;
				q.push({x/2,cnt+1});
			}
			if(!dp[x-1]) {
				dp[x-1] = x;
				q.push({x-1,cnt+1});
			}
		}
	}
}
int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>N;
	ans = INT_MAX;
	solve(N);
	cout<<ans<<"\n";
	stack<int> s;
	s.push(1);
	while(s.top() != N) {
		s.push(dp[s.top()]);
	}
	while(!s.empty()) {
		cout<<s.top()<<" ";
		s.pop();
	}
	cout<<"\n";
	return 0;
}