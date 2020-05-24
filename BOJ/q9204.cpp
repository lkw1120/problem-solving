#include<bits/stdc++.h>
using namespace std;
const int SIZE = 8;
vector<pair<int,int>> v;
pair<int,int> X,Y;
int dX[4] = {1,1,-1,-1};
int dY[4] = {1,-1,1,-1};
char x;
int y;
pair<int,int> move() {
    int x = X.first;
    int y = X.second;
    for(int i=1;i<SIZE;i++) {
        for(int j=0;j<4;j++) {
            if(0 < x+i*dX[j] && x+i*dX[j] <= SIZE
            && 0 < y+i*dY[j] && y+i*dY[j] <= SIZE) {
                if(abs(Y.first-(x+i*dX[j])) == abs(Y.second-(y+i*dY[j]))) {
                    return {x+i*dX[j],y+i*dY[j]};
                }
            }
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T;
    cin>>T;
    while(T--) {
        v.clear();
        cin>>x>>y;
        X = {x-'A'+1,y};
        cin>>x>>y;
        Y = {x-'A'+1,y};
        int w = abs(X.first - Y.first);
        int h = abs(X.second - Y.second);
        if((w+h)%2 == 1) {
            cout<<"Impossible"<<"\n";
        }
        else {
            v.push_back(X);
            if(X != Y) {
                if(w != h) {
                    v.push_back(move());
                }
                v.push_back(Y);
            }
            cout<<v.size()-1<<" ";
            for(auto ans: v) {
                cout<<(char)(ans.first+'A'-1)<<" "<<ans.second<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}