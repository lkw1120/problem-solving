#include<bits/stdc++.h>
using namespace std;
const int MAX = 1e4+1;
string word;
int N,ans;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>N;
	ans = 0;
	int a,b,c;
	a = b = c = 0;
	for(int i=0;i<N;i++) {
		cin>>word;
		int size = word.size();
		for(int i=0;i+1<size;i++) {
			if(word[i] == 'A' && word[i+1] == 'B') ans++;	
		}
		if(word[0] == 'B' && word[size-1] != 'A') b++;
		if(word[0] != 'B' && word[size-1] == 'A') a++;
		if(word[0] == 'B' && word[size-1] == 'A') c++;
	}
	if(0 < c) {
		ans+=c-1;
		if(0 < b) {
			ans++;
			b--;
		}
		if(0 < a) {
			ans++;
			a--;
		}
	}
	ans+=min(a,b);
	cout<<ans<<"\n";
	return 0;
}