#include<bits/stdc++.h>
using namespace std;
#define lli long long
#define vll vector<lli>
#define vvll vector<vector<lli>>
#define vp vector<pair<lli,lli>>
#define f(i,n) for(lli i=0;i<n;i++)
#define fa(v) for (auto &it : v) 

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        lli n;
        cin>>n;
        string a,b;
        cin>>a>>b;
        vector<int> a0,a1;
        f(i,a.size()){
            if(a[i]=='1') a1.push_back(i);
        }
        f(i,b.size()){
            if(b[i]=='0') a0.push_back(i);
        }
        lli odd0=0,odd1=0,even0=0,even1=0;
        f(i,a0.size()){
            if(a0[i]%2==0) even0++;
            else odd0++;
        }
        f(i,a1.size()){
            if(a1[i]%2==0) even1++;
            else odd1++;
        }
        if(odd0-even1>=0 && even0-odd1>=0) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}