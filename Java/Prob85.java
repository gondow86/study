
public class Prob85 {
	public static void main(String[] args) {
		int a;
		int b;
		int c;
		try {
			a = Integer.valueOf(args[0]);
			b = Integer.valueOf(args[1]);
			c = a / b;
			System.out.println(c);
		} catch(ArrayIndexOutOfBoundsException e) {
			System.out.println("Please enter two numbers!");
		} catch(ArithmeticException e) {
			System.out.println("Denominator must not be zero!");
		}
	}
}
