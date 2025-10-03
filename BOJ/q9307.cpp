#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string formatter(double n) {
    ll cents = llround(n*100.0);
    ll dollars = cents/100;
    int cent = int(cents%100);
    string str1 = to_string(dollars);
    int size = str1.size();
    for(int i=size-3;i>0;i-=3) {
        str1.insert(i, ",");
    }
    string str2 = to_string(cent);
    if(str2.size() < 2) {
        str2 = "0"+str2;
    }
    return str1+"."+str2;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    while(1) {
        double c1,c2,c3;
        cin>>c1;
        if(c1 == -1) break;
        int N;
        cin>>c2>>c3>>N;
        vector<double> v = {c1,c2,c3};
        for(int i=3;i<N;i++) {
            double next = (v[i-3]*v[i-2])/v[i-1];
            next = round(next*100.0)/100.0;
            v.push_back(next);
        }
        string ans = formatter(v[N-1]);
        cout<<"Month "<<N<<" cost: $"<<ans<<"\n";
    }
    return 0;
}