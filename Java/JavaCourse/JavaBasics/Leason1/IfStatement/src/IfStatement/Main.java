package IfStatement;

public class Main {

	public static void main(String[] args) {
		
		int age = 75;
		
		if (18 <= age && 75 > age)
		{
			System.out.println("You are an adult!");
		}
		else if (75 <= age)
		{
			System.out.println("OK Boomer");
		}
		else
		{
			System.out.println("You are not an adult!");
		}

	}

}
