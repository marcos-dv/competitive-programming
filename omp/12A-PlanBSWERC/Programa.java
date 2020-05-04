package planbswerc;

import java.util.Scanner;

//Centrado en (x,y) y radio r
class Circulo {
	private double x, y, r;
	
	public Circulo(int x1, int y1, int d) {
		x = x1;
		y = y1;
		r = (double)d/2;
	}
	
	//Devuelve true si interseca con la recta centrada de pendiente m.
	Boolean interseccion(double m){
		return ((2*x*y*m-y*y+r*r+m*m*(r*r-x*x)) >= 0);
	}	
}


public class Programa {

	//10 angulos, de 0 a 90 (de 10 en 10)
	private final static int ANGULOS = 10;
	private final static int SALTO = 10;

	public static Scanner reader = new Scanner(System.in);	
	
	private static Circulo[] leerCirculos(int n) {
		Circulo c[] = new Circulo[n];
		for (int i = 0; i < n; ++i) {
			int x = reader.nextInt();
			int y = reader.nextInt();
			int d = reader.nextInt();
			c[i] = new Circulo(x, y, d);
		}
		return c;
	}
	
	private static double [] angulos(){
		double angulos[] = new double[ANGULOS];
		for (int i = 0; i < ANGULOS; ++i) {
			//Tangente del angulo en radianes
			angulos[i] = Math.tan((double)Math.PI*i*SALTO/180);
		}
		return angulos;
	}
	
	private static void solve() {
		int n = reader.nextInt();
		Circulo circulos[] = leerCirculos(n);
		double pendiente[] = angulos();
		Boolean tocados[] = new Boolean[n];
		for (int j = 0; j < n; ++j)
			tocados[j] = false;
		int rotos = 0;
		//Angulo i, globo j
		for (int i = 0; (i < ANGULOS) && (rotos < n); ++i) {
			//el disparo es valido, rompe algun globo
			Boolean valido = false;
			//Comprobar los globos
			for(int j = 0; j < n; ++j) {
				if (!tocados[j] && circulos[j].interseccion(pendiente[i])) {
						rotos++;
						valido = true;	
						tocados[j] = true;		
				}
			}	//Disparo efectuado
			if (valido)
				System.out.println("Fire laser at " + i*SALTO + " degrees.");
		}
		//Solucion
		if (rotos == 0)
			System.out.println("No balloon burst.");
		else if (rotos == 1)
			System.out.println("1 burst balloon.");
		else
			System.out.println(rotos + " burst balloons.");
	}
	
	public static void main(String[] args) {
		int ncasos = 0;
		ncasos = reader.nextInt();
		for(int i = 0; i < ncasos; ++i) {
			solve();
		}
		reader.close();
	}
}
