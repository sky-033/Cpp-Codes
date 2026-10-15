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
const lli N=4e5+10; 

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        vector<int> a(4);
        f(i,4){
            a[i]=int(s[i])-48;
        }
        lli x=0;
        x=a[0]*1000+a[1]*100+a[2]*10+a[3]*1;
        lli l=1,h=x,mid;
        while(h-l>1){
            mid=(l+h)/2;
            if(mid*mid>x) h=mid-1;
            else l=mid;
        }
        if(l*l==x){
            cout<<l<<" "<<0<<endl;
        }
        else if(h*h==x){
            cout<<h<<" "<<0<<endl;
        }
        else cout<<-1<<endl;
    }
    return 0;
}