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
void solve(int** ed,int st,ll n,int* visit){
    queue<ll> qu;
    qu.push(st);
    cout<<st<<" ";
    while(!qu.empty()){
        ll a=qu.front();
        visit[a]=1;
        //cout<<a<<" ";
        for(int i=0;i<n;i++){
            if(i==a){
                continue;
            }
            else{
                if(ed[a][i]==1&&visit[i]!=1){
                    cout<<i<<" ";
                    qu.push(i);
                    visit[i]=1;
                }
            }
        }
        
        qu.pop();
    }
}
int main(){
#ifndef ONLINE_JUDGE
freopen("ipt.txt","r",stdin);
freopen("out.txt","w",stdout);
#endif
    ll e;
    cin>>n>>e;
    int** ed = new int*[n];
    int i=0;
    for(int i=0;i<n;i++){
        ed[i]=new int[n];
        for(int j=0;j<n;j++){
            ed[i][j]=0;
        }
    }
    for(i=0;i<e;i++){
        ll a,b;
        cin>>a>>b;
        ed[a][b]=1;
        ed[b][a]=1;
    }
    int* visit = new int[n];
    for(i=0;i<n;i++){
        visit[i]=0;
    }
    for(i=0;i<n;i++){
    if(visit[i]!=1)
    solve(ed,i,n,visit);
    }
return 0;
}