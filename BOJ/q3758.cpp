#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> Pair;
int T,ans;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>T;
	while(T--) {
		int cnt[101] = {0};
		int stmp[101] = {0};
		int arr[101][101] = {0};
		vector<pair<Pair,Pair>> v;
		int N,K,ID,M;
		cin>>N>>K>>ID>>M;
		int id,num,score;
		for(int i=1;i<=M;i++) {
			cin>>id>>num>>score;
			arr[id][num] = max(arr[id][num],score);
			cnt[id]++;
			stmp[id] = i;
		}
		for(int i=1;i<=N;i++) {
			int sum = 0;
			for(int j=1;j<=K;j++) {
				sum+=arr[i][j];
			}
			v.push_back({Pair(sum,-cnt[i]),Pair(-stmp[i],i)});
		}
		sort(v.rbegin(),v.rend());
		for(int i=0;i<N;i++) {
			if(v[i].second.second == ID) {
				ans = i+1;
				break;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}