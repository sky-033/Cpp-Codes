#include<bits/stdc++.h>
using namespace std;
#define lli long long
#define vll vector<lli>
#define vvll vector<vector<lli>>
#define vp vector<pair<lli,lli>>
#define f(i,n) for(lli i=0;i<n;i++)
#define g(j,n) for(lli j=0;j<n;j++)
#define rf(i,n) for(lli i=n-1;i>=0;i--)
#define ff(a,b,c) for(lli i=a;i<b;i+=c)
#define fb(a,b,c) for(lli i=a-1;i>=b;i-=c)
#define fa(v) for (auto &it : v) 
const lli N=2e5+10;
const lli M=1e9+7; 

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        lli n=s.size();
        unordered_map<char,lli> hsh;
        f(i,s.size()) hsh[s[i]]++;
        bool flag=true;
        fa(hsh){
            if(it.second>=2){
                lli indx1=-1,indx2=-1,mindistance=1e9;
                lli l=0,h=0;
                while(h<n){
                    if(s[h]==it.first){
                        if(l!=h&& s[l]==it.first && h-l+1<mindistance){
                            mindistance=h-l+1;
                            indx1=l,indx2=h;
                        }
                        l=h;
                        h++;
                    }
                    else{
                        h++;
                    }
                }
                unordered_set<char> check;
                for(lli i=indx1;i<=indx2;i++){
                    check.insert(s[i]);
                }
                if(check.size()<hsh.size()){
                    flag=false;
                    break;
                }
            }
        }
        cout<<(flag? "YES\n":"NO\n");
        
    }
    return 0;
}