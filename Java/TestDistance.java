
public class TestDistance {
	public static void main(String args[]) {
		MyPoint p = new MyPoint();
		MyPoint q = new MyPoint();
		p.setPoint(20, 21);
		q.setPoint(4, 23);
		
		double d = p.getDistanceFrom(q);
		System.out.println("d = " + d);
	}
}
