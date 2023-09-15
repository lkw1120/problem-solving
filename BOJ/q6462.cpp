#include<bits/stdc++.h>
using namespace std;
int X,Y,N,A,B,ans;
int solve(vector<vector<int>> &v) {
	vector<int> dist(21,INT_MAX);
	queue<int> q;
	q.push(A);
	dist[A] = 0;
	while(!q.empty()) {
		int now = q.front();
		q.pop();
		if(now == B) {
			break;
		}
		for(auto next: v[now]) {
			if(dist[next] == INT_MAX) {
				dist[next] = dist[now]+1;
				q.push(next);
			}
		}
	}
	return dist[B];
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	for(int t=1;;t++) {
		vector<vector<int>> v(21);
		for(int i=1;i<20;i++) {
			cin>>X;
			if(cin.eof()) return 0;
			for(int j=0;j<X;j++) {
				cin>>Y;
				v[i].push_back(Y);
				v[Y].push_back(i);
			}
		}
		cout<<"Test Set #"<<t<<"\n";
		cin>>N;
		for(int i=1;i<=N;i++) {
			cin>>A>>B;
			cout<<setw(2)<<A<<" to "<<setw(2)<<B<<": "<<solve(v)<<"\n";
		}
		cout<<"\n";
	}
	return 0;
}