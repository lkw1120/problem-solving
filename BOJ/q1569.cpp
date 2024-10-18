#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int>> v;
int N,X,Y,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>N;
    int minX,minY,maxX,maxY;
    minX = minY = INT_MAX;
    maxX = maxY = INT_MIN;
    for(int i=0;i<N;i++) {
        cin>>X>>Y;
        v.push_back({X,Y});
        minX = min(minX,X);
        minY = min(minY,Y);
        maxX = max(maxX,X);
        maxY = max(maxY,Y);
    }
    int len = max(maxX-minX,maxY-minY);
    if(maxX-minX < maxY-minY) {
        ans = maxY-minY;
        bool f1,f2;
        f1 = f2 = true;
        for(auto [x,y]: v) {
            if(y != maxY && y != minY && x != minX && x != minX+len) {
                f1 = false;
            }
            if(y != maxY && y != minY && x != maxX && x != maxX-len) {
                f2 = false;
            }
        }
        if(!f1 && !f2) {
            ans = -1;
        }
    }
    else if(maxX-minX > maxY-minY) {
        ans = maxX-minX;
        bool f1,f2;
        f1 = f2 = true;
        for(auto [x,y]: v) {
            if(x != maxX && x != minX && y != minY && y != minY+len) {
                f1 = false;
            }
            if(x != maxX && x != minX && y != maxY && y != maxY-len) {
                f2 = false;
            }
        }
        if(!f1 && !f2) {
            ans = -1;
        }
    }
    else {
        ans = maxX-minX;
        for(auto [x,y]: v) {
            if(x != minX && x != maxX && y != minY && y != maxY) {
                ans = -1;
                break;
            }
        }
    }
    cout<<ans<<"\n";
    return 0;
}