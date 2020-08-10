#include<bits/stdc++.h>
using namespace std;
const int MAX = 31;
int fibo[MAX] = {0};
int D,K,A,B;
void init() {
	fibo[1] = 1;
	for(int i=2;i<MAX;i++) {
		fibo[i] = fibo[i-1]+fibo[i-2];
	}
}
int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	init();
	cin>>D>>K;
	A = 1;
	while((K-fibo[D-2]*A)%fibo[D-1]) A++;
	B = (K-fibo[D-2]*A)/fibo[D-1];
	cout<<A<<"\n";
	cout<<B<<"\n";
	return 0;
}