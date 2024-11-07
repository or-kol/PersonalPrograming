package Inheritance;

public class Main {

	public static void main(String[] args) {
		
		Car car = new Car();
		Bicycle bike = new Bicycle();
		
		car.go();
		bike.stop();
		
		System.out.println(car.speed);
		System.out.println(bike.speed);
		
		System.out.println(car.doors);
		System.out.println(bike.pedals);
		System.out.println(car.wheels);
		System.out.println(bike.wheels);

	}

}
