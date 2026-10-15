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
        vll a(n);
        f(i,n) cin>>a[i];
        string s="L";
        lli l=1,h=n-1;
        lli lastindx=0;
        lli times=1;
        while(l<h){
            if(a[l]>a[lastindx] && a[h]>a[lastindx]){
                if(a[h]>a[l]){
                    s.push_back('R');
                    s.push_back('L');
                    lastindx=l;
                }
                else{
                    s.push_back('L');
                    s.push_back('R');
                    lastindx=h;
                }
            }
            else if(a[l]<a[lastindx] && a[h]<a[lastindx]){
                if(a[h]>a[l]){
                    s.push_back('L');
                    s.push_back('R');
                    lastindx=h;
                }
                else{
                    s.push_back('R');
                    s.push_back('L');
                    lastindx=l;
                }
            }
            else{
                if(times%2){
                    if(a[h]>a[l]){
                       s.push_back('R');
                       s.push_back('L');
                       lastindx=l; 
                    }
                    else{
                        s.push_back('L');
                        s.push_back('R');
                        lastindx=h;
                    }
                    times++;
                }
                else{
                    if(a[h]>a[l]){
                       s.push_back('L');
                       s.push_back('R');
                       lastindx=h; 
                    }
                    else{
                        s.push_back('R');
                        s.push_back('L');
                        lastindx=l;
                    }
                    times++;
                }
                
            }
            l++,h--;
        }
        if(l==h) s.push_back('L');
        cout<<s<<endl;
    }
    return 0;
}