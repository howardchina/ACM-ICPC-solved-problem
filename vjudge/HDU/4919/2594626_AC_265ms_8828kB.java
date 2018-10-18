import java.math.*;
import java.util.*;
import static java.lang.System.out;
import java.io.*;
public class Main {
	static Map map = new HashMap<BigInteger, BigInteger>();
	static BigInteger x0 = new BigInteger("0");  
    static BigInteger x1 = new BigInteger("1");  
    static BigInteger x2 = new BigInteger("2");  
    static BigInteger x4 = new BigInteger("4");  
    static BigInteger x6 = new BigInteger("6");  
	BigInteger dfs(BigInteger x) {
		if(map.get(x) != null) return (BigInteger)map.get(x);

		BigInteger d = dfs(x.divide(x2)); // dfs(x/2)
		BigInteger q1 = x.divide(x2);  // x/2
		BigInteger q2 = q1.subtract(x1);  // x/2-1

		BigInteger f1;
		if (x.mod(BigInteger.valueOf(2)).equals(x1)) {
			f1 = d.multiply(x4);
			f1 = f1.add(x6.multiply(q1));
		}  else {
			f1 = d;
			BigInteger d2 = dfs(q2);
			f1 = f1.add(d2);
			f1 = f1.add(x);
			f1 = f1.subtract(x2);
			f1 = f1.multiply(x2);
		}
		map.put(x, f1);
		return f1;
	}
	public void work() {
		map.put(BigInteger.valueOf(0), BigInteger.valueOf(0));
		map.put(BigInteger.valueOf(1), BigInteger.valueOf(0));
		map.put(BigInteger.valueOf(2), BigInteger.valueOf(0));
		map.put(BigInteger.valueOf(3), BigInteger.valueOf(6));
		while(cin.hasNext()){
			String s = cin.next();
			System.out.println(dfs(new BigInteger(s)));
		}
	}
	Main() {
		cin = new Scanner(System.in);
	}
	public static void main(String[] args) {
		Main e = new Main();
		e.work();
	}
	public Scanner cin;
}