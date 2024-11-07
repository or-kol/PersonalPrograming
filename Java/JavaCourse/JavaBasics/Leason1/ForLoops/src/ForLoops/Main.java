package ForLoops;

import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		
		int i;
		
		for (i = 0; i <= 10; ++i)
		{
			System.out.println(i);
		}
		
		
		for (i = 10; i >= 0; --i)
		{
			System.out.println(i);
		}
		
		System.out.println("Happy New Year!!");
		
		System.out.println();
		
		//Nested loops
		int rows;
		int columns;
		String symbol = "";
		int j;
		
		Scanner s = new Scanner(System.in);
		
		System.out.println("Ente number of rows: ");
		rows = s.nextInt();
		
		System.out.println("Ente number of columns: ");
		columns = s.nextInt();
		
		System.out.println("Ente symbol to use: ");
		symbol = s.next();
		
		for(i = 0; i < rows; ++i)
		{
			for(j = 0; j < columns; ++j)
			{
				System.out.print(symbol);
			}
			System.out.println();
		}
		
		
	}

}
