#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> v;
vector<bool> visited;
vector<int> res;
int N,M,K,X,A,B;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>N>>M>>K>>X;
	v.resize(N+1);
	visited.resize(N+1);
	for(int i=0;i<M;i++) {
		cin>>A>>B;
		v[A].push_back(B);
	}
	queue<pair<int,int>> q;
	q.push({X,0});
	visited[X] = true;
	while(!q.empty()) {
		int x = q.front().first;
		int k = q.front().second;
		q.pop();
		if(k == K) {
			res.push_back(x);
		}
		for(auto next: v[x]) {
			if(visited[next]) continue;
			visited[next] = true;
			q.push({next,k+1});
		}
	}
	if(res.empty()) {
		cout<<-1<<"\n";
	}
	else {
		sort(res.begin(),res.end());
		for(auto item: res) {
			cout<<item<<"\n";	
		}
	}
	return 0;	
}