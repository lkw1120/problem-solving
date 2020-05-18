#include<bits/stdc++.h>
using namespace std;
map<string,string> p;
map<string,int> s;
int T,F;
string find(string a) {
    if(a == p[a]) return a;
    else return p[a] = find(p[a]);
}
bool check(string a, string b) {
    a = find(a);
    b = find(b);
    if(a == b) return true;
    else return false;
}
void merge(string a, string b) {
    a = find(a);
    b = find(b);
    if(a != b) {
        p[a] = b;
        s[b]+=s[a];
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>T;
    while(T--) {
        p.clear();
        s.clear();
        cin>>F;
        string a,b;
        for(int i=0;i<F;i++) {
            cin>>a>>b;
            if (p.count(a) == 0) {
				p[a] = a;
				s[a] = 1;
			}
			if(p.count(b) == 0) {
				p[b] = b;
				s[b] = 1;
			}
			merge(a,b);
			cout<<s[p[b]]<<"\n";
        }
    }
    return 0;
}