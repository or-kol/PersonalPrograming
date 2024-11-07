package StaticKeyword;

public class Main {

	public static void main(String[] args) {
		
		Friend friend1 = new Friend("Bro");
		Friend friend2 = new Friend("Jhon");
		System.out.println(Friend.num_of_friends);
		
		Friend friend3 = new Friend("Max");
		System.out.println(Friend.num_of_friends);
		
		System.out.println(friend1.num_of_friends); 
		// It's possible to access a static variable with an instance of the class, but It's not recommended.
		// Best practice is to use the class (like in the first two examples).
		
		Friend friend4 = new Friend("Sandy");
		//static method:
		Friend.displayFriends();
		
		/*
		* Static
			In Java, a static method is a method that belongs to the class itself rather than to any specific instance (object) 
			of the class.Static methods can be called without creating objects.This means that you can call a static method using 
			the class name directly, without needing to create an object of the class. static methods are often used for utility 
			functions, helper methods, or operations that don't require any instance-specific data.
		
		* Public
			In Java, a public method is a method that can be accessed and called from any other class or package. It is one of the 
			four access modifiers in Java, along with private, protected, and package-private (default access).
		*/
	}

}
