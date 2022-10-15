#include<bits/stdc++.h>
#define MAX 200001
using namespace std;
vector<int> nodes[MAX];
int colors[MAX] = {0};
bool visited[MAX] = {false};
int N,A,B,ans;
void solve(int node, int color) {
	for(auto child: nodes[node]) {
		if(!visited[child]) {
			visited[child] = true;
			if(color != colors[child]) ans++;
			solve(child,colors[child]);
		}
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>N;
	for(int i=1;i<=N;i++) {
		cin>>colors[i];
	}
	for(int i=1;i<N;i++) {
		cin>>A>>B;
		nodes[A].push_back(B);
		nodes[B].push_back(A);
	}
	ans = 0;
	nodes[0].push_back(1);
	solve(0,0);
	cout<<ans<<"\n";
	return 0;	
}