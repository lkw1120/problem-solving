#include<bits/stdc++.h>
using namespace std;
const int MAX = 1e5+1;
vector<int> v[MAX];
int N,A,B,Q,T,K;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>N;
	for(int i=1;i<N;i++) {
		cin>>A>>B;
		v[A].push_back(B);
		v[B].push_back(A);
	}
	cin>>Q;
	while(Q--) {
		cin>>T>>K;
		if(T == 1 && v[K].size() == 1) {
			cout<<"no"<<"\n";
		}
		else {
			cout<<"yes"<<"\n";
		}
	}
	return 0;
}