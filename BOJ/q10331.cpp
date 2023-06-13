#include<bits/stdc++.h>
using namespace std;
string input;
int N,ans;
void firstRule(string str, int size) {
	stack<int> s;
	s.push(str[0]-'0');
	for(int i=2;i<size;i+=2) {
		if(str[i-1] == '*') {
			int tmp = s.top()*(str[i]-'0');
			s.pop();
			s.push(tmp);
		}
		else {
			s.push(str[i]-'0');	
		}
	}
	int n = 0;
	while(!s.empty()) {
		n+=s.top();
		s.pop();
	}
	if(n == N) {
		ans+=1;
	}
	return ;
}
void secondRule(string str, int size) {
	int n;
	n = str[0]-'0';
	for(int i=2;i<size;i+=2) {
		if(str[i-1] == '*') {
			n*=(str[i]-'0');
		}
		else {
			n+=(str[i]-'0');	
		}
	}
	if(n == N) {
		ans+=2;
	}
	return ;
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>input;
	cin>>N;
	ans = 0;
	firstRule(input,input.size());
	secondRule(input,input.size());
	if(ans == 1) {
		cout<<"M"<<"\n";
	}
	else if(ans == 2) {
		cout<<"L"<<"\n";
	}
	else if(ans == 3) {
		cout<<"U"<<"\n";
	}
	else {
		cout<<"I"<<"\n";
	}
	return 0;
}