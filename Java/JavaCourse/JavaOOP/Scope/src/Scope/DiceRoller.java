package Scope;

import java.util.Random;

public class DiceRoller {
	
	/*
	// r and num are local variables in the constructor method in this example
	// therefore they're accessible only within the constructor and need to be passed through the roll method. 
	DiceRoller()
	{
		Random r = new Random();
		int num = 0;
		roll(r, num);
	}
	
	void roll(Random r, int num)
	{
		num = r.nextInt(6) + 1;
		System.out.println(num);
	}
	*/
	
	
	// in this example r and num are global within the class
	// therefore they are accessible to all methods in the class.
	Random r;
	int num;
	
	DiceRoller()
	{
		r = new Random();
		roll();
	}
	
	void roll()
	{
		num = r.nextInt(6) + 1;
		System.out.println(num);
	}

}
