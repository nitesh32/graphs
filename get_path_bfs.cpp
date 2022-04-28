#include<bits/stdc++.h>
using namespace std;
long long n;
string s;
typedef long long ll;
#define nit( i, n) for(i=0;i<n;i++)
int gcd(int a,int b){ if(b==0) return a; else return gcd(b,a%b);}
bool iseven(int n){return ((n&1)==0)?true:false;}
int pov(int n,int m){ int c=1;  while(m>0){  if(!iseven(m)){ c=c*n; } n=n*n; m=m>>1;  }  return c; }
unsigned int intlen(unsigned int n){return n ? intlen(n/10)+1 : 0;}
bool isprime(int x) { for (int d = 2; d * d <= x; d++) { if (x % d == 0) return false; }return true; }
int main(){
#ifndef ONLINE_JUDGE
freopen("ipt.txt","r",stdin);
freopen("ou.txt","w",stdout);
#endif
    ll t;
    cin>>t;
    while(t--){
        ll e;
        cin>>n>>e;
        ll st,ew;
        cin>>st>>ew;
        int** ed=new int*[n];
        for(int i=0;i<n;i++){
            ed[i]=new int[n];
            for(int j=0;j<n;j++){
                ed[i][j]=0;
            }
        }
        for(int i=0;i<e;i++){
            ll x,y;
            cin>>x>>y;
            ed[x][y]=1;
            ed[y][x]=1;
        }
        int* visit = new int[n];
        for(int i=0;i<n;i++){
            visit[i]=0;
        }
        if(ed[st][ew]==1){
            cout<<ew<<" "<<st<<endl;
            continue;
        }
        queue<ll> qu;
        qu.push(st);
        visit[st]=1;
        map<ll,ll> mp;
        //cout<<st<<" ";
        int f=0;
        ll last;
        while(!qu.empty()){
            ll a = qu.front();
            for(int i=0;i<n;i++){
                if(i==a){
                    continue;
                }
                else{
                    if(ed[a][i]==1&&visit[i]!=1){
                        //cout<<i<<" ";
                        mp[i]=a;
                        if(i==ew){
                            f=1;
                            last=a;
                            break;
                        }
                        qu.push(i);
                        visit[i]=1;
                    }
                }
            }
            if(f==1){
                break;
            }
            qu.pop();
        }
        // for(auto val : mp){
        //     cout<<val.first<<" "<<val.second<<endl;
        // }
        if(f==1){
        cout<<ew<<" ";
        while(true){
            cout<<last<<" ";
            last=mp[last];
            if(last==st){
                break;
            }
        }
        cout<<st<<" ";
        }
    cout<<endl;
    }
return 0;
}