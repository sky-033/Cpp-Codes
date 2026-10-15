#include<bits/stdc++.h>
using namespace std;
#define lli long long
#define vll vector<lli>
#define vvll vector<vector<lli>>
#define vp vector<pair<lli,lli>>
#define f(i,n) for(lli i=0;i<n;i++)
#define F(I,n) for(lli I=1;I<n;I++)
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
        vll a(n);
        f(i,n) cin>>a[i];
        vll b,c;
        bool flag=true;
        for(lli i=0;i<n-1;i++){
            if(a[i]!=a[i+1]){
                flag=false;
                break;
            }
        }
        if(flag){
            cout<<-1<<endl;
        }
        else{
            sort(a.begin(),a.end());
            b.push_back(a[0]);
            lli indx=1;
            for(lli i=1;i<n;i++){
                if(a[i]==a[0]){
                    b.push_back(a[i]);
                    indx++;
                }
                else break;
            }
            for(lli i=indx;i<n;i++){
                c.push_back(a[i]);
            }
            cout<<b.size()<<" "<<c.size()<<endl;
            f(i,b.size()) cout<<b[i]<<" ";
            cout<<endl;
            f(i,c.size()) cout<<c[i]<<" ";
            cout<<endl;
        }
    }
    return 0;
}