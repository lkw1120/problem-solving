#include<bits/stdc++.h>
using namespace std;
int N,R,C,ans;
void solve(int y, int x, int size) {
    if (y == R && x == C) {
        cout<<ans<<"\n";
        return;
    }
    if(R < y + size && R >= y && C < x + size && C >= x) {
        solve(y,x,size/2);
        solve(y,x+size/2,size/2);
        solve(y+size/2,x,size/2);
        solve(y+size/2,x+size/2,size/2);
    }
    else {
        ans += size*size;
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	cout.tie(NULL);
    cin>>N>>R>>C;
    solve(0,0,(1<<N));
    return 0;
}