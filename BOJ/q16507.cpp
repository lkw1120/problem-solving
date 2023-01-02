#include<bits/stdc++.h>
#define MAX 1001
typedef long long ll;
using namespace std;
ll photo[MAX][MAX] = {0};
ll R,C,Q,ans;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>R>>C>>Q;
	for(int i=1;i<=R;i++) {
		for(int j=1;j<=C;j++) {
			cin>>photo[i][j];
			photo[i][j]+=(photo[i-1][j]+photo[i][j-1]-photo[i-1][j-1]);
		}
	}
	while(Q--) {
		int a,b,c,d;
		cin>>a>>b>>c>>d;
		int tmp = (c-(a-1))*(d-(b-1));
		ans = (photo[c][d]-photo[a-1][d]-photo[c][b-1]+photo[a-1][b-1])/tmp;
		cout<<ans<<"\n";
	}
	return 0;
}