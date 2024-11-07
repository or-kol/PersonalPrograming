package Objects;

public class Food {
	
	String name;
	
	Food(String name)
	{
		this.name = name;
	}
	
	public String toString()
	{
		return String.format("%s ", this.name);
	}
}
