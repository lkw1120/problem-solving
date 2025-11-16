#include <bits/stdc++.h>
using namespace std;
typedef pair<string,int> Pair;
unordered_map<string,vector<Pair>> adj;
set<string> st;
int N,X;
bool compare(Pair a, Pair b) {
    if(a.second != b.second) {
        return a.second > b.second;
    }
    else {
        return a.first < b.first;
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    for(int tc=1;tc<=N;tc++) {
        adj.clear();
        st.clear();
        cin>>X;
        for(int i=0;i<X;i++) {
            string str1,str2;
            int n;
            cin>>str1>>str2>>n;
            adj[str1].push_back({str2,n});
            st.insert(str2);
        }
        unordered_map<string,int> age;
        queue<string> q;
        age["Ted"] = 100;
        q.push("Ted");
        while(!q.empty()) {
            string cur = q.front();
            q.pop();
            for(auto [a,b]: adj[cur]) {
                if(!age.count(a)) {
                    age[a] = age[cur]-b;
                    q.push(a);
                }
            }
        }
        vector<Pair> v;
        for(auto item: st) {
            v.push_back({item,age[item]});
        }
        sort(v.begin(),v.end(),compare);
        cout<<"DATASET "<<tc<<"\n";
        for(auto [a,b]: v) {
            cout<<a<<" "<<b<<"\n";
        }
    }
    return 0;
}