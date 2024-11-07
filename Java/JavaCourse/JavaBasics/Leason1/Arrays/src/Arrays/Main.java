package Arrays;



public class Main {
	
	public static void main(String[] args) {
		
		String[] cars1 = {"Camaro", "Corvette", "Tesla", "BMW"};
		System.out.println(String.format("First car is: %s", cars1[0]));
		
		cars1[0] = "Mustang";
		System.out.println(String.format("First car is: %s", cars1[0]));
		
		
		String[] cars2 = new String[3];
		cars2[0] = "Camaro";
		cars2[1] = "Corvette";
		cars2[2] = "Tesla";
		
		int i;
		for(i = 0; i < cars2.length; ++i)
		{
			System.out.println(cars2[i]);
		}
		
		
		//Multi-dimensional array
		
		String[][] cars3 = 
			{
					{"Camaro", "Corvette", "Silverado"},
					{"Mustang", "Ranger", "F-150"},
					{"Ferrari", "Lambo", "Tesla"}
			};
		
		int j;
		for (i = 0; i < cars3.length; ++i)
		{
			for (j = 0; j < cars3[i].length; ++j)
			{
				System.out.print(String.format("%s ", cars3[i][j]));
			}
			System.out.println();
		}
	}
}
