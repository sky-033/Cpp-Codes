#include<bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
using namespace std;
#define lli long long
#define vll vector<lli>
#define vvll vector<vector<lli>>
#define vp vector<pair<lli,lli>>
#define f(i,n) for(lli i=0;i<n;i++)
#define rf(i,n) for(lli i=n-1;i>=0;i--)
#define ff(a,b,c) for(lli i=a;i<b;i+=c)
#define fb(a,b,c) for(lli i=a-1;i>=b;i-=c)
#define fa(v) for (auto &it : v) 
#define all(x) (x).begin(), (x).end()
#define sor(x) sort(all(x))
#define setbits(x) __builtin_popcountll(x)
#define bitlen(x) 64-__builtin_clzll(x)
// template <typename T>using ordered_multiset = tree<T,null_type,less_equal<T>,rb_tree_tag tree_order_statistics_node_update>;
const lli N=2e5+10;
const lli M=1e9+7; 

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        lli n,ct=0;
        cin>>n;
        vll a(n);
        set<lli> pos,neg;
        f(i,n){
            cin>>a[i];
            if(a[i]>0) pos.insert(a[i]);
            else if(a[i]<0) neg.insert(a[i]);
            else ct++;
        }
        sor(a);
        lli maxi=a[n-1]-a[0];
        if(pos.size()==0) cout<<"NO"<<"\n";
        else{
            bool flag=true;
            queue<lli> q;
            lli l=0,h=n-1;
            lli sum=0;
            while(l<=h){
                if(sum+a[h]<maxi){
                    sum+=a[h];
                    q.push(a[h]);
                    h--;
                }
                else{
                    sum+=a[l];
                    q.push(a[l]);
                    l++;
                }
                if(abs(sum)>=maxi){
                    flag=false;
                    break;
                }
            }
            if(flag){
                cout<<"YES"<<"\n";
                while(!q.empty()){
                    cout<<q.front()<<" ";
                    q.pop();
                }
                cout<<"\n";
            }
            else cout<<"NO"<<"\n";
        }
    }
    return 0;
}