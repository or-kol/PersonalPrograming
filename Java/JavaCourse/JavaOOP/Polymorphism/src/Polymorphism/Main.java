package Polymorphism;

import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		
		/*
		Car car = new Car();
		Bicycle bicycle = new Bicycle();
		Boat boat = new Boat();
		
		Vehicle[] racers = {car, bicycle, boat};
		
		for (Vehicle v : racers)
		{
			v.go();
		}
		*/
		
		
		//Dynamic poly-morphism
		
		Scanner s = new Scanner(System.in);
		Animal animal;
		
		System.out.println("Chose one of the following enimals: (1 = Dog) or (2 = Cat)");
		int choice = s.nextInt();
		
		if (1 == choice)
		{
			animal = new Dog();
			animal.speak();
		}
		else if (2 == choice)
		{
			animal = new Cat();
			animal.speak();
		}
		else
		{
			animal = new Animal();
			System.out.println("Invalid choice");
			animal.speak();
		}
	}

}
