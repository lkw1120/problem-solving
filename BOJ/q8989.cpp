#include<bits/stdc++.h>
using namespace std;
typedef pair<double,string> Pair;
vector<Pair> v;
int T,A,B;
double find(int h, int m) {
    double dh,dm;
    dm = 6.0*m;
    dh = 30.0*(h%12) + 30.0/60*m;
    double deg = abs(dm-dh);
    if(180 < deg) {
        return 360-deg;
    }
    else {
        return deg;
    }
}
bool compare(Pair a, Pair b) {
    if(a.first == b.first) {
        string aa,bb;
        aa = a.second;
        bb = b.second;
        if(aa.substr(0,2) == bb.substr(0,2)) {
            return aa.substr(3,2) < bb.substr(3,2);
        }
        else {
            return aa.substr(0,2) < bb.substr(0,2);
        }
    }
    else {
        return a.first < b.first;
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>T;
    while(T--) {
        v.clear();
        for(int i=0;i<5;i++) {
            string str,tmp;
            cin>>str;
            int hh,mm;
            tmp = str.substr(0,2);
            hh = stoi(tmp);
            tmp = str.substr(3,2);
            mm = stoi(tmp);
            v.push_back({find(hh,mm),str});
        }
        sort(v.begin(),v.end(),compare);
        cout<<v[2].second<<"\n";
    }
    return 0;
}