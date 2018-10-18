import java.math.*;
import java.util.*;

public class Main {
    public static void main(String arg[]){
        Scanner cin = new Scanner(System.in);
        int n = cin.nextInt();
        int an[] = new int[n];
        int a[] = new int[n];
        int b[] = new int[n];
        int i,j,k;
        for (i=0;i<n;i++)
            an[i] = cin.nextInt();
        Arrays.sort(an);
        for (i=1,j=1;i<n;i++)
            if (an[i]!=an[i-1])
                an[j++] = an[i];
        for (i=1,k=0;i<j;i++){
            a[k] = (an[i] - an[i-1])*2;
            b[k] = an[i] * an[i-1];
            int t = gcd(a[k],b[k]);
            a[k] /= t;
            b[k++] /= t;
        }
        BigInteger ans1 = BigInteger.valueOf(a[0]),ans2 = BigInteger.valueOf(b[0]),ans;
        for (i=1;i<k;i++){
            ans1 = ans1.gcd(BigInteger.valueOf(a[i]));
            ans = ans2.multiply(BigInteger.valueOf(b[i]));
            ans2 = ans.divide(ans2.gcd(BigInteger.valueOf(b[i])));
        }
        ans = ans2.gcd(ans1);
        System.out.println(ans2.divide(ans)+" "+ans1.divide(ans));
    }
    public static int gcd(int a,int b){
        int t;
        if (a<b){
            t = a;
            a = b;
            b = t;
        }
        while(true){
            if (b==0) break;
            t = a;
            a = b;
            b = t%b;
        }
        return a;
    }
}