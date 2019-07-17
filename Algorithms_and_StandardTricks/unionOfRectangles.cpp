#include <bits/stdc++.h>
#define all(x) x.begin(),x.end()
#define mp(x,y) make_pair(x,y)
#define pb(x) push_back(x)
#define pf(x) push_front(x)
#define ppb(x) pop_back(x)
#define ppf(x) pop_front(x)
#define clr(a,b) memset(a,b,sizeof a)
#define ff first
#define ss second
#define umap unordered_map
#define fr(i,n) for(int i=0;i<n;++i)
#define lwr(x) lower_bound(x)
#define upr(x) upper_bound(x)
#define priority_queue pq

using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long, int> pli;
typedef pair<int, long> pil;
typedef pair<long, long> pll;
typedef vector<int> vi;
typedef vector<long> vl;
typedef vector<char> vc;
typedef vector<ll> vll;
typedef vector<bool> vb;
typedef vector<double> vd;

/*primes*/
//ll p1=1e6+3, p2=1616161, p3=3959297, p4=7393931;
//freopen("in.txt" , "r" , stdin) ;
//freopen("out.txt" , "w" , stdout) ;

int n;
const int N=1e6;

struct rect{
    int x1, y1, x2, y2;
};

struct event_x{
    int typ, x, idx;
    event_x(int x, int t, int idx):x(x), typ(t), idx(idx){}
};

struct event_y{
    int typ, y, idx;
    event_y(int y, int t, int idx):y(y), typ(t), idx(idx){}
};

vector<rect> vec;
vector<event_x> Sx;
vector<pii> tree;
vi lazy;

void init()
{
    vec.resize(n);
    tree.resize(4*N, mp(0, 0));
    lazy.resize(4*N, 0);
}

bool comp_x(event_x e1, event_x e2)
{
    if(e1.x!=e2.x) return e1.x<e2.x;
    return e1.typ<e2.typ;
}

void update(int start, int end, int node, int l, int r, int delta)
{
    int len=end-start+1;
    if(start>r || end<l) return ;

    if(start>=l && end<=r){
        tree[node].ss+=delta;
        if(tree[node].ss==0) tree[node].ff=tree[2*node].ff+tree[2*node+1].ff;
        else tree[node].ff=len;
        return ;
    }

    int mid=(start+end)/2;
    update(start, mid, 2*node, l, r, delta);
    update(mid+1, end, 2*node+1, l, r, delta);
    if(tree[node].ss==0) tree[node].ff=tree[2*node].ff+tree[2*node+1].ff;
    return ;
}

int query(int start, int end, int node, int l, int r)
{
    // cout<<start<<" "<<end<<" "<<l<<" "<<r<<" "<<tree[node].ff<<endl;
    if(start>r || end<l) return 0;

    if(start>=l && end<=r){
        return tree[node].ff;
    }

    int mid=(start+end)/2;
    return query(start, mid, 2*node, l, r)+query(mid+1, end, 2*node+1, l, r);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin>>n;
    init();
    fr(i, n){
        cin>>vec[i].x1>>vec[i].y1>>vec[i].x2>>vec[i].y2;
        Sx.pb(event_x(vec[i].x1, 0, i));
        Sx.pb(event_x(vec[i].x2, 1, i));
    }

    sort(all(Sx), comp_x);

    ll ans=0;
    ll px=Sx[0].x, dy, dx, cnt, py;
    for(auto i:Sx){
        dx=i.x-px;
        dy=query(0, N, 1, 0, N);
        // cout<<dx<<" "<<dy<<endl;
        //cout<<dy<<"\n";
        ans+=dx*dy;

        px=i.x;
        
        if(i.typ==0){
            update(0, N, 1, vec[i.idx].y1, vec[i.idx].y2-1, 1);
            continue;
        }

        update(0, N, 1, vec[i.idx].y1, vec[i.idx].y2-1, -1);   
    }

    cout<<ans<<endl;
    return 0;
}