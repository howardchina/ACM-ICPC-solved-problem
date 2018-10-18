import java.math.BigInteger;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class Main {
	//HDU 4919
	//f(n)=4f(k)+6k..n=2k+1
	//f(n)=2f(k)+2f(k-1)+4k-4..n=2k
	Map<BigInteger, BigInteger>f;
	
	BigInteger x0,x1,x2,x4,x6;
	Scanner cin;
	BigInteger dfs(BigInteger n){
		if(f.get(n)!=null) return f.get(n);
		BigInteger ans=new BigInteger("0");
		BigInteger k,k1;
		if(n.mod(x2).compareTo(x1)==0){//2k+1
			k=n.subtract(x1).divide(x2);
			ans=x4.multiply(dfs(k));
			ans=ans.add(x6.multiply(k));
		}else{//2k
			k=n.divide(x2);
			k1=k.subtract(x1);
			ans=x2.multiply(dfs(k));
			ans=ans.add(x2.multiply(dfs(k1)));
			ans=ans.add(x4.multiply(k).subtract(x4));
		}
		f.put(n, ans);
		return ans;
	}
	void work(){
		x0=new BigInteger("0");
		x1=new BigInteger("1");
		x2=new BigInteger("2");
		x4=new BigInteger("4");
		x6=new BigInteger("6");
		f=new HashMap<BigInteger,BigInteger>();
		f.put(x0, x0);
		cin=new Scanner(System.in);
		while(cin.hasNext()){
			String s=cin.next();
			System.out.println(dfs(new BigInteger(s)));
		}
	}
	public static void main(String[] args) {
		Main e = new Main();
		
		e.work();
	}

}
