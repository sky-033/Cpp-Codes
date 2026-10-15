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
#define sor(x) sort(all(x))
#define setbits(x) __builtin_popcountll(x)
#define bitlen(x) 64-__builtin_clzll(x)
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
        stack<char> st1,st2;
        bool flag1=false,flag2=false;
        vll colors(n);
        f(i,n){
            if(s[i]=='('){
                if(!st2.empty()){              //   '()'->2
                    st2.pop();
                    colors[i]=2;
                    flag1=true;
                }
                else{
                    st1.push('(');           //  ')('->1
                    colors[i]=1;
                    flag2=true;
                }
            }
            else{
                if(!st1.empty()){
                    st1.pop();
                    colors[i]=1;
                }
                else{
                    st2.push(')');
                    colors[i]=2;
                }
            }
        }
        if(st1.empty() && st2.empty()){
            if(flag1 && flag2){
                cout<<2<<endl;
                fa(colors) cout<<it<<" ";
                cout<<endl;
            }
            else{
                cout<<1<<endl;
                fa(colors) cout<<1<<" ";
                cout<<endl;
            }

        }
        else cout<<-1<<endl;
    }
    return 0;
}