import java.io.*;
import java.util.*;

public class Prob93 {
	public static void main(String[] args) {
		double ans = 0;
		
		try {
			File file = new File("numbers.txt");
			Scanner scan = new Scanner(file);
			FileWriter fw = new FileWriter("result93.txt");
			while(scan.hasNextLine()) {
				String str = scan.nextLine();
				String[] inputs = str.split("\\s+");
				ans = Double.valueOf(inputs[0]);
				for (int i = 1; i < inputs.length; i++) {
					if (inputs[i].equals("+")) {
						ans = ans + Double.valueOf(inputs[i+1]);
					} else if (inputs[i].equals("-")) {
						ans = ans - Double.valueOf(inputs[i+1]); 
					} else if (inputs[i].equals("*")) {
						ans = ans * Double.valueOf(inputs[i+1]);
					} else if (inputs[i].equals("/")) {
						ans = ans / Double.valueOf(inputs[i+1]);
					}
				}
				fw.write(str + " = " + ans);
				if (scan.hasNextLine()) {
					fw.write("\n");
				}
				ans = 0;
			}
			fw.close();
			
		} catch(IOException e) {
			System.err.println("IOException" + " " + e.toString());
		} catch(NumberFormatException e) {
			System.err.println("NumberFormatException" + " " + e.toString());
		}
	}
}
