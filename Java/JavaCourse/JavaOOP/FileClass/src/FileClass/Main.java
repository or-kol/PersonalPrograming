package FileClass;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

public class Main {

	public static void main(String[] args) {
		
		File file = new File("Message.txt");
		//if the file is not in the project folder we will need the full path:
		//File file = new File("C:\\Users\\User\\OneDrive\\Desktop\\Message.txt");
		
		if (file.exists())
		{
			System.out.println("That file exists!");
			System.out.println(file.getPath());
			System.out.println(file.getAbsolutePath());
			System.out.println(file.isFile());
			System.out.println(file.delete());
		}
		else
		{
			System.out.println("That file doesn't exists!");
		}
		
		
		
		  
		//FileWriter
		try 
		{
			FileWriter writer = new FileWriter("poem.txt");
			writer.write("Roses are red,\nViolets are blue,\nSugar is sweet,\nAnd so are you.");
			writer.append("\n\nA poem");
			writer.close();
		}
		catch (Exception e) {
			e.printStackTrace();
		}
		
		
		
		
		//FileReader
		try
		{
			FileReader reader = new FileReader("poem.txt");
			
			int data = reader.read();
			while (data != -1)
			{
				System.out.print((char)data);
				data = reader.read();
			}
			reader.close();
		}
		catch (FileNotFoundException e) {
			e.printStackTrace();
		}
		catch (IOException e) {
			e.printStackTrace();
		}
		
	}

}
