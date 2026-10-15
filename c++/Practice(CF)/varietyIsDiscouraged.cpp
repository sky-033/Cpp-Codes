#include<bits/stdc++.h>
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
 

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        lli n;
        cin>>n;
        vll a(n),hsh(n+1,0);
        f(i,n){
            cin>>a[i];
            hsh[a[i]]++;
        }
        lli x=-1,y=-1;
        lli l=0,h=0,ct=0;
        while(h<n){
            if(hsh[a[h]]==1){
                if(h-l+1>ct){
                    ct=h-l+1;
                    x=l,y=h;
                }
                h++;
            }
            else{
                l=h+1;
                h=l;
            }
        }
        if(x==-1){
            cout<<0<<endl;
        }
        else{
            cout<<x+1<<" "<<y+1<<endl;;
        }
    }
    return 0;
}