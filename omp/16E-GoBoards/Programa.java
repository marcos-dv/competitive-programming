import java.math.BigInteger;
import java.util.Scanner;

public class Programa {
	
	//Cambio de base
	public static String base(BigInteger n, BigInteger base) {
		String b3 = "";
		BigInteger cero = new BigInteger("0");
		while(n.compareTo(cero) > 0) {
			b3 += n.mod(base).toString();
			n = n.divide(base);
		}
		return b3;
	}
	
	//Dibuja el tablero de la posicion n
	public static void solve(BigInteger n) {
		String n3 = base(n, new BigInteger("3"));
		for(int i = 0; i < 19*19 ; ++i) {
			if ((i != 0) && (i % 19 == 0))
				System.out.println("");
			if (i >= n3.length())
				System.out.print('.');
			else if (n3.charAt(i) == '0')
				System.out.print('.');
			else if (n3.charAt(i) == '1')
				System.out.print('W');
			else
				System.out.print('B');
		}
		System.out.println("");
		System.out.println("");
	}
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int ncasos = sc.nextInt();
		
		for(int i = 0; i < ncasos; ++i) {
			BigInteger n = sc.nextBigInteger();
			solve(n.add(new BigInteger("-1")));
		}
		sc.close();
	}
}
