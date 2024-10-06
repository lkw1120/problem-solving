#include<bits/stdc++.h>
using namespace std;
vector<string> v;
string str;
vector<string> split(string str, char ch) {
    istringstream iss(str);
    string buf;
    vector<string> res;
    while (getline(iss, buf, ch)) {
        res.push_back(buf);
    }
    return res;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>str;
    v = split(str,':');
    if(v.size() == 9) {
        if(v[0] == "") v.erase(v.begin());
        else if(v[8] == "") v.erase(v.begin()+8);
    }
    while(v.size() < 8) {
        auto idx = find(v.begin(),v.end(),"")-v.begin();
        v.insert(v.begin()+idx,"");
    }
    for(int i=0;i<8;i++) {
        if(v[i].size() != 4) {
            if(v[i].size() == 0) {
                v[i] = "0000";
            }
            else {
                while(v[i].size() != 4) {
                    v[i] = "0"+v[i];
                }
            }
        }
    }
    for(int i=0;i<8;i++) {
        if(i) cout<<":";
        cout<<v[i];
    }
    cout<<"\n";
    return 0;
}