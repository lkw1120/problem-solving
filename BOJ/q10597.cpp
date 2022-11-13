#include<bits/stdc++.h>
using namespace std;
vector<bool> check;
vector<int> v;
string input;
int N;
void solve(string str) {
	if(str.size() == 0) {
		for(int i=0;i<N;i++) {
			cout<<v[i]<<" ";	
		}
		cout<<"\n";
		exit(0);
	}
	else {
		int n = 0;
		string s = "";
		for(int i=0;i<str.size();i++) {
			s = s+str[i];
			n = stoi(s);
			if(n > N) break;
			if(n <= N && !check[n]) {
				v.push_back(n);
				check[n] = true;
				solve(str.substr(i+1));
				v.pop_back();
				check[n] = false;
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>input;
	int len = input.size();
	if(9 < len) {
		N = (len-9)/2+9;
	}
	else {
		N = len;
	}
	check.resize(N+1);
	solve(input);
	return 0;	
}