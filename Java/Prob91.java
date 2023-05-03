import java.util.*;

class Prob91 {
	private int processInput(String inString, int prev) {  
		String[] inputs = inString.split("\\s+");
		int result = prev;
		for (int i=0; i<inputs.length; i++) {
			if (inputs[i].compareTo("quit") == 0) {
				System.exit(0);
			}
			if (inputs[i].compareTo("finish") == 0) {
				System.out.println(result);
				result = 0;
			} else {
				result += Integer.valueOf(inputs[i]);
			}
			
		}
		return result;
	}

	public static void main(String[] args) {
		int result = 0;
		Prob91 app = new Prob91();
		Scanner scan = new Scanner(System.in);
		while (true) {
			System.out.println("Please input numbers: ");
			String str = scan.nextLine();
			result = app.processInput(str, result);
		}
	}
}

