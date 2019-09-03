#include <cstdio>
#include <algorithm>
using namespace std;
#define rep(i, j, k) for(int i=j;i<=k;i++)
const int N = 321;
const int inf = 5e8;
int a[N][N], d[N][N], pos[N][N];
int n, m, path[N];
void getpath(int x,int y){
     if(pos[x][y]==-1) return ;
     getpath(x,pos[x][y]);
     path[++ path[0]] = pos[x][y];
     getpath(pos[x][y],y);
}
int main(){
    int u, v, w, ans = inf;
    scanf("%d %d", &n, &m);
    rep(i, 1, n) rep(j, 1, n) {
        a[i][j] = d[i][j] = inf;
        pos[i][j] = -1;
    }
    rep(i, 1, m) {
        scanf("%d %d %d", &u, &v, &w);
        d[u][v] = d[v][u] = a[u][v] = a[v][u] = min(a[u][v], w);
    }
    rep(k, 1, n) {
        rep(i, 1, k - 1) rep(j, i + 1, k - 1) 
            if (ans > d[i][j] + a[i][k] + a[k][j]) {
                ans = d[i][j] + a[i][k] + a[k][j];
                path[path[0] = 1] = i;
                getpath(i, j);
                path[++ path[0]] = j;
                path[++ path[0]] = k; 
            } 
        rep(i, 1, n) rep(j, 1, n)
            if (d[i][j] > d[i][k] + d[k][j]) {
                d[i][j] = d[i][k] + d[k][j];
                pos[i][j] = k;
            }
    }
    if(ans == inf) puts("No solution.");
    else {
        for (int i=1;i<=path[0];i++) printf("%d%c",path[i], i==path[0]?'\n':' ');
    }
return 0;
}