#include<bits/stdc++.h>
#define MAX 501
using namespace std;
int city[MAX][MAX] = {0};
int N,M,A,B,C,Q;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	cin>>N>>M;
	for(int i=0;i<M;i++) {
		cin>>A>>B;
		city[A][B] = city[B][A] = 1;
	}
	cin>>Q;
	for(int i=0;i<Q;i++) {
		cin>>C>>A>>B;
		if(C == 2) {
			city[A][B] = city[B][A] = 0;
		}
		else {
			city[A][B] = city[B][A] = 1;
		}
		vector<int> res(N,-1);
		res[0] = 0;
		vector<bool> visited(N+1,false);
		visited[1] = true;
		queue<pair<int,int>> q;
		q.push({1,0});
		while(!q.empty()) {
			int n = q.front().first;
			int cnt = q.front().second;
			q.pop();
			res[n-1] = cnt;
			for(int i=1;i<=N;i++) {
				if(city[n][i] && !visited[i]) {
					visited[i] = true;
					q.push({i,cnt+1});
				}
			}
		}
		for(auto item: res) {
			cout<<item<<" ";
		}
		cout<<"\n";
	}
    return 0;
}