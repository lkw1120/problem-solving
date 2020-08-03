#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
bool isCorrect;
ll N,ans;
bool canReverse(ll n) {
	while(n>0) {
		switch(n%10) {
			case 3:
			case 4:
			case 7:
				return false;
		}
		n/=10;
	}
	return true;
}
ll reverseNum(ll n) {
	ll m = 0;
	while(n>0) {
		m*=10;
		switch(n%10) {
			case 0:
			case 1:
			case 2:
			case 5:
			case 8:
				m+=(n%10);
				break;
			case 6:
				m+=9;
				break;
			case 9:
				m+=6;
				break;
		}
		n/=10;
	}
	return m;
}
bool isPrime(ll n) {
	for(ll i=2;i*i<=n;i++) {
		if(!(n%i)) return false;
	}
	return true;
}
int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>N;
	isCorrect = false;
	if(2 <= N && canReverse(N) && isPrime(N)
	&& isPrime(reverseNum(N))) {
		isCorrect = true;
	}
	if(isCorrect) {
		cout<<"yes"<<"\n";
	}
	else {
		cout<<"no"<<"\n";
	}
	return 0;
}