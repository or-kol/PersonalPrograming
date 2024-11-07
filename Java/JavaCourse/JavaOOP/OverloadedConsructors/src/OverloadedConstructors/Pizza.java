package OverloadedConstructors;

public class Pizza {
	
	String bread;
	String souce;
	String cheese;
	String topping;
	
	Pizza(String bread, String souce, String cheese, String topping)
	{
		this.bread = bread;
		this.souce = souce;
		this.cheese = cheese;
		this.topping = topping;
	}
	
	Pizza(String bread, String souce, String cheese)
	{
		this.bread = bread;
		this.souce = souce;
		this.cheese = cheese;
	}
	
	void bake()
	{
		
	}
}
