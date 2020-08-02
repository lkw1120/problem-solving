#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000000;
const int MAX = 40000;
map<int,int> a,b;
vector<int> prime;
bool isPrime[MAX];
ll N,M,n,m,ans;
void init() {
	fill(isPrime,isPrime+MAX,true);
	for(int i=2;i<MAX;i++) {
		if(!isPrime[i]) continue;
		prime.push_back(i);
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
	cin>>N;
	for(int i=0;i<N;i++) {
		cin>>n;
		for(int j=0;j<prime.size();j++) {
			if(n%prime[j] == 0) {
				a[prime[j]]++;
				n/=prime[j];
				j--;
			}
		}
		a[n]++;
	}
	cin>>M;
	for(int i=0;i<M;i++) {
		cin>>n;
		for(int j=0;j<prime.size();j++) {
			if(n%prime[j] == 0) {
				b[prime[j]]++;
				n/=prime[j];
				j--;
			}
		}
		b[n]++;
	}
	ans = 1;
	bool flag = false;
	for(auto item: a) {
		int now = item.first;
		if(!b[now]) continue;
		int cnt = min(a[now],b[now]);
		while(cnt--){
			ans*=now;
			if(ans > MOD) {
				flag = true;
				ans%=MOD;
			}
		}
	}
	if(flag) {
		cout.width(9);
		cout.fill('0');
	}
	cout<<ans<<"\n";
	return 0;
}