package ToStringMethod;

public class Car {
	
	String make;
	String model;
	String color;
	int year;
	
	Car(String make, String model, String color, int year)
	{
		this.make = make;
		this.model = model;
		this.color = color;
		this.year = year;
	}
	
	public String toString()
	{
		return String.format("Maker: %10s\nModel: %10s\nColor: %10s\nYear:  %10d\n", 
				this.make, this.model, this.color, this.year);
	}
	

}
