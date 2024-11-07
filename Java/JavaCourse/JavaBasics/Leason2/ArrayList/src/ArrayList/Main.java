package ArrayList;

import java.util.ArrayList;

public class Main {

	public static void main(String[] args) {
		
		ArrayList<String> foods = new ArrayList<String>();
		
		foods.add("Pizza");
		foods.add("Hamburger");
		foods.add("Hotdog");
		
		for (int i = 0; i < foods.size(); ++i)
		{
			System.out.println(String.format("%s ", foods.get(i)));
		}
		System.out.println();
		
		foods.set(0, "Sushi");
		foods.remove(2);
		
		for (int i = 0; i < foods.size(); ++i)
		{
			System.out.println(String.format("%s ", foods.get(i)));
		}
		System.out.println();
		
		foods.clear();
		
		for (int i = 0; i < foods.size(); ++i)
		{
			System.out.println(String.format("%s ", foods.get(i)));
		}
		
		
		
		//Multi-dimensional array
		
		ArrayList<String> bakery_list = new ArrayList<String>();
		bakery_list.add("Pasta");
		bakery_list.add("Garlic-bread");
		bakery_list.add("Donats");
		
		int i;
		for (i = 0; i < bakery_list.size(); ++i)
		{
			System.out.println(String.format("%s ", bakery_list.get(i)));
		}
		System.out.println();
		
		ArrayList<String> produce_list = new ArrayList<String>();
		produce_list.add("Tomatoes");
		produce_list.add("Zucchini");
		produce_list.add("Peppers");
		
		
		ArrayList<String> drinks_list = new ArrayList<String>();
		drinks_list.add("Soda");
		drinks_list.add("Coffe");
		
		
		ArrayList<ArrayList<String>> grocery_list = new ArrayList<ArrayList<String>>();
		grocery_list.add(bakery_list);
		grocery_list.add(produce_list);
		grocery_list.add(drinks_list);
		
		System.out.println(grocery_list.get(0).get(0));
		System.out.println(grocery_list.get(2).get(1));
		System.out.println();
		
		int j;
		for (i = 0; i < grocery_list.size(); ++i)
		{
			for (j = 0; j < grocery_list.get(i).size(); ++j) 
			{
				System.out.print(String.format("%s ", grocery_list.get(i).get(j)));
			}
			
			System.out.println();
		}
		
		
		
	}

}
