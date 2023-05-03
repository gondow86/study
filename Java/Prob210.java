
public class Prob210 {
	public static void main(String[] args) {
		Mypoint p = new Mypoint();
		MyCircle c = new MyCircle();
		c.center = p;
		
		c.setCircle(20, 21, 9);
		double area = c.computeArea();
		double circumference = c.computeCircumference();
		System.out.println("The area of the circle is " + area + ", and the circumference is " + circumference);
	}
}
