#include<bits/stdc++.h>
using namespace std;
const int MAX = 10001;
bool prime[MAX];
bool check[MAX];
int arr[1001];
int P,T,N,M,ans;
void init() {
	fill(prime,prime+MAX,true);
	prime[0] = prime[1] = false;
	for(int i=2;i*i<MAX;i++) {
		if(prime[i]) {
			for(int j=2;i*j<MAX;j++) {
				prime[i*j] = false;	
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	init();
	cin>>P;
	while(P--) {
		cin>>T>>M;
		N = M;
		bool flag = true;
		if(prime[N]) {
			fill(check,check+MAX,false);
			while(1 < N) {
				check[N] = true;
				int sum = 0;
				while(N) {
					sum+=pow(N%10,2);
					N/=10;
				}
				N = sum;
				if(check[N]) {
					flag = false;
					break;
				}
				else {
					check[N] = true;	
				}
			}
		}
		else {
			flag = false;	
		}
		cout<<T<<" "<<M<<" ";
		if(flag) {
			cout<<"YES"<<"\n";	
		}
		else {
			cout<<"NO"<<"\n";	
		}
	}
	return 0;
}