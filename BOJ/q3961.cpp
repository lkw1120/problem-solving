#include<bits/stdc++.h>
using namespace std;
string kbd[3] = {
    "qwertyuiop",
    "asdfghjkl",
    "zxcvbnm"
};
vector<pair<int,string>> v;
string str1,str2;
int T,I;
int find(char c1, char c2) {
    int x1,x2,y1,y2;
    for(int i=0;i<3;i++) {
        int size = kbd[i].size();
        for(int j=0;j<size;j++) {
            if(kbd[i][j] == c1) {
                x1 = i, y1 = j;
            }
            if(kbd[i][j] == c2) {
                x2 = i, y2 = j;
            }
        }
    }
    return abs(x2-x1)+abs(y2-y1);
}
int solve(string s1, string s2) {
    int size,dist;
    size = s1.size();
    dist = 0;
    for(int i=0;i<size;i++) {
        dist+=find(s1[i],s2[i]);
    }
    return dist;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>T;
    while(T--) {
        v.clear();
        cin>>str1>>I;
        for(int i=0;i<I;i++) {
            cin>>str2;
            v.push_back({solve(str1,str2),str2});
        }
        sort(v.begin(),v.end());
        for(auto item: v) {
            cout<<item.second<<" "<<item.first<<"\n";
        }
    }
    return 0;
}