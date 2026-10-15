#include<bits/stdc++.h>
using namespace std;
#define lli long long
#define vll vector<lli>
#define vvll vector<vector<lli>>
#define vp vector<pair<lli,lli>>
#define f(i,n) for(lli i=0;i<n;i++)
#define g(j,n) for(lli j=0;j<n;j++)
#define h(k,n) for(lli k=0;k<n;k++)
#define rf(i,n) for(lli i=n-1;i>=0;i--)
#define ff(a,b,c) for(lli i=a;i<b;i+=c)
#define fb(a,b,c) for(lli i=a-1;i>=b;i-=c)
#define fa(v) for (auto &it : v) 
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sor(x) sort(all(x))
#define rsor(x) sort(rall(x))
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
        lli ct=0;
        ff(0,n-3,1){
            if(s[i]=='1' && s[i+1]=='1' && s[i+2]=='0' && s[i+3]=='0'){
                ct++;
            }
        }
        lli q;
        cin>>q;
        f(i,q){
            lli indx;
            char v;
            cin>>indx>>v;
            if(n<4){
                s[indx-1]=v;
                cout<<"NO"<<endl;
                continue;
            }
            if(s[indx-1]!=v){
                lli beg=max(0LL,indx-1-3);
                lli end=min(indx-1,n-4);
                for(lli i=beg;i<=end;i++){
                    if(s[i]=='1' && s[i+1]=='1' && s[i+2]=='0' && s[i+3]=='0'){
                        ct--;
                    }
                }
                s[indx-1]=v;
                for(lli i=beg;i<=end;i++){
                    if(s[i]=='1' && s[i+1]=='1' && s[i+2]=='0' && s[i+3]=='0'){
                        ct++;
                    }
                }
            }
            if(ct>0) cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }
    }
    return 0;
}