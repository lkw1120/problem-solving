#include<bits/stdc++.h>
using namespace std;
vector<int> v1,v2;
int N;
void hanoi(int n, int from, int by, int to) {
	if(n == 1) {
		cout<<from<<" "<<to<<"\n";
	}
	else {
		hanoi(n-1,from,to,by);
		cout<<from<<" "<<to<<"\n";
		hanoi(n-1,by,from,to);
	}
}
void multiply() {
	int sum,carry;
	sum = carry = 0;
	v2.clear();
	for(int i=v1.size()-1;i>=0;i--) {
		sum = v1[i]*2 + carry;
		carry = sum/10;
		sum = sum%10;
		v2.insert(v2.begin(),sum);
	}
	if(carry != 0) {
		v2.insert(v2.begin(),carry);
	}
	v1.clear();
	for(auto item: v2) {
		v1.push_back(item);
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>N;
	v1.push_back(1);
	for(int i=0;i<N;i++) {
		multiply();
	}
	v1[v1.size()-1]--;
	for(int i=v1.size()-1;i>0;i--) {
		if(v1[i] >= 0) {
			break;
		}
		else {
			v1[i-1]--;
		}
	}
	for(auto item: v1) {
		cout<<item;
	}
	cout<<"\n";
	if(N <= 20) {
		hanoi(N,1,2,3);
	}
	return 0;
}