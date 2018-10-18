#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;
const int maxn = 1024+10;//列数
const int maxr = 4096+10;//行数
const int maxnode = maxr*4+maxn;

//行编号从1开始，列编号为1~n，结点0是表头结点，结点1~n是各列顶部的虚拟结点
struct DLX{
    int n, sz;//列数，结点总数
    int S[maxn];//各列结点总数

    int row[maxnode],col[maxnode];//各结点行列编号
    int L[maxnode],R[maxnode],U[maxnode],D[maxnode];//十字链表

    int ansd, ans[maxr];//解

    void init(int n){ //n是列数
        this->n = n;

        //虚拟节点
        for(int i=0;i <= n;i++){
            U[i]=i; D[i]=i; L[i]=i-1; R[i]=i+1;
        }
        R[n]=0; L[0]=n;

        sz = n+1;
        memset(S,0,sizeof(S));
    }

    //c为虚拟节点的编号 位于c列的最下面
    void addRow(int r,vector<int>columns){
        int first = sz,column_sz=columns.size();
        for(int i=0; i<column_sz; i++){
            int c=columns[i];
            L[sz]=sz-1; R[sz]=sz+1; D[sz]=c; U[sz]=U[c];
            D[U[c]]=sz; U[c]=sz;
            row[sz]=r; col[sz]=c;
            S[c]++; sz++;
        }
        R[sz-1]=first;L[first]=sz-1;
    }

    //顺着链表，遍历除s以外的其他元素
    #define FOR(i,A,s) for(int i=A[s];i!=s;i=A[i])

    void remove(int c){
        L[R[c]] = L[c];
        R[L[c]] = R[c];
        FOR(i,D,c)
            FOR(j,R,i) {
                U[D[j]]=U[j];
                D[U[j]]=D[j];
                --S[col[j]];
            }
    }

    void restore(int c){
        FOR(i,U,c)
            FOR(j,L,i) {
                ++S[col[j]];
                U[D[j]]=j;
                D[U[j]]=j;
            }
        L[R[c]]=c;
        R[L[c]]=c;
    }

    bool dfs(int d){//d为递归深度
        if(R[0]==0){
            ansd = d;//找到解
            return true;//记录解的长度
        }

        //找S最小的列c
        int c = R[0];//第一个未删除的列
        FOR(i,R,0) if(S[i]<S[c]) c=i;

        remove(c);//删除第c列
        FOR(i,D,c){//用结点i所在行覆盖第c列
            ans[d]=row[i];
            FOR(j,R,i) remove(col[j]);//删除节点i所在行能覆盖的所有其他列
            if(dfs(d+1)) return true;
            FOR(j,L,i) restore(col[j]);//恢复节点i所在行能覆盖的所有其他列
        }
        restore(c);//删除第c列

        return false;
    }

    bool solve(vector<int>& v){
        v.clear();
        if(!dfs(0)) return false;
        for(int i=0; i<ansd; i++) v.push_back(ans[i]);
        return true;
    }
};

DLX solver;
enum{SLOT,ROW,COL,SUB};

int encode(int a,int b,int c){
    return a*256+b*16+c+1;
}

void decode(int code,int &a,int &b,int &c){
    code--;
    c = code%16; code/=16;
    b = code%16; code/=16;
    a = code;
}

char puzzle[16][20];

bool read(){
    for(int i=0;i<16;i++){
        if(scanf("%s",puzzle[i])==EOF) return false;
    }
    return true;
}

int main(){
//    freopen("data.in","r",stdin);
    int kase=0;
    while(read()){
        if(++kase!=1) printf("\n");
        solver.init(1024);
        for(int r=0;r<16;r++){
            for(int c=0;c<16;c++){
                for(int v=0;v<16;v++){
                    if(puzzle[r][c]=='-' || puzzle[r][c]=='A'+v){
                        vector<int>columns;
                        columns.push_back(encode(SLOT,r,c));
                        columns.push_back(encode(ROW,r,v));
                        columns.push_back(encode(COL,c,v));
                        columns.push_back(encode(SUB,(r/4)*4+c/4,v));
                        solver.addRow(encode(r,c,v),columns);
                    }
                }
            }
        }
        vector<int> ans;
        solver.solve(ans);

        int ans_sz=ans.size();
        for(int i=0;i<ans_sz;i++){
            int r,c,v;
            decode(ans[i], r,c,v);
            puzzle[r][c] = 'A'+v;
        }
        for(int i=0;i<16;i++){
            printf("%s\n",puzzle[i]);
        }
    }
    return 0;
}
