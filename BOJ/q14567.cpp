#include<bits/stdc++.h>
#define MAX 1001
using namespace std;
vector<int> v[MAX];
int indegree[MAX] = {0};
int dp[MAX] = {0};
int N,M,A,B;
void topologySort() {
	queue<int> q;
	for(int i=1;i<=N;i++) {
		if(indegree[i] == 0) {
			q.push(i);
			dp[i] = 1;
		}
	}
	for(int i=1;i<=N;i++) {
		if(q.empty()) return ;	
		int n = q.front();
		q.pop();
		for(auto next:v[n]) {
			if(--indegree[next] == 0) {
				dp[next] = max(dp[next],dp[n]+1);
				q.push(next);
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>N>>M;
	for(int i=0;i<M;i++) {
		cin>>A>>B;
		v[A].push_back(B);
		indegree[B]++;
	}
	topologySort();
	for(int i=1;i<=N;i++) {
		cout<<dp[i]<<" ";	
	}
	cout<<"\n";
	return 0;	
}