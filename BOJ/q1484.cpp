#include<bits/stdc++.h>
#define MAX 200002
using namespace std;
int diff[MAX] = {0};
vector<int> v;
int G,l,r,sum;
void preload() {
	for(int i=1;i<MAX;i++) {
		diff[i] = i*2+1;	
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	preload();
	cin>>G;
	l = 1;
	r = 2;
	sum = 0;
	while(l < r && r <= MAX) {
		if(sum < G) {
			sum+=diff[r-1];
			r++;	
		}
		else {
			if(sum == G) {
				v.push_back(r-1);
			}
			sum-=diff[l];
			l++;
		}
	}
	if(v.size() > 0) {
		for(auto item: v) {
			cout<<item<<"\n";
		}
	}
	else {
		cout<<-1<<"\n";	
	}
	return 0;
}