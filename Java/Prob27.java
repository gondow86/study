
public class Prob27 {
	public static void main(String[] args) {
		ComplexNumber c1 = new ComplexNumber();
		ComplexNumber c2 = new ComplexNumber();
		
		c1.real = 1;
		c1.imaginary = 2;
		c2.real = 3;
		c2.imaginary = 4;
		
		c1.print();
		double abs1 = c1.abs();
		System.out.println("Absolute num of c1 is " + abs1);
		c2.print();
		double abs2 = c2.abs();
		System.out.println("Absolute num of c2 is " + abs2);
	}
}
