
public class Prob24 {
	public static void main(String[] args) {
		Turtle t = new Turtle();
		t.move(180, 300);
		t.penDown();
		for (int i = 0; i < 12; i++) {
			if (i == 11) {
				t.setColor(java.awt.Color.yellow);
				t.go(60);
			} else {
				if (i % 3 == 0) {
					t.setColor(java.awt.Color.blue);
				} else if(i % 3 == 1) {
					t.setColor(java.awt.Color.red);
				} else {
					t.setColor(java.awt.Color.yellow);
				}
				t.go(60);
				t.rotate(30);
			}
		}
	}
}
