#include<bits/stdc++.h>
using namespace std;
int arr[10001] = {0};
bool visited[10001] = {0};
queue<pair<pair<int,int>,int>> q;
int N,A,B,ans;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>N;
	for(int i=1;i<=N;i++) {
		cin>>arr[i];	
	}
	cin>>A>>B;
	q.push({{A,arr[A]},0});
	visited[A] = true;
	ans = -1;
	while(!q.empty()) {
		int now = q.front().first.first;
		int step = q.front().first.second;
		int jump = q.front().second;
		q.pop();
		if(now == B) {
			ans = jump;
			break;
		}
		for(int i=now-step;i>=1;i-=step) {
			if(visited[i]) continue;
			visited[i] = true;
			q.push({{i,arr[i]},jump+1});
		}
		for(int i=now+step;i<=N;i+=step) {
			if(visited[i]) continue;
			visited[i] = true;
			q.push({{i,arr[i]},jump+1});
		}
	}
	cout<<ans<<"\n";
	return 0;	
}