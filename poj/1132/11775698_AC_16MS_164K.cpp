#include<stdio.h>
#include<string.h>

bool b[32][32];

int main()
{
    int cnt = 0, x = 0, y = 0;
    char c = '\0';/*, p = ''*/
    scanf("%d", &cnt);
    for(int i = 0; i < cnt; i++) {
        memset(b, 0, sizeof(b));
        printf("Bitmap #%d\n", i+1);
        scanf("%d%d", &x, &y);
        while(true) {
            scanf("%c", &c);
            if(c == '.') break;
            switch(c){
                case 'E':
                    b[x][y-1] = 1;
                    x++;
                    break;
                case 'N':
                    b[x][y] = 1;
                    y++;
                    break;
                case 'W':
                    b[x-1][y] = 1;
                    x--;
                    break;
                case 'S':
                    b[x-1][y-1] = 1;
                    y--;
            }
//            if(c == '.') {
//                break;
//            }
//            else {
//                if(p) {
//                    switch p {
//                        case 'E':
//                            b[x-1][y] = 1;
//                            break;
//                        case 'N':
//                            b[x-1][]
//
//                    }
//                }
//            }

        }

        for(int k = 31; k >= 0; k--) {
            for(int j = 0; j < 32; j++) {
                if(b[j][k]) printf("X");
                else printf(".");
            }
            printf("\n");
        }
        printf("\n");
    }


    return 0;
}
