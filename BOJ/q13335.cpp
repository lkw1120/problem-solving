#include<bits/stdc++.h>
using namespace std;
vector<int> v;
queue<pair<int,int>> q;
int N,W,L,input,timer,sum,ans;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>N>>W>>L;
	for(int i=0;i<N;i++) {
		cin>>input;
		v.push_back(input);
	}
	timer = 1, sum = 0;
	for(auto truck: v) {
		while(sum + truck > L) {
			while(timer < q.front().second + W) {
				timer++;
			}
			sum-=q.front().first;
			q.pop();
		}
		if(sum + truck <= L) {
			sum+=truck;
			q.push({truck,timer});
			timer++;
		}
	}
    while(!q.empty()) {
        ans = q.front().second;
        q.pop();
    }
	ans+=W;
    cout<<ans<<"\n"; 
	return 0;
}