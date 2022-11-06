#include<bits/stdc++.h>
using namespace std;
int xs,ys,xe,ye,dx,dy;
int gcd(int a, int b) {
    if(b == 0) {
        return a;
    }
	else {
        return gcd(b,a%b);
    }
}
double dist(int a, int b) {
	return sqrt(pow(a-xs,2)+pow(b-ys,2));
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>xs>>ys;
	cin>>xe>>ye>>dx>>dy;
	int tmp = gcd(dx,dy);
	dx/=tmp;
	dy/=tmp;
	while(dist(xe,ye) > dist(xe+dx,ye+dy)) {
		xe+=dx;
		ye+=dy;
	}
	cout<<xe<<" "<<ye<<"\n";
	return 0;	
}