
public class Prob25 {
	public static void main(String[] args) {
		Mypoint p = new Mypoint();
		Mypoint q = new Mypoint();
		
		p.x = 20;
		p.y = 21;
		q.x = 4;
		q.y = 16;
		double d1 = p.getDistance();
		double d2 = q.getDistance();
		System.out.println("The distance from P is " + d1);
		System.out.println("The distance from Q is " + d2);
	}
}
