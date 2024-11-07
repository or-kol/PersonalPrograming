package SuperKeyword;

public class Mian {

	public static void main(String[] args) {
		
		Hero hero1 = new Hero("Batman", 42, "$$$");
		System.out.println(hero1);
		
		Hero hero2 = new Hero("Superman", 43, "everything");
		System.out.println(hero2);
		
		Person person = new Person("John", 23);
		System.out.println(person);
		
	}

}
