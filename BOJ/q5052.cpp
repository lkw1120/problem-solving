#include<bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    map<string,bool> mp;
    vector<string> v;
    int T,N;
    cin>>T;
    for(int t=0;t<T;t++) {
        cin>>N;
        for(int n=0;n<N;n++) {
            string str;
            cin>>str;
            v.push_back(str);
        }
        sort(v.begin(),v.end());
        bool isConsistent = true;
        for(int i=0;i<v.size();i++) {
            for(int j=0;j<v[i].size();j++) {
                if(mp.find(v[i].substr(0,j)) != mp.end()) {
                    isConsistent = false;
                }
            }
            mp.insert({v[i],true});
        }
        if(isConsistent) 
            cout<<"YES"<<"\n";
        else
            cout<<"NO"<<"\n";
        mp.clear();
        v.clear();
    }
    return 0;
}