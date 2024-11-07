package SuperKeyword;

public class Hero extends Person{
	
	String power;
	
	Hero(String name, int age, String power)
	{
		super(name, age);
		this.power = power;
	}
	
	
	public String toString() {
		return String.format("%s and his power is %s", super.toString(), this.power);
	}

}
