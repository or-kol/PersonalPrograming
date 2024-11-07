package Exceptions;

import java.util.InputMismatchException;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		
		Scanner s = new Scanner(System.in);
		
		try 
		{
			System.out.println("Enter a whole number to devide: ");
			int x = s.nextInt();
			
			System.out.println("Enter a whole number to devide by: ");
			int y = s.nextInt();
		
			int z = x / y;
			System.out.printf("The result of %d / %d = %d\n", x, y, z);
		}
		catch (ArithmeticException e)
		{
			System.out.println("You can't devide by zero!");
		}
		catch (InputMismatchException e)
		{
			System.out.println("Invalid input!");
		}
		catch(Exception e)
		{
			System.out.println("Something went wrong!");
		}
		finally
		{
			s.close();
		}

	}

}
