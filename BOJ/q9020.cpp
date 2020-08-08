#include<bits/stdc++.h>
using namespace std;
const int MAX = 10001;
bool isPrime[MAX];
bool flag;
int T,N,a,b;
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
	cin>>T;
	while(T--) {
		cin>>N;
		flag = false;
		a = b = N/2;
		while (true) {
			while (!isPrime[a]) a--;
			while (!isPrime[b]) b++;
			if (a + b == N) break;
			else if (a + b > N) a--;
			else if (a + b < N) b++;
		}
		cout<<a<<" "<<b<<"\n";
	}
	return 0;
}