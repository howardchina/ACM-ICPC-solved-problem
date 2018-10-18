import java.util.*;
import java.math.*;

public class Main{
	Scanner cin = new Scanner(System.in);
	int T;
	
	
	public void run(){
		T = cin.nextInt();
		int cas=1;
		while(T>0){
			T--;
			int n = cin.nextInt();
			
			System.out.println("Case #" + cas + ": " + BigInteger.valueOf(32).pow(n));
			cas++;
//			BigInteger.valueOf(32).pow(n);
//			System.out.println("!");
		}
	}
	public static void main(String[] args){	
		Main a = new Main();
		a.run();
	}
}