package Methods;

public class Main {

	public static void main(String[] args) {
		
		//Methods
		int age = 36;
		hello("Or", age);
		
		
		
		//Overloaded Methods
		int x = 3;
		int y = 4;
		
		int z;
		
		z = add(x, y);
		System.out.println(z);
		
		z = add(x, y, x);
		System.out.println(z);
		
		z = add(x, y, x, y);
		System.out.println(z);
		
		double a = 1.5;
		double b = 3.5;
		double c;
		
		c = add(a, b);
		System.out.println(c);
		
		c = add(a, b, a);
		System.out.println(c);
		
		c = add(a, b, a, b);
		System.out.println(c);
		

	}
	
	
	
	//Methods
	static void hello(String name, int age)
	{
		System.out.println(String.format("Hello %s,\nYou are %d ears old!", name, age));
	}
	
	
	
	
	//Overloaded Methods
	static int add(int x, int y)
	{
		System.out.println("Overloaded method number 1");
		return x + y;
	}
	
	static int add(int x, int y, int z)
	{
		System.out.println("Overloaded method number 2");
		return x + y;
	}
	
	static int add(int x, int y, int z, int i)
	{
		System.out.println("Overloaded method number 3");
		return x + y;
	}
	
	static double add(double x, double y)
	{
		System.out.println("Overloaded method number 4");
		return x + y;
	}
	
	static double add(double x, double y, double z)
	{
		System.out.println("Overloaded method number 5");
		return x + y;
	}
	
	static double add(double x, double y, double z, double i)
	{
		System.out.println("Overloaded method number 6");
		return x + y;
	}

}
