//#Name: Sofen Hoque Anonta  #Problm:
#include <bits/stdc++.h>
using namespace std;

//FOLD ME
namespace{
typedef long long LL;
typedef vector<int> vint;
typedef pair<int,int> pint;
typedef unsigned long long ULL;

//Macros
int CC_;
#define sf scanf
#define pf printf
#define PP cin.get();
#define NL cout<<endl;
#define all(container) container.begin(),container.end()
#define DC(x_) cout<<">>> "<<#x_<<"\n";DA(x_.begin(), x_.end());
#define DD(x_) cout<<">>>>( "<<++CC_<<" ) "<<#x_<<": "<<x_<<endl;
#define SS printf(">_<LOOOOOK@MEEEEEEEEEEEEEEE<<( %d )>>\n",++CC_);
#define EXT(st_) cout<<"\n>>>Exicution Time: "<<(double)(clock()-st_)/CLOCKS_PER_SEC<<endl;
#define DM(MT,n_,m_)pf("Matrix %s:\n   ", #MT);for(int i_= 0;i_<m_;i_++)pf("%4d ", i_);NL;NL;for(int r_=0;r_<n_;r_++){pf("%2d ", r_);for(int c_= 0;c_<m_;c_++)pf("%4d ", MT[r_][c_]);NL}
#define mem(a_,b_)(a_, b_, sizeof(a_));


//constants
const double EPS= 1E-9;
const double PI= 2*acos(0.0);
const long long MOD= 1000000007;

template <class T>void DA(T i,T e){while(i!=e){cout<<"Con>>( "<<++CC_<<" ) "<<*i++<<endl;}}
template <class T>void DA(T* x, int l){for(int i=0; i<l;i++)cout<<"["<<i<<"]>> "<<x[i]<<endl;}
template <class T>inline void sary(T* st, T* nd){while(st<nd)cin>>*st++;/*sf("%d", st++);*/}
template <class T>void tobin(T n,char*bin){int pos= 1<<((int)log2(n));while(pos>=1){if((n & pos)==0)*bin='0';else*bin='1';pos>>=1;bin++;}*bin='\0';}
template <class T>inline T LCM(T x,T y){return((x*y)/__gcd(x,y));}
LL todec(string& num, int b){LL dec=num[0]-(isupper(num[0])? 'A'-10: '0');for(int i=1;num[i];i++){if(num[i]>='A'&& num[i]<='Z')num[i]-='A'-10;else num[i]-='0';dec*= b;dec+= num[i];}return dec;}
LL bigMod(LL x, LL y, LL m){if(y == 0) return 1;LL p= bigMod(x, y/2, m)%m;p= (p*p)%m;return ((y&1)? (x*p)%m :p);}
ULL ncr(int n, int k){ULL res= 1;if(k>n-k)k= n-k;for(int i=0; i<k; i++){res *= n-i;res /= i+1;}return res;}
int phi(int n){int ret= n;for(int i= 2; i*i <= n; i++){if(n % i == 0){while(n%i == 0){n /= i;}ret -= ret/i;}}if(n > 1) ret -= ret/n;return ret;}
int egcd(int a, int b, int& x, int& y){if(a == 0){x= 0;y= 1;return b;}int x1, y1;int gcd= egcd(b%a, a, x1, y1);x= y1 - (b/a) * x1;y= x1;return gcd;}
bool comp(const int a,const int b){return a>b;}
}

const int sss= 1E6;

bool vis[150005];
vint g[150005];

LL CN, CE;

void dfs(int n){
    if(vis[n]) return;
    
    vis[n] = 1;
    int len= g[n].size();
    
    CN++;
    
    for(int i= 0; i<len; i++){
        dfs(g[n][i]);
        CE++;
    }
}

void solve(){
    int n, m;
    
    cin>>n>>m;
    
    int u, v;
    
    
    while(m--){
        cin>>u>>v;
        
        g[u].push_back(v);
        g[v].push_back(u);
    }
    
    
    for(int i=1; i<=n; i++){
        if(vis[i] == 0){
            CN= CE= 0;
            
            dfs(i);
            CE/= 2;
            
//            DD(i)
//            DD(CN)
//            DD(CE)
                    
            if(CN == 1 || (CN == 2 && CE == 1)){
                continue;
            }
            else if(CE != (CN*(CN-1)/2)){
                cout<< "NO" <<endl;
                return;
            }
        }
    }
    
    cout<< "YES" <<endl;

}



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
//    freopen("D:/input.txt", "r", stdin);
    
//    for(int i= 1; i<10; i++){
//        DD(i*(i+1)/2)
//    }
    
    solve();
    
    return 0;
}