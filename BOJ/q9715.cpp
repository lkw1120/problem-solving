#include<bits/stdc++.h>
using namespace std;
vector<string> v;
int dX[4] = {0,1,0,-1};
int dY[4] = {1,0,-1,0};
int T,R,C,ans;
int height(int r, int c) {
    if(r < 0 || r >= R || c < 0 || c >= C) {
        return 0;
    }
    return v[r][c]-'0';
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>T;
    while(T--) {
        cin>>R>>C;
        v.assign(R,"");
        for(int i=0;i<R;i++) {
            cin>>v[i];
        }
        int sum = 0;
        for(int i=0;i<R;i++) {
            for(int j=0;j<C;j++) {
                int h = height(i,j);
                if(h == 0) continue;
                sum+=2;
                for(int k=0;k<4;k++) {
                    int dx = i+dX[k];
                    int dy = j+dY[k];
                    int nh = height(dx,dy);
                    if(h > nh) {
                        sum+=(h-nh);
                    }
                }
            }
        }
        ans = sum;
        cout<<ans<<"\n";
    }
    return 0;
}