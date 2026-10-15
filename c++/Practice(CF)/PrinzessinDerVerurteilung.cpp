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
#define setbits(x) __builtin_popcountll(x)
const lli N=2e5+10;
const lli M=1e9+7; 

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        lli n;
        cin>>n;
        string s;
        cin>>s;
        bool flag=false;
        string ans="";
        for(lli i='a';i<='z';i++){
            if(s.find(i)==string::npos){
                ans+=i;
                flag=true;
                break;
            }
        }
        if(!flag){
            for(lli i='a';i<='z';i++){
                for(lli j='a';j<='z';j++){
                    string temp="";
                    temp+=i;
                    temp+=j;
                    if(s.find(temp)==string::npos){
                        ans=temp;
                        flag=true;
                        break;
                    }
                }
                if(flag) break;
            }
        }
        if(!flag){
            for(lli i='a';i<='z';i++){
                for(lli j='a';j<='z';j++){
                    for(lli k='a';k<='z';k++){
                        string temp="";
                        temp+=i;
                        temp+=j;
                        temp+=k;
                        if(s.find(temp)==string::npos){
                            ans=temp;
                            flag=true;
                            break;
                        }
                    }
                    if(flag) break;
                }
                if(flag) break;
            }

        }
        cout<<ans<<endl;

    }
    return 0;
}