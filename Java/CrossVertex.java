
public class CrossVertex extends Vertex{
	void draw(Turtle t) {
		t.setColor(java.awt.Color.blue);
		t.penDown();
		t.go(10);
		t.penUp();
		t.rotate(90);
		t.go(5);
		t.rotate(90);
		t.go(5);
		t.rotate(90);
		t.penDown();
		t.go(10);
	}
}
