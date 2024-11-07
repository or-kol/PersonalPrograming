package StaticKeyword;

public class Friend {
	
	String name;
	static int num_of_friends;
	Friend(String name)
	{
		this.name = name;
		num_of_friends++;
	}
	
	static void displayFriends()
	{
		System.out.printf("You have %d friends", num_of_friends);
	}
	
}
