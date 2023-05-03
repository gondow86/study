
public class Prob23 {
	public static void main(String[] args) {
		Turtle t1 = new Turtle();
		Turtle t2 = new Turtle();
		
		t1.move(10, 100); t2.move(210, 100);
		t1.penDown();     t2.penDown();
		t1.go(60);        t2.go(60);
		t1.rotate(90);    t2.rotate(72);
		t1.go(60);        t2.go(60);
		t1.rotate(90);    t2.rotate(72);
		t1.go(60);        t2.go(60);
		t1.rotate(90);    t2.rotate(72);
		t1.go(60);        t2.go(60);
		                  t2.rotate(72);
		                  t2.go(60);
	}
}
