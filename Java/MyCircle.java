
public class MyCircle {
	Mypoint center;
	int radius;
	
	void setCircle(int x, int y, int r) {
		center.x = x;
		center.y = y;
		radius = r;
	}
	
	int computeDiameter() {
		return 2 * radius;
	}
	
	double computeArea() {
		return radius * radius * Math.PI;
	}
	
	double computeCircumference() {
		return computeDiameter() * Math.PI;
	}
}