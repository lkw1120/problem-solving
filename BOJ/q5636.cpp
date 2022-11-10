#include<bits/stdc++.h>
#define MAX 100001
using namespace std;
bool isPrime[MAX];
vector<int> v;
string input;
void preload() {
	fill(isPrime,isPrime+MAX,true);
	isPrime[0] = isPrime[1] = false;
	for(int i=2;i<=sqrt(MAX);i++) {
		if(!isPrime[i]) continue;
		for(int j=i*2;j<MAX;j+=i) {
			isPrime[j] = false;
		}
	}
	for(int i=MAX-1;i>=2;i--) {
		if(isPrime[i]) v.push_back(i);	
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	preload();
	while(true) {
		cin>>input;
		if(input == "0") break;
		for(auto prime: v) {
			if(input.find(to_string(prime)) != string::npos) {
				cout<<prime<<"\n";
				break;
			}
		}
	}
	return 0;
}