#include<bits/stdc++.h>
using namespace std;
priority_queue<pair<int,int>> pq;
int N,X;
int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>N;
	while(N--) {
		cin>>X;
		if(X == 0) {
			if(!pq.empty()) {
				cout<<-pq.top().second<<"\n";
				pq.pop();
			}
			else {
				cout<<0<<"\n";
			}
		}
		else {
			pq.push({-abs(X),-X});
		}
	}
	return 0;
}