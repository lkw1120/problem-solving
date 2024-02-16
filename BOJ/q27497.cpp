#include<bits/stdc++.h>
using namespace std;
deque<char> dq;
stack<int> st;
int N;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>N;
	while(N--) {
		int n;
		char ch;
		cin>>n;
		if(n != 3) {
			cin>>ch;
			st.push(n);
			if(n == 1) {
				dq.push_back(ch);
			}
			else {
				dq.push_front(ch);	
			}
		}
		else {
			if(!dq.empty()) {
				int m = st.top();
				st.pop();
				if(m == 1) {
					dq.pop_back();
				}
				else {
					dq.pop_front();
				}
			}
		}
	}
	if(dq.empty()) {
		cout<<0<<"\n";	
	}
	else {
		while(!dq.empty()) {
			cout<<dq.front();
			dq.pop_front();
		}
		cout<<"\n";
	}
	return 0;
}