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
        vll a(n);
        unordered_map<lli,vll> freq;
        f(i,n){
            cin>>a[i];
            freq[a[i]].push_back(i+1);
        }
        bool flag=true;
        fa(freq){
            lli size=it.second.size();
        }
        if(freq.size()==1) flag=false;
        if(flag){
            cout<<"YES"<<endl;
            vector<pair<lli, vector<lli>>> vec(freq.begin(), freq.end());
            sort(vec.begin(), vec.end(), [](const auto &a1, const auto &b) {
                return a1.second.size() < b.second.size();
            });
            bool check=false;
            lli last=-1;
            auto itt=vec.begin();
            lli x=itt->second[0];
            if(itt->second.size()>1) check=true;
            itt++;
            for(;itt!=vec.end();itt++){
                fa(itt->second){
                    cout<<x<<" "<<it<<endl;
                    last=it;
                }
            }
            if(check){
                auto it=vec.begin();
                for(auto v:it->second){
                    if(x!=v) cout<<last<<" "<<v<<endl;
                }
            }
        }

        else cout<<"NO"<<endl;
    }
    return 0;
}