#include<bits/stdc++.h>
using namespace std;
int v[26][2];
char P,L,R;
int N;
void print(vector<char> res) {
	for(auto node: res) {
		cout<<node;
	}
	cout<<"\n";
}
vector<char> prefix() {
	vector<char> res;
	stack<int> st;
	int node;
	st.push(0);
	while(!st.empty()) {
		node = st.top();
		st.pop();
		if('A'+node != '.') {
			res.push_back('A'+node);
			st.push(v[node][1]);
			st.push(v[node][0]);
		}
	}
	return res;
}
vector<char> infix() {
	vector<char> res;
	stack<int> st;
	int node = 0;
	while(true) {
		while('A'+node != '.') {
			st.push(node);
			node = v[node][0];
		}
		if(!st.empty()) {
			node = st.top();
			st.pop();
			res.push_back('A'+node);
			node = v[node][1];
		}
		else {
			break;	
		}
	}
	return res;
}
vector<char> postfix() {
	vector<char> res;
	stack<int> st;
	int node;
	st.push(0);
	while(!st.empty()) {
		node = st.top();
		st.pop();
		if('A'+node != '.') {
			res.push_back('A'+node);
			st.push(v[node][0]);
			st.push(v[node][1]);
		}
	}
	reverse(res.begin(),res.end());
	return res;
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>N;
	for(int i=0;i<N;i++) {
		cin>>P>>L>>R;
		v[P-'A'][0] = L-'A';
		v[P-'A'][1] = R-'A';
	}
	print(prefix());
	print(infix());
	print(postfix());
	return 0;	
}