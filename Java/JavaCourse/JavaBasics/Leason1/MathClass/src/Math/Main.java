package Math;

import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		
		
		double x = 3.14;
		double y = -10;
		
		double max = Math.max(x, y);
		System.out.println(String.format("Max = %.2f", max));
		
		double min = Math.min(x, y);
		System.out.println(String.format("Min = %.2f", min));
		
		double absolute =  Math.abs(y);
		System.out.println(String.format("Absolute value of y = %.2f", absolute));
		
		double root = Math.sqrt(absolute);
		System.out.println(String.format("Square root of 10 = %.2f", root));
		
		double ceil = Math.ceil(x);
		double floor = Math.floor(x);
		System.out.println(String.format("x rounded up = %.2f", ceil));
		System.out.println(String.format("x rounded down = %.2f", floor));
		
		
		double a;
		double b;
		double hypotenuse;
		
		Scanner s = new Scanner(System.in);
		
		System.out.println("Please enter side a: ");
		a = s.nextDouble();
		
		s.nextLine();
		
		System.out.println("Please enter side b: ");
		b = s.nextDouble();
		
		s.nextLine();
		
		hypotenuse = Math.sqrt(Math.pow(a, 2) + Math.pow(b, 2));
		
		System.out.println(String.format("The hypotenuse = %.2f", hypotenuse));
		

	}

}
