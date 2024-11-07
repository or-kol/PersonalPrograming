package Objects;

public class GarageCar {
	
	String name;
	
	GarageCar(String name)
	{
		this.name = name;
	}
	
	public String toString()
	{
		return String.format("%s", this.name);
	}
	
}
