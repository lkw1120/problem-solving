#include<bits/stdc++.h>
using namespace std;
vector<int> crane;
vector<int> box;
int N,M,n,m,ans;
int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>N;
	for(int i=0;i<N;i++) {
		cin>>n;
		crane.push_back(n);
	}
	cin>>M;
	for(int i=0;i<M;i++) {
		cin>>m;
		box.push_back(m);
	}
	sort(crane.begin(),crane.end(),greater<int>());
	sort(box.begin(),box.end(),greater<int>());
 
	if(crane[0] < box[0]) {
		ans = -1;
	}
	else {
		int cnt = 0;
		while (!box.empty()) { 
			int index = 0;
			for(int i=0;i<box.size();i++) {
				if (index == crane.size()) {
					break;
				}
                if (crane[index] >= box[i]) {
                    index++;
                    box.erase(box.begin()+i);
                    i--;
                }
			}
			cnt++;
		}
		ans = cnt;
	}
	cout<<ans<<"\n";
	return 0;
}