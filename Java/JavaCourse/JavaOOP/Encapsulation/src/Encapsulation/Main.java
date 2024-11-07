package Encapsulation;

public class Main {

	public static void main(String[] args) {
		
		// Encapsulation = 	attributes of a class will be hidden or private, 
		//					Can be accessed only through methods (getters & setters)
		//					You should make attributes private if you don't have a reason to make them public/protected
		
		
		Car car1 = new Car("Chevrolet", "Camero", 2021);
		System.out.println(car1.getMake());
		System.out.println(car1.getModel());
		System.out.println(car1.getYear());
		
		
		car1.setMake("BMW");
		car1.setModel("X1");
		car1.setYear(2018);
		
		System.out.println();
		System.out.println(car1.getMake());
		System.out.println(car1.getModel());
		System.out.println(car1.getYear());
		
		
		
		// Copy objects:
		Car car2 = new Car("Ford","Mustang",2022);
		car2.copy(car1);
		
		Car car3 = new Car(car1);
		
		System.out.println();
		System.out.println(car1);
		System.out.println(car1.getMake());
		System.out.println(car1.getModel());
		System.out.println(car1.getYear());
		
		System.out.println();
		System.out.println(car2);
		System.out.println(car2.getMake());
		System.out.println(car2.getModel());
		System.out.println(car2.getYear());
		
		System.out.println();
		System.out.println(car3);
		System.out.println(car3.getMake());
		System.out.println(car3.getModel());
		System.out.println(car3.getYear());
		
	}

}
