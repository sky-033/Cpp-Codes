#include<bits/stdc++.h>
using namespace std;
#define lli long long
#define vll vector<lli>
#define vvll vector<vector<lli>>
#define vp vector<pair<lli,lli>>
#define f(i,n) for(lli i=0;i<n;i++)
#define fa(v) for (auto &it : v) 

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        lli n,k;
        cin>>n>>k;
        vll a(n);
        f(i,n) cin>>a[i];
        if(k==1){
            cout<<0<<endl;
        }
        else if(k==2){
            bool flag=false;
            f(i,n){
                if(a[i]%2==0){
                    flag=true;
                    break;
                }
            }
            if(flag) cout<<0<<endl;
            else cout<<1<<endl;
        }
        else if(k==3){
            lli c1=0,c2=0;
            bool flag1=false;
            f(i,n){
                if(a[i]%3==0){
                    flag1=true;
                    break;
                }
                else if(a[i]%3==2){
                    c2=1;
                }
                else{
                    c1=1;
                }
            }
            if(flag1) cout<<0<<endl;
            else if(c2==1) cout<<1<<endl;
            else cout<<2<<endl;
        }
        else if(k==4){
            bool flag2=false;
            int ct=0;
            f(i,n){
                if(a[i]%4==0){
                    flag2=true;
                    break;
                }
                else if(a[i]%2==0){
                    ct++;
                }
            }
            if(flag2 || ct>=2) cout<<0<<endl;
            else if(ct==1) cout<<1<<endl;
            else if(ct==0){
                bool cc=0,cd=0;
                f(i,n){
                    if(a[i]%4==3) cc=1;
                    else if(a[i]%4==1) cd=1;
                }
                if(cc==1) cout<<1<<endl;
                else if(cd==1) cout<<2<<endl;
            }
        }
        else{
            bool flag4=false;
            lli c4=0,c3=0,c2=0,c1=0;
            f(i,n){
                if(a[i]%5==0){
                    flag4=true;
                    break;
                }
                else if(a[i]%5==4){
                    c4=1;
                }
                else if(a[i]%5==3){
                    c3=1;
                }
                else if(a[i]%5==2){
                    c2=1;
                }
                else{
                    c1=1;
                }
            }
            if(flag4) cout<<0<<endl;
            else if(c4==1) cout<<1<<endl;
            else if(c3==1) cout<<2<<endl;
            else if(c2==1) cout<<3<<endl;
            else if(c1==1) cout<<4<<endl;
        }

    }
    return 0;
}