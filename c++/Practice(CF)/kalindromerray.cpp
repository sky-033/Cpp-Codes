#include<bits/stdc++.h>
using namespace std;
#define lli long long
#define vll vector<lli>
#define vvll vector<vector<lli>>
#define vp vector<pair<lli,lli>>
#define f(i,n) for(lli i=0;i<n;i++)
#define ff(a,b,c) for(lli i=a;i<b;i+=c)
#define fa(v) for (auto &it : v) 
const lli N=4e5+10; 
bool check(vll &a,lli x){
    vll b;
    lli n=a.size();
    f(i,n){
        if(a[i]!=x){
            b.push_back(a[i]);
        }
    }
    lli m=b.size();
    bool flag=true;
    f(i,m/2){
        if(b[i]!=b[m-i-1]){
            flag=false;
            break;
        }
    }
    if(flag==true) return true;
    else return false;
}
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
        lli l=0,h=n-1;
        bool flag1=true,flag2=true;
        while(l<h){
            if(a[l]!=a[h]){
                flag1=check(a,a[l]);
                flag2=check(a,a[h]);
                break;
            }
            l++,h--;
        }
        if(flag1==true || flag2==true) cout<<"YES"<<endl;
        else cout<<"NO"<<endl; 
    }
    return 0;
}