package package1;
import package2.*;

public class A {

	public static void main(String[] args) {
		
		 
		C c = new C();
		
		// default access modifier example:
		//System.out.println(c.default_message);
		/*
		This won't work since everything with the default access modifier is accessible only within it's own package.
		it will be available in Asub (see class) 
		*/
		
		
		// public access modifier example:
		System.out.println(c.public_message);
		/*
		anything with public keyword is accessible to any package in the project.
		*/
		
		
	}

}
