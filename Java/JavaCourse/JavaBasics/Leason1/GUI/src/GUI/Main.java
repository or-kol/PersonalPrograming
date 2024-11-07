package GUI;

import javax.swing.JOptionPane; 

public class Main {

	public static void main(String[] args) {
		
		String name = JOptionPane.showInputDialog("Enter Your Name:");
		JOptionPane.showMessageDialog(null, String.format("Hello %s", name));
		
		int age = Integer.parseInt(JOptionPane.showInputDialog("Enter Your age:"));
		JOptionPane.showMessageDialog(null, String.format("You are %d years old", age));
		
		
		Double height = Double.parseDouble(JOptionPane.showInputDialog("Enter Your height:"));
		JOptionPane.showMessageDialog(null, String.format("You are %.2f cm tall", height));
	}

}
