package Scope;

public class Main {

	public static void main(String[] args) {
		
		final int x = 4;
		//x = 4;		==>		we can't assign new value to a variable marked as final.
		
		final int y; 
		y = 6;
		//this is possible since the variable was not initialized
		//but after assigning a value it can't be modified.
		
		
		DiceRoller dr = new DiceRoller();
		
		
		/*
		Access Modifiers
		
		* Default Access Modifier
			When no access modifier is specified for a class, method, or data member – It is said to be having 
			the default access modifier by default. The data members, classes, or methods that are not declared 
			using any access modifiers i.e. having default access modifiers are accessible only within the same package.
		
		* Private Access Modifier
			The private access modifier is specified using the keyword private. The methods or data members declared as 
			private are accessible only within the class in which they are declared.
			Any other class of the same package will not be able to access these members.
			Top-level classes or interfaces can not be declared as private because:
				private means “only visible within the enclosing class”.
				protected means “only visible within the enclosing class and any subclasses”
			Hence these modifiers in terms of application to classes, apply only to nested classes and not on top-level classes
		
		* Protected Access Modifier
			The protected access modifier is specified using the keyword protected.
			The methods or data members declared as protected are accessible within the same package or subclasses in different packages.
		
		*/

	}

}
