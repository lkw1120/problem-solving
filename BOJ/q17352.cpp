#include<bits/stdc++.h>
using namespace std;
const int MAX = 300001;
vector<int> v[MAX];
vector<int> res;
bool visited[MAX] = {false};
int N,A,B;
int bfs(int n) {
	queue<int> q;
	q.push(n);
	visited[n] = true;
	while(!q.empty()) {
		n = q.front();
		q.pop();
		for(auto next: v[n]) {
			if(visited[next]) continue;
			visited[next] = true;
			q.push(next);
		}
	}
	return n;
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>N;
	for(int i=0;i<N-2;i++) {
		cin>>A>>B;
		v[A].push_back(B);
		v[B].push_back(A);
	}
	for(int i=1;i<=N;i++) {
		if(!visited[i]) {
			res.push_back(bfs(i));
		}
	}
	cout<<res[0]<<" "<<res[1]<<"\n";
	return 0;
}