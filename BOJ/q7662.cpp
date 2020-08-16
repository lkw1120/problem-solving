#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> P;
const int MAX = 1000001;
char op;
int T,K,N;
int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>T;
	while(T--) {	
		priority_queue<P,vector<P>,greater<P>> pq1;
		priority_queue<P,vector<P>,less<P>> pq2;
        bool visit[MAX] = {false};
		cin>>K;
		for(int i=0;i<K;i++) {
			cin>>op>>N;
			if(op == 'I') {
				pq1.push({N,i});
				pq2.push({N,i});
				visit[i] = true;
			}
			else {
				if(N == 1) {
					while(!pq2.empty() && !visit[pq2.top().second]) pq2.pop();
					if(!pq2.empty()) {
						visit[pq2.top().second] = false;
						pq2.pop();
					}
				}
				else {
					while(!pq1.empty() && !visit[pq1.top().second]) pq1.pop();
					if(!pq1.empty()) {
						visit[pq1.top().second] = false;
						pq1.pop();
					}
				}
			}
		}
		while(!pq2.empty() && !visit[pq2.top().second]) pq2.pop();
		while(!pq1.empty() && !visit[pq1.top().second]) pq1.pop();
		if(pq2.empty() && pq1.empty()) {
			cout<<"EMPTY"<<"\n";
		}
		else {
			cout<<pq2.top().first<<" "<<pq1.top().first<<"\n";
		}
	}	
	return 0;
}