package PrintFormat;

public class Main {

	public static void main(String[] args) {
		
		boolean b = true;
		char c = '@';
		String s = "Or";
		int i = -50000;
		double d = 15.356875;
		
		System.out.printf("This is format string %b\n", b);
		System.out.printf("This is format string %c\n", c);
		System.out.printf("This is format string %s\n", s);
		System.out.printf("This is format string %d\n", i);
		System.out.printf("This is format string %f\n", d);
		
		
		//Width:
		System.out.printf("This is format string i%10s\n", s);
		
		
		//Precision:
		System.out.printf("This is format string %.2f\n", d);
		
		
		//Flags:
			// '-' - left justify
		System.out.printf("This is format string %-10si\n", s);
		
			// ',' - adding ',' in the thousands place in a numeric value
		System.out.printf("This is format string %,d\n", i);
		
			// '+' - adding + or - to the number based on it's value
		System.out.printf("This is format string %+d\n", i);
		
			// 0 - adding 0 before the with will make it pad with 0 before the value
		System.out.printf("This is format string %020d\n", i);
		
	}

}
