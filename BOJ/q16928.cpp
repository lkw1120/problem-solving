#include<bits/stdc++.h>
#define MAX 101
using namespace std;
queue<pair<int,int>> q;
bool visited[MAX] = {0};
int arr[MAX] = {0};
int N,M,X,Y,ans;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>N>>M;
	for(int i=1;i<=N+M;i++) {
		cin>>X>>Y;
		arr[X] = Y;
	}
	q.push({1,0});
	visited[1] = true;
	ans = 0;
	while(!q.empty()) {
		int x = q.front().first;
		int cnt = q.front().second;
		q.pop();
		if(x == 100) {
			ans = cnt;
			break;
		}
		for(int i=1;i<=6;i++) {
			if(x+i < MAX && !visited[x+i]) {
				visited[x+i] = true;
				if(arr[x+i] != 0) {
					visited[arr[x+i]] = true;
					q.push({arr[x+i],cnt+1});
				}
				else {
					q.push({x+i,cnt+1});
				}
			}
		}
	}
	cout<<ans<<"\n";
	return 0;
}