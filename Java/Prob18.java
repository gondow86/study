
public class Prob18 {
	public static void main(String[] args) {
		int num = 210409;
		int max = 0;
		for (int i = 1; i < num; i++) {
			if (num % i == 0) {
			    max = i;
			}
		}
		if (max > 1) {
			System.out.println("This isn't a prime number. Max divisor is " + max + ".");
		} else {
			System.out.println("This is a prime number.");
		}
	}
}