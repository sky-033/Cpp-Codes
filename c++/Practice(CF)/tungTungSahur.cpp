#include<bits/stdc++.h>
using namespace std;
#define lli long long
#define vll vector<lli>
#define vvll vector<vector<lli>>
#define vp vector<pair<lli,lli>>
#define f(i,n) for(lli i=0;i<n;i++)
#define ff(a,b,c) for(lli i=a;i<b;i+=c)
#define fa(v) for (auto &it : v) 
const lli N=4e5+10; 

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        string p,s;
        cin>>p;
        cin>>s;
        lli p1=p.size();
        lli s1=s.size();
        vector<pair<char,lli>> freq,freq1;
        lli l=0,h=1;
        while(h<p1){
            if(p[l]==p[h]){
                h++;
            }
            else{
                freq.emplace_back(p[l],h-l);
                l=h;
                h++;
            }
        }
        freq.emplace_back(p[l],h-l);

        lli l1=0,h1=1;
        while(h1<s1){
            if(s[l1]==s[h1]){
                h1++;
            }
            else{
                freq1.emplace_back(s[l1],h1-l1);
                l1=h1;
                h1++;
            }
        }
        freq1.emplace_back(s[l1],h1-l1);
        bool flag=true;
        for(lli i=0;i<freq.size();i++){
            if(freq[i].first==freq1[i].first){
                if(freq1[i].second>=freq[i].second && freq1[i].second<= 2*freq[i].second) flag=true;
                else{
                    flag=false;
                    break;
                }
            }
            else{
                flag=false;
                break;
            }
        }
        if(freq.size()!=freq1.size()) flag=false;
        if(flag==true) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}