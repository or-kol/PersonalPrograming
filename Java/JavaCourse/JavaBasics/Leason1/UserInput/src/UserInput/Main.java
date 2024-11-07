package UserInput;

import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		
		Scanner scanner = new Scanner(System.in);
		
		System.out.println("What is your name? ");
		String name = scanner.nextLine();
		
		System.out.println("How old are you? ");
		int age = scanner.nextInt();
		
		scanner.nextLine();
		
		System.out.println("What is your favorit food? ");
		String food = scanner.nextLine();
		
		System.out.println(String.format("Hello %s", name));
		System.out.println(String.format("You are %d ears old", age));
		System.out.println(String.format("You like %s", food));

	}

}
