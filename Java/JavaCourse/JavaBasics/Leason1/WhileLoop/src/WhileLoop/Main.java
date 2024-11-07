package WhileLoop;

import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		
		Scanner s = new Scanner(System.in);
		
		String name = "";
		
		while(name.isBlank())
		{
			System.out.println("Enter your name");
			name = s.nextLine();
		}
		
		System.out.println(String.format("Hello, %s", name));
		
		
		// do loop - execute the block of code at least once
		do
		{
			System.out.println("Enter your name");
			name = s.nextLine();
		}
		while(name.isBlank());

	}

}
