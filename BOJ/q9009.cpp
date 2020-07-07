#include<bits/stdc++.h>
using namespace std;
vector<int> fibo;
stack<int> ans;
int T,N,M;
void init() {
	fibo.push_back(0);
	fibo.push_back(1);
	for(int i=1;fibo[i]<1000000000;i++) {
		fibo.push_back(fibo[i]+fibo[i-1]);
	}
}
int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	init();
	cin>>T;
	while(T--) {
		cin>>N;
        while(N) {
            for(auto item: fibo) {
				if(item <= N) {
					M = item;
				}
            }
			N -= M;
            ans.push(M);
        }
		while(!ans.empty()) {
			cout<<ans.top()<<" ";
			ans.pop();
		}
		cout<<"\n";
	}
	return 0;
}