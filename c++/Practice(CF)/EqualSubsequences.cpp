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
#define all(x) (x).begin(), (x).end()
#define sor(x) sort(all(x))
#define setbits(x) __builtin_popcountll(x)
#define bitlen(x) 64-__builtin_clzll(x)
const lli N=2e5+10;
const lli M=1e9+7; 

vll factor(lli n){
    vll temp;
    for(lli i=1;i*i<=n;i++){
        if(n%i==0){
            temp.push_back(i);
            if(n/i!=i) temp.push_back(n/i);
        }
    }
    sor(temp);
    return temp;
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
        string s;
        cin>>s;
        map<char,lli> freq;
        vll ans;
        fa(s) freq[it]++;
        vll factors=factor(n);
        fa(freq) ans.push_back(it.second);
        sor(ans);
        reverse(all(ans));
        lli divi=1,cnt=n;
        fa(factors){
            lli ct=0;
            lli siz=n/it;
            if(siz<=ans.size()){
                for(lli i=0;i<siz;i++){
                    if(ans[i]>it) ct+=(ans[i]-it);
                }
                for(lli i=siz;i<ans.size();i++){
                    ct+=ans[i];
                }
                if(ct<cnt){
                    cnt=ct;
                    divi=it;
                }
            }
            else{
                for(lli i=0;i<ans.size();i++){
                    if(ans[i]>it) ct+=(ans[i]-it);
                }
                if(ct<cnt){
                    cnt=ct;
                    divi=it;
                }
            }
        }
        lli cnt2=cnt;
        queue<char> todel,toadd,toadd2;
        fa(freq){
            if(it.second>divi){
                cnt-=(it.second-divi);
                for(lli i=0;i<it.second-divi;i++) todel.push(it.first);
            }
        }
        fa(freq){
            if(cnt<=0) break;
            cnt-=it.second;
            for(int i=0;i<it.second;i++) todel.push(it.first);
        }
        map<char,lli> dell,addd;
        for(char i='a';i<='z';i++){
            dell[i]=0;
            addd[i]=0;
        }
        // cout<<todel.size();
        while(!todel.empty()){
            char temp=todel.front();
            todel.pop();
            dell[temp]++;
        }
        fa(freq){
            if(it.second<divi && dell[it.first]==0){
                for(int i=0;i<divi-it.second;i++) toadd.push(it.first);
            }
        }
        while(!toadd.empty()){
            char temp=toadd.front();
            toadd2.push(temp);
            toadd.pop();
            addd[temp]++;
        }
        if(toadd2.size()<cnt2){
            for(char i='a';i<='z';i++){
                if(dell[i]==0 && addd[i]==0){
                    for(int j=0;j<divi;j++) toadd2.push(i);
                }
                if(toadd2.size()==cnt2) break;
            }
        }
        // while(!toadd2.empty()){
        //     char ccc=toadd2.front();
        //     cout<<ccc<<" ";
        //     toadd2.pop();
            
        // }
        // fa(dell){
        //     if(it.second!=0) cout<<it.first<<" "<<it.second<<" ";
        // }
        f(i,n){
            if(dell[s[i]]!=0){
                char cc=toadd2.front();
                toadd2.pop();
                s[i]=cc;
                dell[s[i]]--;
            }
            if(toadd2.size()==0) break;
        }
        cout<<cnt2<<endl;
        cout<<s<<endl;
    }
    return 0;
}