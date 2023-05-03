import java.io.*;
import java.util.*;

public class Prob92 {
	public static void main(String[] args) {
		int word_counter = 0;
		int char_counter = 0;
		
		try {
			File file = new File("message.txt");
			Scanner scan = new Scanner(file);
			FileWriter fw = new FileWriter("output92.txt");
			while(scan.hasNextLine()) {
				String str = scan.nextLine();
				String[] inputs = str.split("");
				for (int i = 0; i < inputs.length; i++) {
					if (i > 0 && inputs[i].compareTo(" ") == 0 || inputs[i].compareTo(".") == 0) {
						word_counter++;
					}
					if (inputs[i].length() == 0) {
						char_counter--;
					}
				}
				char_counter += inputs.length;
				fw.write(word_counter + " " + char_counter + ": " + str);
				if (scan.hasNextLine()) {
					fw.write("\n");
				}
				word_counter = 0;
				char_counter = 0;
			}
			fw.close();
			
		} catch(NullPointerException e) {
			System.err.println("NullPointerException" + " " + e.toString());
		} catch(IOException e) {
			System.err.println("IOException" + " " + e.toString());
		}
	}
}