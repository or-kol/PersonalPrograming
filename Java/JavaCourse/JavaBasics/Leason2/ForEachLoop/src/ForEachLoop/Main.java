package ForEachLoop;

import java.util.ArrayList;

public class Main {

	public static void main(String[] args) {
		
		String[] animals_arr = {"Cat", "Dog", "Rat", "Bird"};
		
		for(String i : animals_arr)
		{
			System.out.println(i);
		}
		
		
		ArrayList<String> animals_lst = new ArrayList<String>();
		animals_lst.add("Cat");
		animals_lst.add("Dog");
		animals_lst.add("Rat");
		animals_lst.add("Bird");
		
		for(String i : animals_lst)
		{
			System.out.println(i);
		}

	}

}
