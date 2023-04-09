#include<bits/stdc++.h>
using namespace std;
vector<int> v[1001];
vector<int> cow;
int checked[1001] = {0};
int K,N,M,A,B,cnt,ans;
void bfs(int n) {
	bool visited[1001] = {0};
	visited[n] = true;
	queue<int> q;
	q.push(n);
	while(!q.empty()) {
		n = q.front();
		cnt = max(cnt,checked[n]);
		q.pop();
		for(auto next: v[n]) {
			if(visited[next]) continue;
			checked[next]++;
            visited[next] = true;
			q.push(next);
		}
	}
	return ;
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>K>>N>>M;
	cow.resize(K);
	for(int i=0;i<K;i++) {
		cin>>cow[i];
	}
	for(int i=0;i<M;i++) {
		cin>>A>>B;
		v[A].push_back(B);
	}
	cnt = 0;
	for(int i=0;i<K;i++) {
		checked[cow[i]]++;
		bfs(cow[i]);
	}
	ans = 0;
	for(int i=1;i<=N;i++) {
		if(checked[i] == cnt) ans++;
	}
	cout<<ans<<"\n";
	return 0;	
}