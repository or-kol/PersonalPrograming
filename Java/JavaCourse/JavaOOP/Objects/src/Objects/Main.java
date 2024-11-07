package Objects;

public class Main {

	public static void main(String[] args) {
		
		Car my_car = new Car();
		
		System.out.printf("The color of my car is: %s\n", my_car.color);
		System.out.printf("The model of my car is: %s\n", my_car.model);
		System.out.printf("The maker of my car is: %s\n", my_car.make);
		System.out.printf("My car is from: %d\n", my_car.year);
		System.out.printf("My car worth: %.2f$\n", my_car.price);
		
		my_car.drive();
		my_car.brake();
		
		/*
		the problem with this class is that it can build only one kind of car.
		to fix that we need a constructor.
		 */
		
		
		Human human1 = new Human("Or", 36, 92.5);
		Human human2 = new Human("Rick", 65, 70);
		
		System.out.println(human1.name);
		System.out.println(human1.age);
		
		System.out.println(human2.name);
		System.out.println(human2.age);
		
		human1.eat();
		human2.eat();
		
		human1.drink();
		human2.drink();
		
		
		// Array of objects:
			// First method:
		Food[] refregirator = new Food[3];
		
		Food food1 = new Food("Pizza");
		Food food2 = new Food("Hamburger");
		Food food3 = new Food("Hotdog"); 
		
		refregirator[0] = food1;
		refregirator[1] = food2;
		refregirator[2] = food3;
		
		int i;
		for(i = 0; i < refregirator.length; ++i)
		{
			System.out.println(refregirator[i].toString());
		}
		
		
			// Second method:
		Food[] refregirator2 = {food1, food2, food3};
		
		for(i = 0; i < refregirator2.length; ++i)
		{
			System.out.println(refregirator2[i].toString());
		}
		
		
		
		
		// Pass objects as arguments
		Garage garage = new Garage();
		
		GarageCar car1 = new GarageCar("BMW");
		GarageCar car2 = new GarageCar("Tesla");
		
		garage.park(car1);
		garage.park(car2);
		

	}

}
