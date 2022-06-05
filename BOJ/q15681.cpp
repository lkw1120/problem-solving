#include<bits/stdc++.h>
#define MAX 100001
using namespace std;
vector<int> v[MAX];
bool visited[MAX] = {false};
int dp[MAX] = {0};
int N,R,Q,U,V,ans;
int solve(int n) {
	int cnt = 1;
	if(dp[n] != 0) return dp[n];
	for(auto item: v[n]) {
		if(!visited[item]) {
			visited[item] = true;
 			cnt += solve(item);
		}
	}
	dp[n] = cnt;
	return cnt;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>N>>R>>Q;
	for(int i=0;i<N-1;i++) {
		cin>>U>>V;
		v[U].push_back(V);
		v[V].push_back(U);
	}
	visited[R] = true;
	solve(R);
	for(int i=0;i<Q;i++) {
		cin>>U;
		cout<<dp[U]<<"\n";
	}
	return 0;
}