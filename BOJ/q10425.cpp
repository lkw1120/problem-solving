#include<bits/stdc++.h>
#define MAX 100001
using namespace std;
string fibo[MAX] = {""};
map<string,int> mp;
string input;
int T;
string add(string a, string b) {
	string res = "";
	int a_size = a.size();
	int b_size = b.size();
	int n,carry;
	n = carry = 0;
	for(int i=0;i<b_size;i++) {
		if(a_size <= i) {
			n = b[b_size-1-i]-'0';	
		}
		else {
			n = a[a_size-1-i]+b[b_size-1-i]-'0'-'0';
		}
		n+=carry;
		carry = n/10;
		res = to_string(n%10)+res;
	}
	if(carry) {
		res = '1'+res;
	}
	if(res.size() <= 10) {
		return res;
	}
	else {
		return res.substr(res.size()-10,10);
	}
}
void preload() {
	fibo[0] = "0";
	fibo[1] = "1";
	mp["0"] = 0;
	mp["1"] = 1;
	for(int i=2;i<MAX;i++) {
		fibo[i] = add(fibo[i-2],fibo[i-1]);
		mp[fibo[i]] = i;
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	preload();
	cin>>T;
	while(T--) {
		cin>>input;
		if(input.size() <= 10) {
			cout<<mp[input]<<"\n";
		}
		else {
			cout<<mp[input.substr(input.size()-10,10)]<<"\n";	
		}
	}
	return 0;	
}