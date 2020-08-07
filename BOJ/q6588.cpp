#include<bits/stdc++.h>
using namespace std;
const int MAX = 1000000;
bool isPrime[MAX];
bool flag;
int N,a,b;
void init() {
	fill(isPrime,isPrime+MAX,true);
	isPrime[0] = isPrime[1] = false;
	for(int i=2;i<MAX;i++) {
		if(!isPrime[i]) continue;
		for(int j=2*i;j<MAX;j+=i) {
			isPrime[j] = false;
		}
	}
}
int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	init();
	while(true) {
		cin>>N;
		if(!N) break;
		flag = false;
		a = 0;
		b = N;
		while (a <= b) {
			while (!isPrime[a]) a++;
			while (!isPrime[b]) b--;
			if (a + b == N) {
				flag = true;
				break;
			}
			else if (a + b > N) {
				b--;
			}
			else if (a + b < N) {
				a++;
			}
		}
		if(flag) {
			cout<<N<<" = "<<a<<" + "<<b<<"\n";
		}
		else {
			cout<<"Goldbach's conjecture is wrong."<<"\n";
		}
	}
	return 0;
}