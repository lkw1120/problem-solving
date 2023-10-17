#include<bits/stdc++.h>
using namespace std;
string S;
int N;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>N;
	while(N--) {
		cin>>S;
		list<char> lt;
		auto iter = lt.begin();
		int size = S.size();
		for(int i=0;i<size;i++) {
			if(S[i] == '<') {
				if(iter != lt.begin()) iter--;
			}
			else if(S[i] == '>') {
				if(iter != lt.end()) iter++;
			}
			else if(S[i] == '-') {
				if(iter != lt.begin()) {
					iter = lt.erase(--iter);	
				}
			}
			else {	
				lt.insert(iter,S[i]);
			}
		}
		for(auto item: lt) {
			cout<<item;
		}
		cout<<"\n";
	}
	return 0;
}