#include<bits/stdc++.h>
using namespace std;
string S,P;
int N,M,ans;
vector<int> getPi(string p) {
	int m,j;
	m = (int)p.size();
	j = 0;
    vector<int> pi(m, 0);
    for(int i=1;i<m;i++) {
        while(j > 0 && p[i] !=  p[j]) {
			j = pi[j-1];
		}
        if(p[i] == p[j]) {
			pi[i] = ++j;
		}
	}
	return pi;     
}        
vector<int> kmp(string s, string p) {
	vector<int> ans;
	auto pi = getPi(p);
	int n,m,j;
	n = (int)s.size();
	m = (int)p.size();
	j = 0;
    for(int i=0;i<n;i++) {
		while(j>0 && s[i] != p[j]) {
        	j = pi[j-1];
		}
        if(s[i] == p[j]) {
			if(j == m-1) {
				ans.push_back(i-m+1);
				j = pi[j];
			}
			else {
				j++;
			}
		}    
	}
	return ans;    
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>N>>M;
	cin>>S;
	P = "I";
	for(int i=0;i<N;i++) {
		P+="OI";
	}
	auto matched = kmp(S,P);
	ans = (int)matched.size();
	cout<<ans<<"\n";
	return 0;
}