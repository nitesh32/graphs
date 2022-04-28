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
vector<ll> vec;
bool dfs(int** ed,ll st,ll n,ll end,int* visit){
    //cout<<st<<" ";
    vec.push_back(st);
    if(st==end){
        return true;
    }
    
    visit[st]=1;
    for(int i=0;i<n;i++){
        if(i==st){
            continue;
        }
        else{
            if(ed[st][i]==1&&visit[i]!=1){
                //cout<<i<<" ";
                if(dfs(ed,i,n,end,visit)){
                    return true;
                }
            }
        }
    }
    return false;
}
int main(){
#ifndef ONLINE_JUDGE
freopen("ipt.txt","r",stdin);
freopen("out.txt","w",stdout);
#endif
    ll t;
    cin>>t;
    while(t--){
    ll edg,st,e;
    cin>>n>>edg;
    cin>>st>>e;
    int** ed=new int*[n];
    for(int i=0;i<n;i++){
        ed[i]=new int[n];
        for(int j=0;j<n;j++){
            ed[i][j]=0;
        }
    }
    for(int i=0;i<edg;i++){
        ll x,y;
        cin>>x>>y;
        ed[x][y]=1;
        ed[y][x]=1;
    }
    int* visit=new int[n];
    for(int i=0;i<n;i++){
        visit[i]=0;
    }
    bool ans = dfs(ed,st,n,e,visit);
    if(ans){
    cout<<"YES"<<endl;
    for(int i=vec.size()-1;i>=0;i--){
        cout<<vec[i]<<" ";
    }
    }
    else{
        cout<<"NO"<<endl;
    }
    cout<<endl;
    vec.clear();

    //cout<<ans<<endl;
    // for(auto val : ans){
    //     cout<<val<<" ";
    // }
    }
return 0;
}