#include<bits/stdc++.h>
#define MAX 10001
using namespace std;
bool visited[MAX] = {false};
vector<int> v[MAX];
int output[MAX] = {0};
int N,M,A,B,hack;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>N>>M;
	for(int i=0;i<M;i++) {
		cin>>A>>B;
		v[B].push_back(A);
	}
	hack = 0;
	for(int i=1;i<=N;i++) {
		fill(visited,visited+MAX,false);
		visited[i] = true;
		queue<int> q;
		q.push(i);
		int cnt = 0;
		while(!q.empty()) {
			int pc = q.front();
			q.pop();
			for(auto next: v[pc]) {
				if(!visited[next]) {
					visited[next] = true;
					cnt++;
					q.push(next);
				}
			}
		}
		output[i] = cnt;
		hack = max(hack,cnt);
	}
	for(int i=1;i<=N;i++) {
		if(output[i] == hack) {
			cout<<i<<" ";	
		}
	}
	cout<<"\n";
	return 0;	
}