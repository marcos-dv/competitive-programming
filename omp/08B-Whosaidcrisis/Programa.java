import java.math.BigInteger;
import java.util.Scanner;

public class Programa {
	
	public static void solve(BigInteger a, BigInteger b){
		System.out.println(a.subtract(b));
	}
	
	public static void main(String[] args) {
			Scanner sc = new Scanner(System.in);
			int ncasos = sc.nextInt();
			for(int i = 0; i < ncasos; ++i)
				solve(sc.nextBigInteger(), sc.nextBigInteger());
	}
}
