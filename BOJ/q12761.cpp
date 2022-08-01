#include<bits/stdc++.h>
#define MAX 100001
using namespace std;
bool visited[MAX] = {false};
queue<pair<int,int>> q;
int A,B,N,M,ans;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>A>>B>>N>>M;
	q.push({N,0});
	visited[N] = true;
	ans = INT_MAX;
	while(!q.empty()) {
		int n = q.front().first;
		int cnt = q.front().second;
		q.pop();
		if(n == M) {
			ans = cnt;
			break;
		}
		else {
			if(n+1 < MAX && !visited[n+1]) {
				visited[n+1] = true;
				q.push({n+1,cnt+1});
			}
			if(n-1 >= 0 && !visited[n-1]) {
				visited[n-1] = true;
				q.push({n-1,cnt+1});	
			}
			if(n+A < MAX && !visited[n+A]) {
				visited[n+A] = true;
				q.push({n+A,cnt+1});
			}
			if(n-A >= 0 && !visited[n-A]) {
				visited[n-A] = true;
				q.push({n-A,cnt+1});
			}
			if(n*A < MAX && !visited[n*A]) {
				visited[n*A] = true;
				q.push({n*A,cnt+1});	
			}
			if(n+B < MAX && !visited[n+B]) {
				visited[n+B] = true;
				q.push({n+B,cnt+1});
			}
			if( n-B >= 0 && !visited[n-B]) {
				visited[n-B] = true;
				q.push({n-B,cnt+1});
			}
			if(n*B < MAX && !visited[n*B]) {
				visited[n*B] = true;
				q.push({n*B,cnt+1});	
			}
		}
	}
	cout<<ans<<"\n";
	return 0;
}