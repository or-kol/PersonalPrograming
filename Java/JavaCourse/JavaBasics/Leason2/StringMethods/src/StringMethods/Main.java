package StringMethods;

public class Main {

	public static void main(String[] args) {
		
		String name = "John";
		
		System.out.println(name.equals("John"));
		System.out.println(name.equalsIgnoreCase("john"));
		
		System.out.println(name.length());
		
		System.out.println(name.charAt(2));
		
		System.out.println(name.indexOf('o'));
		
		System.out.println(name.isEmpty());
		
		String upper_name = name.toUpperCase();
		System.out.println(upper_name);
		System.out.println(upper_name.toLowerCase());
		
		String name1 = String.format("   %s    ", name);
		System.out.println(String.format(".%s. ===> .%s.", name1, name.trim()));
		
		String replace = name.replace('o', 'a');
		System.out.println(replace);
	}

}
