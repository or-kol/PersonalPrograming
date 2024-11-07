package Random;

import java.util.Random;

public class Main {

	public static void main(String[] args) {
		
		Random r = new Random();
		
		int x = r.nextInt(6) + 1;
		System.out.println(String.format("Random int = %d", x));
		
		double d = r.nextDouble();
		System.out.println(String.format("Random int = %.17f", d));
		
		boolean b = r.nextBoolean();
		System.out.println(String.format("Random boolean = %b", b));
		
		char c = (char)(r.nextInt(26) + 'a');
		System.out.println(String.format("Random char = %c", c));
		
		

	}

}
