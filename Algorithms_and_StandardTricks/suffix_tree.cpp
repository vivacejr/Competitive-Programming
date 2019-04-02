#include <bits/stdc++.h>
using namespace std;

#define fpos adla
const int inf = 1e9;
const int maxn = 1e4;
string s;
map<int, int> to[maxn];
int len[maxn], fpos[maxn], link[maxn];
int node, pos;
int node_num = 1, n = 0;
 
int make_node(int _pos, int _len)
{
    cerr<<node_num<<" "<<_pos<<" "<<_len<<endl;
    fpos[node_num] = _pos;
    len [node_num] = _len;
    return node_num++;
}
 
void go_edge()
{
    cout<<pos<<" "<<node<<" "<<s[n-pos]<<" "<<endl;
    while(pos > len[to[node][s[n - pos]]])
    {
        node = to[node][s[n - pos]];
        pos -= len[node];
        cout<<node<<" "<<s[n-pos]<<" "<<endl;
    }

}
 
void add_letter(int c)
{
    s+=(char)c;
    n++;
    cout<<s<<endl;
    pos++;
    int last = 0;
    while(pos > 0)
    {
        go_edge();
        cout<<"n "<<n<<" "<<pos<<" "<<s[n-pos]<<endl;
        int edge = s[n - pos];
        int &v = to[node][edge];
        int t = s[fpos[v] + pos - 1];
        cout<<pos<<"xxx"<<node<<" "<<(char)edge<<endl;
        cout<<v<<endl;
        if(v == 0)
        {

            cerr<<"root"<<endl;
            v = make_node(n - pos, inf);
            link[last] = node;
            last = 0;
        }
        else if(t == c)
        {
            cerr<<(char)c<<endl;
            link[last] = node;
            return;
        }
        else
        {
            int u = make_node(fpos[v], pos - 1);
            to[u][c] = make_node(n - 1, inf);
            to[u][t] = v;
            fpos[v] += pos - 1;
            len [v] -= pos - 1;
            v = u;
            link[last] = u;
            last = u;
        }
        if(node == 0)
            pos--;
        else
            node = link[node];
    }
}
 
int main()
{
    len[0] = inf;
    string s;
    cin >> s;
    int ans = 0;
    for(int i = 0; i < s.length(); i++)
    {
        add_letter(s[i]);
        cout<<endl;        
    }
}