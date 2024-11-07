package OverloadedConstructors;

public class Main {

	public static void main(String[] args) {
		
		Pizza pizza1 = new Pizza("thick crust", "tomato", "mozzarella", "pepperoni");
		
		System.out.printf("The ingredients of your pizza: %s, %s, %s, %s\n", 
				pizza1.bread, pizza1.souce, pizza1.cheese, pizza1.topping);
		
		
		Pizza pizza2 = new Pizza("thick crust", "tomato", "mozzarella");
		
		System.out.printf("The ingredients of your pizza: %s, %s, %s, %s\n", 
				pizza2.bread, pizza2.souce, pizza2.cheese, pizza2.topping);
		
		System.out.printf("The ingredients of your pizza: %s, %s, %s\n", 
				pizza2.bread, pizza2.souce, pizza2.cheese);
	}

}
