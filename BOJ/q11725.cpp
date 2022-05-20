#include<bits/stdc++.h>
#define MAX 100001
using namespace std;
bool visited[MAX] = {false};
int parent[MAX] = {0};
vector<int> tree[MAX];
int N,A,B;
void dfs(int node) {
	visited[node] = true;
	for(int i=0;i<tree[node].size();i++) {
		int next = tree[node][i];
		if(!visited[next]) {
			parent[next] = node;
			dfs(next);
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>N;
	for(int i=1;i<N;i++) {
		cin>>A>>B;
		tree[A].push_back(B);
		tree[B].push_back(A);
	}
	dfs(1);
	for(int i=2;i<=N;i++) {
		cout<<parent[i]<<"\n";
	}
	return 0;
}