#include<bits/stdc++.h>
using namespace std;
int T,N,M;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>T;
	while(T--) {
		cin>>N>>M;
		cout<<1<<"\n";
		for(int i=0;i<M;i++) {
			cout<<"("<<0<<","<<i<<")"<<"\n";
		}
		for(int i=M-1;i>=0;i--) {
			if((M-1)%2 == i%2) {
				for(int j=1;j<N;j++) {
					cout<<"("<<j<<","<<i<<")"<<"\n";
				}
			}
			else {
				for(int j=N-1;j>0;j--) {
					cout<<"("<<j<<","<<i<<")"<<"\n";
				}
			}
		}
	}
	return 0;
}