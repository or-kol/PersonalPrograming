package LogicalOperators;

import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		
		
		//AND logical operator &&:
		int temp = 15;
		
		if (30 < temp)
		{
			System.out.println("It is hot outside");
		}
		else if (20 <= temp && 30 >= temp)
		{
			System.out.println("It's warm outside");
		}
		else
		{
			System.out.println("It's cold outside");
		}
		
		
		//OR logical operator ||:
		Scanner s = new Scanner(System.in);
		
		System.out.println("You are playing a game! Press q or Q to quit");
		String response = s.next();
		
		if (response.equals("q") || response.equals("Q"))
		{
			System.out.println("You quit the game!");
		}
		else
		{
			System.out.println("You are still playing the game!");
		}
		
		
		//NOT logical operator !:
		if (!response.equals("q") && !response.equals("Q"))
		{
			System.out.println("You are still playing the game!");
		}
		else
		{
			System.out.println("You quit the game!");
		}
		
		
		
	}

}
