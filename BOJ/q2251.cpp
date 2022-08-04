#include<bits/stdc++.h>
#define MAX 201
using namespace std;
bool check[3][MAX] = {false};
vector<int> v;
int A,B,C;
void solve(int a, int b, int c) {
	if(check[0][a] && check[1][b] && check[2][c]) {
		return ;	
	}
	check[0][a] = check[1][b] = check[2][c] = true;
	if(a == 0) {
		v.push_back(c);
	}
	if(a < A && b > 0) {
		if(A-a > b) {
			solve(a+b,0,c);
		}
		else {
			solve(A,b-(A-a),c);
		}
	}
	if(a > 0 && b < B) {
		if(B-b > a) {
			solve(0,a+b,c);
		}
		else {
			solve(a-(B-b),B,c);
		}
	}
	if(a < A && c > 0) {
		if(A-a > c) {
			solve(a+c,b,0);
		}
		else {
			solve(A,b,c-(A-a));
		}
	}
	if(a > 0 && c < C) {
		if(C-c > a) {
			solve(0,b,a+c);
		}
		else {
			solve(a-(C-c),b,C);
		}
	}
	if(b < B && c > 0) {
		if(B-b > c) {
			solve(a,b+c,0);
		}
		else {
			solve(a,B,c-(B-b));
		}
	}
	if(b > 0 && c < C) {
		if(C-c > b) {
			solve(a,0,b+c);
		}
		else {
			solve(a,b-(C-c),C);
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>A>>B>>C;
	solve(0,0,C);
	sort(v.begin(),v.end());
	for(auto item: v) {
		cout<<item<<" ";	
	}
	cout<<"\n";
	return 0;	
}