
public class RectVertex extends Vertex{
	void draw(Turtle t) {
		t.setColor(java.awt.Color.blue);
		t.penDown();
		t.go(5);
		t.rotate(90);
		t.go(5);
		t.rotate(90);
		t.go(5);
		t.rotate(90);
		t.go(5);
	}
}
