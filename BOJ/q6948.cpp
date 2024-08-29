#include<bits/stdc++.h>
using namespace std;
map<char,vector<char>> mp;
set<char> st,visited;
vector<char> v;
char c1,c2;
string str;
int N;
void find(char ch) {
    visited.insert(ch);
    if('A' <= ch && ch <= 'Z') {
        for(auto item: mp[ch]) {
            if(!visited.count(item)) {
                find(item);
            }
        }
    }
    else {
        v.push_back(ch);
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>N;
    for(int i=0;i<N;i++) {
        cin>>c1>>str>>c2;
        mp[c1].push_back(c2);
        st.insert(c1);
        if('A' <= c2 && c2 <= 'Z') {
            st.insert(c2);
        }
    }
    for(auto node: st) {
        visited.clear();
        v.clear();
        find(node);
        sort(v.begin(),v.end());
        int size = v.size();
        cout<<node<<" = {";
        for(int i=0;i<size;i++) {
            if(i != 0) cout<<",";
            cout<<v[i];
        }
        cout<<"}"<<"\n";
    }
    return 0;
}