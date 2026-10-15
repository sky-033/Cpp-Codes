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
        lli n,m;
        cin>>n>>m;
        lli maxi=n*(n+1)/2;
        vll ans;
        set<lli> ans1;
        if(m>maxi || m<n) cout<<-1<<endl;
        else{
            lli root=m-n;
            if(root>=n){
                ans.push_back(n);
                ans1.insert(n);
            }
            else ans.push_back(root+1);
            lli rem=n-1;
            lli left=m-n;
            if(ans[0]==root+1){
                f(i,n){
                    if(i+1!=root+1) ans.push_back(i+1);
                }
            }
            else{
                rf(i,n-1){
                    if(i+1==left-rem+1 && rem>0 && left>0){
                        ans.push_back(i+1);
                        ans1.insert(i+1);
                        left=left-i-1;
                        rem--;
                    }
                    else if(left-rem+1>=i+1){
                        ans.push_back(i+1);
                        ans1.insert(i+1);
                        left=left-i-1;
                        rem--;
                    }
                }
                if(ans.size()!=n){
                    f(i,n){
                        if(ans1.find(i+1)==ans1.end()){
                            ans.push_back(i+1);
                            ans1.insert(i+1);
                        }
                    }
                }
                
                }
                if(ans[0]==root+1) cout<<root+1<<endl;
                else cout<<n<<endl;
                ff(1,n,1){
                    cout<<ans[i-1]<<" "<<ans[i]<<endl;
            }
            

        }
    }
    return 0;
}