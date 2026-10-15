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
        vll hsh(51,0);
        vector<set<lli>> store(n);
        f(i,n){
            lli k;
            cin>>k;
            g(j,k){
                lli x;
                cin>>x;
                store[i].insert(x);
                hsh[x]++;
            }
        }
        lli ct=0;
        set<lli> temp;
        fa(store){
            for(auto itt:it) temp.insert(itt);
        }
        ct=temp.size();
        lli ans=-1;
        ff(1,51,1){
            if(hsh[i]!=0){
                set<lli> checker;
                fa(store){
                    if(it.find(i)!=it.end()) continue;
                    for(auto itt:it){
                        checker.insert(itt);
                    }
                }
                if(checker.size()!=ct){
                    lli a1=checker.size();
                    ans=max(ans,a1);
                }
                
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}