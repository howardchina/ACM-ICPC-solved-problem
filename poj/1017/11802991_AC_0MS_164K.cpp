#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;
int main()
{
//    freopen("data.in", "r", stdin);
//    freopen("data.out", "w", stdout);
    int n[7], ans, space;
    while(~scanf("%d%d%d%d%d%d", &n[1], &n[2], &n[3], &n[4], &n[5], &n[6])) {
        if(!n[1] && !n[2] && !n[3] && !n[4] && !n[5] && !n[6]) break;
//        ans = 0;
//        6*6
//        if(n[6]) {
//            ans = n[6];
//            n[6] = 0;
//        }
        ans = n[6];
//        //5*5
//        if(n[5]) {
//            ans += n[5];
//            space = 11 * n[5];
//            if(n[1] && space >= n[1]) {
//                n[1] = 0;
//            } else {
//                n[1] -= space;
//            }
//            n[5] = 0;
//        }
        if(n[5] > 0) {
            ans += n[5];
            n[1] -= 11*n[5];
        }
//        //4*4
//        if(n[4]) {
//            ans += n[4];
//            space = n[4]*20;
//            if(space >= n[2]*4) {
//                n[2] = 0;
//                space -= n[2]*4;
//                if(n[1] && space) {
//                    if(n[1] >= space) {
//                        n[1] -= space;
//                    } else {
//                        n[1] = 0;
//                    }
//                }
//            } else {
//                n[2] -= space/4;
//            }
//            n[4] = 0;
//        }
        if(n[4] > 0) {
            ans += n[4];
            n[2] -= n[4]*5;
            if(n[2] < 0) {
                n[1] += n[2]*4;
            }
        }

//        //3*3
//        if(n[3]) {
//            space = 0;
//            ans += n[3]/4;
//            n[3] %= 4;
//            if(n[3]) ans++;
//            if(n[3] == 1) {
//                if(n[2] >= 5) {
//                     n[2] -= 5;
//                     space = 7;
//                } else if(n[2] > 0) {
//                    space = 27;
//                    space -= n[2]*4;
//                    n[2] = 0;
//                }
//            } else if(n[3] == 2) {
//                if(n[2] >= 3) {
//                    n[2] -= 3;
//                    space = 6;
//                } else if(n[2] > 0) {
//                    space = 18;
//                    space -= n[2]*4;
//                    n[2] = 0;
//                }
//            } else if(n[3] == 3) {
//                if(n[2] > 1) {
//                    n[2] -= 1;
//                    space = 3;
//                } else if(n[2] > 0) {
//                    space = 9;
//                    space -= n[2]*4;
//                    n[2] = 0;
//                }
//            }
//            if(space && n[1]) {
//                if(space >= n[1]) {
//                    n[1] = 0;
//                } else {
//                    n[1] -= space;
//                }
//            }
//            n[3] = 0;
//        }
        if(n[3] > 0) {
            switch(n[3]%4) {
            case 0:
                ans += n[3]/4;
                break;
            case 1:
                ans += n[3]/4+1;
                if(n[2] > 0) {
                    n[2] -= 5;
                    if(n[1] > 0) {
                        if(n[2] < 0) {
                            n[1] += n[2]*4;
                        }
                        n[1] -= 7;
                    } else {
                        if(n[1] > 0) {
                            n[1] -= 27;
                        }
                    }
                }
                break;
            case 2:
                ans += n[3]/4+1;
                if(n[2] > 0) {
                    n[2] -= 3;
                    if(n[1] > 0) {
                        if(n[2] < 0) {
                            n[1] += n[2]*4;
                        }
                        n[1] -= 6;
                    } else {
                        if(n[1] > 0) {
                            n[1] -= 18;
                        }
                    }
                }
                break;
            case 3:
                ans += n[3]/4+1;
                if(n[2] > 0) {
                    n[2] -= 1;
                    if(n[1] > 0) {
                        if(n[2] < 0) {
                            n[1] += n[2]*4;
                        }
                        n[1] -= 5;
                    } else {
                        if(n[1] > 0) {
                            n[1] -= 9;
                        }
                    }
                }
                break;
            }
        }

//        //2*2
//        if(n[2] > 0) {
//            ans += n[2]/9;
//            n[2] %= 9;
//            if(n[2]) ans++;
//            space = 36 - n[2]*4;
//            if(space && n[1]) {
//                if(space >= n[1]) {
//                    n[1] = 0;
//                } else {
//                    n[1] -= space;
//                }
//            }
//            n[2] = 0;
//        }
        if(n[2] > 0) {
            if(n[2]%9 == 0) {
                ans += n[2]/9;
            }
            else {
                ans += n[2]/9 + 1;
                n[1] -= (36-n[2]%9*4);
            }
        }

//        //1*1
//        if(n[1] > 0) {
//            ans += n[1]/36;
//            if(n[1]) ans++;
//            n[1] = 0;
//        }
        if(n[1] > 0) {
            if(n[1]%36 == 0) {
                ans += n[1]/36;
            }
            else {
                ans += n[1]/36 + 1;
            }
        }

        printf("%d\n", ans);
    }
    return 0;
}
//#include <stdio.h>
//int main()
//{
//    freopen("data.in", "r", stdin);
//    freopen("data.out", "w", stdout);
//	int number;
//	int size1, size2, size3, size4, size5, size6;
//	scanf("%d%d%d%d%d%d", &size1, &size2, &size3, &size4, &size5, &size6);
//	while(size1!=0 || size2!=0 || size3!=0 || size4!=0 || size5!=0 || size6!=0)
//	{
//		number = size6;
//		if(size5 != 0)
//		{
//			number += size5;
//			size1 -= size5 * 11;
//		}
//		if(size4 != 0)
//		{
//			number += size4;
//			size2 -= size4 * 5;
//			if(size2 < 0 && size1 > 0)
//			{
//				size1 += 4*size2;
//			}
//		}
//		if(size3 != 0)
//		{
//			switch(size3%4)
//			{
//			case 0:
//				number += size3/4;
//				break;
//			case 1:
//				number += size3/4+1;
//				if(size2 > 0)
//				{
//					size2 -= 5;
//					if(size1 > 0)
//					{
//						if(size2 < 0)
//						{
//							size1 += 4*size2;
//						}
//						size1 -= 7;
//					}
//				}
//				else
//				{
//					if(size1 > 0)
//					{
//						size1 -= 27;
//					}
//				}
//				break;
//			case 2:
//				number += size3/4+1;
//				if(size2 > 0)
//				{
//					size2 -= 3;
//					if(size1 > 0)
//					{
//						if(size2 < 0)
//						{
//							size1 += 4*size2;
//						}
//						size1 -= 6;
//					}
//				}
//				else
//				{
//					if(size1 > 0)
//					{
//						size1 -= 18;
//					}
//				}
//				break;
//			case 3:
//				number += size3/4+1;
//				if(size2 > 0)
//				{
//					size2 -= 1;
//					if(size1 > 0)
//					{
//						if(size2 < 0)
//						{
//							size1 += 4*size2;
//						}
//						size1 -= 5;
//					}
//				}
//				else
//				{
//					if(size1 > 0)
//					{
//						size1 -= 9;
//					}
//				}
//				break;
//			}
//		}
//		if(size2 > 0)
//		{
//			if(size2%9 == 0)
//			{
//				number += size2/9;
//			}
//			else
//			{
//				number += size2/9 + 1;
//				size1 -= (36-size2%9 * 4);
//			}
//		}
//		if(size1 > 0)
//		{
//			if(size1%36 == 0)
//			{
//				number += size1/36;
//			}
//			else
//			{
//				number += size1/36 + 1;
//			}
//		}
//		printf("%d\n", number);
//		scanf("%d%d%d%d%d%d", &size1, &size2, &size3, &size4, &size5, &size6);
//	}
//	return 0;
//}
