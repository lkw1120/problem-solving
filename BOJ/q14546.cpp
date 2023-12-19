#include<bits/stdc++.h>
using namespace std;
vector<string> v;
int dX[4] = {0,1,0,-1};
int dY[4] = {1,0,-1,0};
int P,L,W,A,B,C,D,ans;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>P;
	while(P--) {
		v.clear();
		cin>>L>>W>>A>>B>>C>>D;
		v.resize(W);
		for(int i=W-1;i>=0;i--) {
			cin>>v[i];
		}
		A--,B--,C--,D--;
		queue<pair<int,int>> q;
		q.push({B,A});
		char ch = v[B][A];
		v[B][A] = '$';
		ans = 0;
		while(!q.empty()) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();
			if(x == D && y == C) {
				ans++;
				break;
			}
			for(int i=0;i<4;i++) {
				int dx = x+dX[i];
				int dy = y+dY[i];
				if(0 <= dx && dx < W && 0 <= dy && dy < L && v[dx][dy] == ch) {
					v[dx][dy] = '$';
					q.push({dx,dy});
				}
			}
		}
		if(ans) {
			cout<<"YES"<<"\n";	
		}
		else {
			cout<<"NO"<<"\n";	
		}
	}
	return 0;
}