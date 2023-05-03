
public class PentagonVertex extends Vertex{
	void draw(Turtle t) {
		t.setColor(java.awt.Color.blue);
		t.penDown();
		t.go(8);
		t.rotate(72);
		t.go(8);
		t.rotate(72);
		t.go(8);
		t.rotate(72);
		t.go(8);
		t.rotate(72);
		t.go(8);
	}
}
