#include<bits/stdc++.h>
#define MAX 100001
using namespace std;
bool prime[MAX] = {false};
int T,N,A,B,ans;
void preload() {
	fill(prime,prime+MAX,true);
	for(int i=2;i<=sqrt(MAX);i++) {
		if(prime[i]) {
			for(int j=i+i;j<=MAX;j+=i) {
				prime[j] = false;
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	preload();
	cin>>T;
	while(T--) {
		cin>>N>>A>>B;
		bool flag = false;
		for(int i=A;i<=B;i++) {
			if(prime[i]) {
				flag = true;
				break;
			}
		}
		ans = INT_MAX;
		if(flag) {
			bool visited[MAX*10] = {false};
			queue<pair<int,int>> q;
			q.push({N,0});
			visited[N] = true;
			while(!q.empty()) {
				int n = q.front().first;
				int cnt = q.front().second;
				q.pop();
				if(A <= n && n <= B && prime[n]) {
					ans = min(ans,cnt);
					break;
				}
				if(0 < n/2 && !visited[n/2]) {
					visited[n/2] = true;
					q.push({n/2,cnt+1});
				}
				if(0 < n/3 && !visited[n/3]) {
					visited[n/3] = true;
					q.push({n/3,cnt+1});
				}
				if(n+1 < MAX && !visited[n+1]) {
					visited[n+1] = true;
					q.push({n+1,cnt+1});
				}
				if(2 <= n-1 && !visited[n-1]) {
					visited[n-1] = true;
					q.push({n-1,cnt+1});
				}
			}
		}
		else {
			ans = -1;
		}
		cout<<ans<<"\n";
	}
	return 0;	
}