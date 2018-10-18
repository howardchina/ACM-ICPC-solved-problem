#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>
#include <bitset>
using namespace std;
const int maxn = 600000 + 10 ;

int fa[maxn] , clk[maxn] ;
set<int>number ;

bitset<maxn*2> text;
bitset<maxn> temp ;

int N ,M, tn ;

void  go(int u , int v) {
    tn =  0 ;
    if(clk[u] > clk[v]) {
        while(1) {
            temp[tn++] =  u%2  ;  if(tn > 600000) while(1) ;
            if(u == v) break ;
            u = fa[u] ;
        }
    }
    else {
        while(1) {
            temp[tn++] =  v%2  ;  if(tn > 600000) while(1) ;
            if(u == v) break ;
            v = fa[v] ;
        }

        for(int i=0,j=tn-1; i<=j; i++ , j--) {
            int x = temp[i] ;
            temp[i] = temp[j];
            temp[j] = x;
        }

    }
}

			//fail  数组，记录“失配边 ”
void GetFail(bitset<maxn> &P,int *f, int m){
	f[0]=f[1]=0;
	for(int i=1;i<m;i++){
		int j=f[i];
		while(j && P[i]!=P[j]) j=f[j];
		f[i+1] = (P[i]==P[j] ? j+1 : 0);
	}
}
int KMP_find(bitset<maxn*2> &T, bitset<maxn> & P,int *f, int n ,int m){
	GetFail(P,f , m);
	int j=0, ret = 0 ;							//当前节点编号，初始值为0
	for(int i=0;i<n;i++){				//文本串当前指针
		while(j && T[i]!=P[j]) j=f[j];	//顺着失配边走
		if(T[i]==P[j]) j++;
		if(j==m) {
            ret ++ ;
            if(j) j = f[j] ;
		}
	}
	return ret ;
}

void append(int st , int n) {
    for(int i=0; i<n; i++) {
        text[N++] = temp[st++] ;
    }
}

int main()
{
//    freopen("data.in", "r" , stdin) ;

    int T , cas = 1;
    scanf("%d", &T) ;
    while(T--) {
        int n ;
        scanf("%d", &n) ;

        number.clear() ;
        memset(fa, -1, (n+5) * sizeof(fa[0])) ;
        memset(clk, -1, (n+5) * sizeof(clk[0])) ;


        number.insert(0);
        number.insert(n+1) ;
        int root ;

        for(int i=1; i<=n; i++) {
//            a[i] = i ;
            int x ;
            scanf("%d", &x) ;
            clk[x] = i ;
            int f1 = * number.lower_bound(x) ;
            int f2 = * ( --number.lower_bound(x) ) ;
            number.insert(x) ;

            if(clk[f2] > clk[f1]) f1 = f2 ;
            if(clk[f1] != -1) {
                fa[ x ] = f1 ;
            }
            else {
                root = x ;
            }
        }


        N = 0 ;
        if(root != 1) {
            go(root , 1) ;
            //memcpy(text+N , temp , (tn-1) * sizeof(temp[0]) ) , N += tn - 1 ;
            append(0 , tn-1) ;
        }
        if(1<n) {
            go(1 , 2) ;
            //memcpy(text+N , temp , (tn) * sizeof(temp[0]) ) , N += tn  ;
            append(0 , tn) ;
        }
        for(int i=3; i<=n; i++) {
            go(i-1, i) ;
            //memcpy(text+N , temp+1 , (tn-1) * sizeof(temp[0]) ) , N += tn - 1 ;
            append(1 , tn-1) ;
        }
        if(n != root) {
            go(n , root) ;
            //memcpy(text+N , temp+1 , (tn-1) * sizeof(temp[0]) ) , N += tn - 1 ;
            append(1 , tn-1) ;
        }



//        for(int i=0; i<N; i++) printf("%d " , text[i]) ;
//        printf("\n") ;

        //text[N] = '\0' ;
        //scanf("%s", temp) ;
        M = 0 ;
        getchar() ;
        char ch = getchar() ;
        while(ch<='1' && ch >= '0') {
            temp[M++] = ch - '0' ;
            ch = getchar() ;
        }

        int ans = KMP_find(text , temp , fa , N , M) ;

        printf("Case #%d: %d\n" , cas++ , ans) ;
    }
    return 0;
}
