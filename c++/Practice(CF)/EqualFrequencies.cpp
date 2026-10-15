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
        map<char,lli> freq,freq1;
        vll ans;
        fa(s) freq[it]++;
        freq1=freq;
        vll factors=factor(n);
        fa(freq) ans.push_back(it.second);
        sor(ans);
        reverse(all(ans));
        lli divi=1,cnt=n;
        fa(factors){
            lli ct=0;
            lli siz=n/it;
            if(1LL*siz<=1LL*ans.size()){
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
                for(lli i=0;i<1LL*ans.size();i++){
                    if(ans[i]>it) ct+=(ans[i]-it);
                }
                if(ct<cnt){
                    cnt=ct;
                    divi=it;
                }
            }
        }
        // cout<<divi<<"\n";
        queue<char> add;
        fa(freq){
            if(1LL*add.size()==cnt) break;
            if(it.second<divi){
                lli times=divi-it.second;
                while(times>0){
                    add.push(it.first);
                    if(add.size()*1LL==cnt) break;
                    times--;
                }
            }
            freq[it.first]=divi;
        }
        if(1LL*add.size()<cnt){
            lli extra=cnt-add.size();
            for(char i='a';i<='z';i++){
                if(1LL*add.size()==cnt) break;
                if(freq[i]<=0){
                    lli times=min(divi,cnt-1LL*add.size());
                    while(times>0){
                        add.push(i);
                        times--;
                    }
                }
            }
        }
        // while(!add.empty()){
        //     cout<<add.front()<<" ";
        //     add.pop();
        // }
        // cout<<divi<<endl;
        lli cnt2=cnt;
        f(i,n){
            if(add.size()==0) break;
            if(freq1[s[i]]>divi){
                freq1[s[i]]--;
                char c=add.front();
                add.pop();
                s[i]=c;
            }
            else if(freq1[s[i]]<divi && cnt2>0){
                cnt2--;
            }
            else if(freq1[s[i]]<divi && add.front()!=s[i]){
                freq1[s[i]]++;
                char c=add.front();
                add.pop();
                s[i]=c;
            }
            
        }
        cout<<cnt<<"\n";
        cout<<s<<"\n";
        // cout<<cnt<<"\n";
        // lli cnt2=cnt;
        // queue<char> todel,toadd,toadd2;
        // fa(freq){
        //     if(it.second>divi){
        //         cnt-=(it.second-divi);
        //         for(lli i=0;i<it.second-divi;i++) todel.push(it.first);
        //     }
        // }
        // fa(freq){
        //     if(cnt<=0) break;
        //     cnt-=it.second;
        // }
        // map<char,lli> dell,addd;
        // while(!todel.empty()){
        //     char temp=todel.front();
        //     todel.pop();
        //     dell[temp]++;
        // }
        // fa(freq){
        //     if(it.second<divi && dell[it.first]==0){
        //         for(int i=0;i<divi-it.second;i++) toadd.push(it.first);
        //     }
        // }
        // while(!toadd.empty()){
        //     char temp=toadd.front();
        //     toadd2.push(temp);
        //     toadd.pop();
        //     addd[temp]++;
        // }
        // if(toadd2.size()<cnt){
        //     for(char i='a';i<='z';i++){
        //         if(dell[i]==0 && addd[i]==0){
        //             for(int j=0;j<divi;j++) toadd2.push(i);
        //         }
        //     }
        // }
        // f(i,n){
        //     if(dell[s[i]]!=0){
        //         char cc=toadd2.front();
        //         toadd2.pop();
        //         s[i]=cc;
        //         dell[s[i]]--;
        //     }
        // }
        // cout<<cnt2<<endl;
        // cout<<s<<endl;
    }
    return 0;
}