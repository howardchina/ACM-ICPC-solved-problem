#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <cassert>

const double PI = acos(-1.0);

struct Point3{
    double x,y,z;
    Point3(){}
    Point3(double x,double y,double z):x(x),y(y),z(z){}
};

typedef Point3 Vector3;

Vector3 operator - (const Point3& A, const Point3& B){
    return Vector3(A.x-B.x, A.y-B.y, A.z-B.z);
}

Vector3 operator / (const Point3& A, double p){
    return Vector3(A.x/p, A.y/p, A.z/p);
}

Vector3 Cross(const Vector3& A, const Vector3& B){
    return Vector3(A.y*B.z - A.z*B.y, A.z*B.x - A.x*B.z, A.x*B.y - A.y*B.x);
}
double Dot(Vector3& A, Vector3& B){
    return A.x*B.x + A.y*B.y + A.z*B.z;
}
double Length(Vector3& A){
    return sqrt(Dot(A,A));
}


struct Plane{
    double a,b,c,d;
    Plane(){}
//    Plane(int a,int b,int c,int d):a(a),b(b),c(c),d(d){}
    Plane(Point3 *P){
        Vector3 V = Cross(P[1]-P[0], P[2]-P[0]);
        V = V / Length(V);
        a = V.x; b = V.y; c = V.z; d = -Dot(V,P[0]);
    }
    Point3 sample(){
        double v1 = rand() / (double)RAND_MAX;
        double v2 = rand() / (double)RAND_MAX;
        if(a!=0) return Point3(-(b*v1+c*v2+d)/a ,v1, v2);
        if(b!=0) return Point3(v1, -(a*v1+c*v2+d)/b, v2);
        if(c!=0) return Point3(v1, v2, -(a*v1+b*v2+d)/c);
        assert(0); //不是平面
    }
};

struct Mat{
    double v[4][4];
    Mat(){}
    Mat(double A[][4]){
        for(int i=0;i<4;i++){
            for(int j=0;j<4;j++){
                v[i][j] = A[i][j];
            }
        }
    }

    void E(){
        for(int i=0;i<4;i++){
            for(int j=0;j<4;j++){
                if(i==j) v[i][j]=1;
                else v[i][j]=0;
            }
        }
    }

    Mat operator *(const Mat &rhs)const{
        Mat re;
        for(int i=0;i<4;i++){
            for(int j=0;j<4;j++){
                re.v[i][j]=0;
                for(int k=0;k<4;k++){
                    re.v[i][j]+=v[i][k]*rhs.v[k][j];
                }
            }
        }
        return re;
    }

    Point3 transform(Point3 P){
        double p[4]={P.x, P.y, P.z, 1}, re[4]={0};
        for(int i=0;i<4;i++){
            for(int j=0;j<4;j++){
                re[i]+=v[i][j]*p[j];
            }
        }
        return Point3(re[0],re[1],re[2]);
    }
};


Mat translate_mat(double a,double b,double c) {
    double M[][4]={
        {1,0,0,a},
        {0,1,0,b},
        {0,0,1,c},
        {0,0,0,1}
    };
    return Mat(M);
}

Mat rotate_mat(double a,double b,double c,double A) {
    double len = sqrt(a*a+b*b+c*c);
    double x = a/len, y = b/len, z = c/len;
    double sine = sin(A),cosine = cos(A);
    double M[][4]={
        {cosine+(1-cosine)*x*x, x*y*(1-cosine)-z*sine, x*z*(1-cosine)+y*sine, 0},
        {y*x*(1-cosine)+z*sine, cosine+y*y*(1-cosine), y*z*(1-cosine)-x*sine, 0},
        {z*x*(1-cosine)-y*sine, z*y*(1-cosine)+x*sine, cosine+z*z*(1-cosine), 0},
        {0                    , 0                    , 0                    , 1}
    };
    return Mat(M);
}

Mat scale_mat(double a,double b,double c) {
    double M[][4]={
        {a,0,0,0},
        {0,b,0,0},
        {0,0,c,0},
        {0,0,0,1}
    };
    return Mat(M);
}

const int maxn = 50050;

Point3 p3[maxn];
Plane pl[maxn];
char s[22];

int main(){
//    freopen("data.in","r",stdin);
    int n,m,T;
    double a,b,c,rad;
    scanf("%d%d%d",&n,&m,&T);
    for(int i=0;i<n;i++){
        scanf("%lf%lf%lf",&p3[i].x, &p3[i].y, &p3[i].z);
    }
    for(int i=0;i<m;i++){
        scanf("%lf%lf%lf%lf",&pl[i].a, &pl[i].b, &pl[i].c, &pl[i].d);
    }
    Mat M,P;
    M.E();
    while(T--){
        scanf("%s",s);
        scanf("%lf%lf%lf",&a,&b,&c);
        if(s[0]=='T'){
            P = translate_mat(a,b,c);
        }else if(s[0]=='R'){
            scanf("%lf",&rad);
            rad = rad*PI/180;
            P = rotate_mat(a,b,c,rad);
        }else{
            P = scale_mat(a,b,c);
        }
        M=P*M;
    }
    for(int i=0;i<n;i++){
        Point3 ans = M.transform(p3[i]);
        printf("%.2lf %.2lf %.2lf\n",ans.x,ans.y,ans.z);
    }
    for(int i=0;i<m;i++){
        Point3 A[3];
        for(int j=0;j<3;j++){
            A[j]=M.transform(pl[i].sample());
        }
        Plane ans(A);
        printf("%.2lf %.2lf %.2lf %.2lf\n", ans.a, ans.b, ans.c, ans.d);
    }
    return 0;
}


