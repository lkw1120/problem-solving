#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX = 1e5+1;
vector<pair<int,int>> v;
int arrX[MAX];
int arrY[MAX];
ll N,X,Y,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>N;
    for(int i=0;i<N;i++) {
        cin>>X>>Y;
        v.push_back({X,Y});
        arrX[X]++;
        arrY[Y]++;
    }
    ans = 0;
    for(auto [x,y]: v) {
        ans+=((ll)(arrX[x]-1)*(ll)(arrY[y]-1));
    }
    cout<<ans<<"\n";
    return 0;
}