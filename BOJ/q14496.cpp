#include<bits/stdc++.h>
#define MAX 1001
using namespace std;
vector<int> v[MAX];
queue<pair<int,int>> q;
bool visited[MAX] = {0};
int A,B,N,M,a,b,ans;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>A>>B;
	cin>>N>>M;
	for(int i=0;i<M;i++) {
		cin>>a>>b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	q.push({A,0});
	visited[A] = true;
	ans = -1;
	while(!q.empty()) {
		int n = q.front().first;
		int cnt = q.front().second;
		q.pop();
		if(n == B) {
			ans = cnt;
			break;
		}
		for(auto item: v[n]) {
			if(!visited[item]) {
				visited[item] = true;
				q.push({item,cnt+1});
			}
		}
	}
	cout<<ans<<"\n";
	return 0;	
}