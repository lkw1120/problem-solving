#include<bits/stdc++.h>
using namespace std;
vector<int> a,b,c,d,res;
vector<pair<int,pair<int,int>>> x,y;
int A,B,C,D,X,Y;
int find(int n) {
	int l,r,mid;
	l = 0;
	r = Y-1;
	while(l <= r) {
		mid = (l+r)/2;
		if(y[mid].first < n) {
			l = mid+1;
		}
		else if(n < y[mid].first) {
			r = mid-1;
		}
		else break;
	}
	return mid;
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>A>>B>>C>>D;
	a.resize(A);
	b.resize(B);
	c.resize(C);
	d.resize(D);
	for(int i=0;i<A;i++) {
		cin>>a[i];
	}
	for(int i=0;i<B;i++) {
		cin>>b[i];
	}
	for(int i=0;i<C;i++) {
		cin>>c[i];
	}
	for(int i=0;i<D;i++) {
		cin>>d[i];
	}
	for(int i=0;i<A;i++) {
		for(int j=0;j<B;j++) {
			x.push_back({a[i]+b[j],{a[i],b[j]}});	
		}
	}
	X = x.size();
	for(int i=0;i<C;i++) {
		for(int j=0;j<D;j++) {
			y.push_back({c[i]+d[j],{c[i],d[j]}});
		}
	}
	Y = y.size();
	sort(y.begin(),y.end());
	for(int i=0;i<X;i++) {
		int j = find(-x[i].first);
		if(x[i].first+y[j].first == 0) {
			res.push_back(x[i].second.first);
			res.push_back(x[i].second.second);
			res.push_back(y[j].second.first);
			res.push_back(y[j].second.second);
			break;
		}
	}
	for(auto item: res) {
		cout<<item<<" ";	
	}
	cout<<"\n";
	return 0;
}