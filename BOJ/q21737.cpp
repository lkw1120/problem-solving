#include<bits/stdc++.h>
using namespace std;
vector<string> v;
vector<int> res;
string input;
int N,M;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>N;
	cin>>input;
	M = input.size();
	v.push_back(string(1,input[0]));
	for(int i=1;i<M;i++) {
		if(input[i] == 'S') {
			v.push_back("-");
		}
		else if(input[i] == 'M') {
			v.push_back("*");
		}
		else if(input[i] == 'U') {
			v.push_back("/");
		}
		else if(input[i] == 'P') {
			v.push_back("+");
		}
		else if(input[i] == 'C') {
			v.push_back("C");
		}
		else {
			if('0' <= input[i-1] && input[i-1] <= '9') {
				v[v.size()-1]+=input[i];
			}
			else {
				v.push_back(string(1,input[i]));
			}
		}
	}
	int n = stoi(v[0]);
	for(int i=0;i<v.size();i++) {
		if(v[i] == "C") {
			res.push_back(n);
		}
		else {
			string op = v[i];
			if(op == "-" && i+1 < v.size()) {
				n-=stoi(v[i+1]);
			}
			else if(op == "*" && i+1 < v.size()) {
				n*=stoi(v[i+1]);
			}
			else if(op == "/" && i+1 < v.size()) {
				n/=stoi(v[i+1]);
			}
			else if(op == "+" && i+1 < v.size()) {
				n+=stoi(v[i+1]);
			}
		}
	}
	if(res.empty()) {
		cout<<"NO OUTPUT"<<"\n";	
	}
	else {
		for(auto item: res) {
			cout<<item<<" ";	
		}
		cout<<"\n";
	}
	return 0;
}