#include<bits/stdc++.h>
using namespace std;
struct Ingredient {
	int p,f,s,v,c;
};
vector<Ingredient> v;
vector<bool> checked;
vector<pair<int,vector<int>>> res;
Ingredient M;
int N,sum;
void dfs(int n, vector<int> vv) {
	Ingredient tmp;
	tmp.p = tmp.f = tmp.s = tmp.v = tmp.c = 0; 
	for(auto item: vv) {
		tmp.p+=v[item].p;
		tmp.f+=v[item].f;
		tmp.s+=v[item].s;
		tmp.v+=v[item].v;
		tmp.c+=v[item].c;
	}
	if(M.p <= tmp.p && M.f <= tmp.f && M.s <= tmp.s && M.v <= tmp.v && M.c > tmp.c) {
		M.c = tmp.c;
		res.push_back({M.c,vv});
	}
	for(int i=n;i<N;i++) {
		if(!checked[i]) {
			checked[i] = true;
			vv.push_back(i);
			dfs(i,vv);
			vv.pop_back();
			checked[i] = false;
		}
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>N;
	cin>>M.p>>M.f>>M.s>>M.v;
	M.c = INT_MAX;
	v.resize(N);
	checked.resize(N);
	for(int i=0;i<N;i++) {
		cin>>v[i].p>>v[i].f>>v[i].s>>v[i].v>>v[i].c;
	}
	vector<int> vv;
	dfs(0,vv);
	if(!res.empty()) {
		sort(res.begin(),res.end(),less<>());
		cout<<res[0].first<<"\n";
		for(auto item: res[0].second) {
			cout<<item+1<<" ";
		}
		cout<<"\n";
	}
	else {
		cout<<-1<<"\n";	
	}
	return 0;	
}