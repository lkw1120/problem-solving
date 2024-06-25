#include<bits/stdc++.h>
using namespace std;
vector<string> v;
map<string,string> mp;
map<string,bool> visited;
string str1,str2;
vector<string> find(string name) {
    vector<string> vv;
    queue<string> q;
    q.push(name);
    visited[name] = true;
    while(!q.empty()) {
        vv.push_back(q.front());
        string next = mp[q.front()];
        q.pop();
        if(!visited[next]) {
            visited[next] = true;
            q.push(next);
        }
    }
    vv.push_back(name);
    return vv;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    for(int t=1;t<10;t++) {
        v.clear();
        mp.clear();
        visited.clear();
        while(true) {
            cin>>str1;
            if(str1 == "#") {
                if(v.empty()) {
                    exit(0);
                }
                break;
            }
            cin>>str2;
            mp[str1] = str2;
            v.push_back(str1);
        }
        cout<<"Party number "<<t<<"\n";
        for(auto item: v) {
            if(!visited[item]) {
                vector<string> vv = find(item);
                int size = vv.size();
                for(int i=0;i<size;i++) {
                    cout<<vv[i];
                    if(i+1 < size) {
                        cout<<" to ";
                    }
                    else {
                        cout<<".\n";
                    }
                }
            }
        }
        cout<<"\n";
    }
    return 0;
}