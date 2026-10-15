#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        vector<pair<int,int>> sides(4);
        for(int i=0;i<4;i++){
            int x,y;
            cin>>x>>y;
            sides[i]={x,y};
        }
        int x1=0;
        for(int i=0;i<4;i++){
            for(int j=0;j<4;j++){
                if(sides[i].first==sides[j].first){
                    x1=abs(sides[i].second-sides[j].second);
                    break;
                }
            }
        }
        cout<<x1*x1<<endl;
    }
    return 0;
}