//#include <iostream>
//#include <cstdio>
//using namespace std;
//const int MAXN = 1010;
//int Grids[MAXN][MAXN], Digit[MAXN][MAXN], tGrids[MAXN * 4], tDigit[MAXN * 4];
//int Calculate(int p, int n)
//{
//    int r, c;
//    int cnt = 0;
//    r = p;
//    for(c = r; c <= (n - p); c++){
//        tGrids[cnt] = Grids[r][c];
//        tDigit[cnt++] = Digit[r][c];
//    }
//    for(; r <= (n - p); r++){
//        tGrids[cnt] = Grids[r][c];
//        tDigit[cnt++] = Digit[r][c];
//    }
//    for(; c > p; c--){
//        tGrids[cnt] = Grids[r][c];
//        tDigit[cnt++] = Digit[r][c];
//    }
//    for(; r > p; r--){
//        tGrids[cnt] = Grids[r][c];
//        tDigit[cnt++] = Digit[r][c];
//    }
//    for(p = 0; p < cnt; p++)
//        if(tGrids[p] == tDigit[0]) break;
//    if(tGrids[p] != tDigit[0]) return 0;
//    for(int i = (p + 1) % cnt, j = 1; j < cnt; i = (i + 1) % cnt, j++){
//        if(tGrids[i] != tDigit[j]) return 0;
//    }
//    return 1;
//}
//int main()
//{
//    int n, len;
//    int flag, con = 1;
//    //freopen("input.txt", "r", stdin);
//    while(scanf("%d", &n) == 1){
//        if(!n) break;
//        for(int i = 1, k = 1; i <= n; i++)
//            for(int j = 1; j <= n; j++){
//                scanf("%d", &Grids[i][j]);
//                Digit[i][j] = k++;
//            }
//        len = n & 1 ? (n + 1) / 2 : n / 2;
//        flag = 0;
//        for(int i = 1; i <= len; i++){
//            if(i == len && (n & 1)){
//                if(Grids[i][i] != Digit[i][i]) flag = 1;
//                break;
//            }
//            if(!Calculate(i, n)){
//                flag = 1;
//                break;
//            }
//        }
//        printf("%d. ", con++);
//        if(flag) printf("NO\n");
//        else printf("YES\n");
//    }
//    return 0;
//}
    #include <stdio.h>
    unsigned int g[1010][1010];
    unsigned int T[1010][1010];
    int main()
    {
        int n, i, j, k, e, num, x, y, flag, ans, u, d, l, r, x2, y2, cnt;
        cnt = 0;
        while(~scanf("%d", &n)) {
            cnt++;
            if(!n) break;
            for(i = 1; i <= n; i++) {
                for(j = 1; j <= n; j++) {
                    T[i][j] = (i-1)*n+j;
                    scanf("%u", &g[i][j]);
                }
            }

    //        for(i = 1; i <= n; i++) {
    //            for(j = 1; j <= n; j++) {
    //                printf("%2u ", g[i][j]);
    //            }
    //            printf("\n");
    //        }
    //        for(i = 1; i <= n; i++) {
    //            for(j = 1; j <= n; j++) {
    //                printf("%2u ", T[i][j]);
    //            }
    //            printf("\n");
    //        }
            if(n%2) {
                ans = 1;
                e = (n+1)/2;
                for(i = 1; ans && i <= e; i++) {
                    if(i == e) {
                        num = 1;
                    }
                    else {
    //                    num = 8+4*(e-i-1);
                        num = 4*((e-i+1)/2);
    //                    num = 8+4*(i-1);
                    }
                    x = 0; y = 0; flag = 1;
                    for(j = 1; flag && j <= n; j++) {
                        for(k = 1; flag && k <= n; k++) {
                            if(g[j][k] == T[i][i]) {
                                x = j; y = k; flag = 0;
    //                            printf("g%d T%d x%d y%d\n", g[j][k], T[i][i], x, y);
    //                            printf("i %d j %d\n", j, k);
    //                            for(int ii = 1; ii <= n; ii++) {
    //                                for(int jj = 1; jj <= n; jj++) {
    //                                    printf("%2u ", g[ii][jj]);
    //                                }
    //                                printf("\n");
    //                            }
                            }
                        }
                    }
    //                printf("start x%d y%d\n", x, y);
                    if(flag) {
                        ans = 0;
                        break;
                    }
    //                printf("x%d y%d\n", x, y);
                    u = i; r = n - i + 1; d = r; l = u;
    //                printf("u%d r%d d%d l%d\n", u, r, d, l);
                    if(x < u || x > d || y < l || y > r) {
                        ans = 0;
                        break;
                    }
                    x2 = i; y2 = i;
                    while(num) {
                        num--;
    //                    printf("num %d\n", num);
    //                    printf("i%d x%d y%d g%d\n",i , x, y, g[x][y]);
                        if(y == r && x != u) {
                            x--;
    //                        puts("1");
                        }
                        else if(x == u && y != l) {
                            y--;
    //                        puts("2");
                        }
                        else if(y == l && x != d) {
                            x++;
    //                        puts("3");
                        }
                        else if(x == d && y != r) {
                            y++;
    //                        puts("4");
                        }
                        else {
    //                        if(u != d && r != l)
    //                            printf("error\n");
                        }
                        if(y2 == r && x2 != u) {
                            x2--;
                        }
                        else if(x2 == u && y2 != l) {
                            y2--;
                        }
                        else if(y2 == l && x2 != d) {
                            x2++;
                        }
                        else if(x2 == d && y2 != r) {
                            y2++;
                        }
                        else {
    //                        printf("error\n");
                        }
                        if(g[x][y] != T[x2][y2]) break;
    //                    printf("num%d\n", num);
                    }
                    if(num != 0) ans = 0;
    //                printf("num%d\n", num);
                }
            }
            else {
                ans = 1;
                e = n/2;
                for(i = 1; ans && i <= e; i++) {
                    num = 4*((e+1-i)*2-1);
    //                if(i == e) {
    //                    num = 1;
    //                }
    //                else {
    //                num = 4*((e-i+1)/2);
    //                    num = 8+4*(i-1);
    //                }
                    x = 0; y = 0; flag = 1;
                    for(j = 1; flag && j <= n; j++) {
                        for(k = 1; flag && k <= n; k++) {
                            if(g[j][k] == T[i][i]) {
                                x = j; y = k; flag = 0;
    //                            printf("g%d T%d x%d y%d\n", g[j][k], T[i][i], x, y);
    //                            printf("i %d j %d\n", j, k);
    //                            for(int ii = 1; ii <= n; ii++) {
    //                                for(int jj = 1; jj <= n; jj++) {
    //                                    printf("%2u ", g[ii][jj]);
    //                                }
    //                                printf("\n");
    //                            }
                            }
                        }
                    }
    //                printf("start x%d y%d\n", x, y);
                    if(flag) {
                        ans = 0;
                        break;
                    }
    //                printf("x%d y%d\n", x, y);
                    u = i; r = n - i + 1; d = r; l = u;
    //                printf("u%d r%d d%d l%d\n", u, r, d, l);
    //                if(x < u || x > d || y < l || y > r) {
    //                    ans = 0;
    //                    break;
    //                }
                    x2 = i; y2 = i;
                    while(num) {
                        num--;
    //                    printf("num %d\n", num);
    //                    printf("i%d x%d y%d g%d\n",i , x, y, g[x][y]);
                        if(y == r && x != u) {
                            x--;
    //                        puts("1");
                        }
                        else if(x == u && y != l) {
                            y--;
    //                        puts("2");
                        }
                        else if(y == l && x != d) {
                            x++;
    //                        puts("3");
                        }
                        else if(x == d && y != r) {
                            y++;
    //                        puts("4");
                        }
                        else {
    //                        if(u != d && r != l)
    //                            printf("error\n");
                        }
                        if(y2 == r && x2 != u) {
                            x2--;
                        }
                        else if(x2 == u && y2 != l) {
                            y2--;
                        }
                        else if(y2 == l && x2 != d) {
                            x2++;
                        }
                        else if(x2 == d && y2 != r) {
                            y2++;
                        }
                        else {
    //                        printf("error\n");
                        }
                        if(g[x][y] != T[x2][y2]) break;
    //                    printf("num%d\n", num);
                    }
                    if(num != 0) ans = 0;
    //                printf("num%d\n", num);

                }

            }
    //        e = (n+1)/2;

    //        for(i = 0; i < e; i++) {
    //            for()
    //        }
            if(ans) {
                printf("%d. YES\n", cnt);
            }
            else {
                printf("%d. NO\n", cnt);
            }
        }
        return 0;
    }
