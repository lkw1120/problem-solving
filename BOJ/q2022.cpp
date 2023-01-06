#include<bits/stdc++.h>
using namespace std;
double X,Y,C,ans;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>X>>Y>>C;
	double low,high,mid;
	low = 0;
	high = min(X,Y);
	while(0.0001 < high-low) {
		mid = (low+high)/2.0;
		double a = sqrt(X*X-mid*mid);
		double b = sqrt(Y*Y-mid*mid);
		double c = (a*b)/(a+b);
		if(c < C) {
			high = mid;
		}
		else {
			ans = mid;
			low = mid;
		}
	}
	cout<<fixed;
	cout.precision(3);
	cout<<ans<<"\n";
	return 0;	
}