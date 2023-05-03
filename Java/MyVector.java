
public class MyVector {
	private double[] elements;
	static int count = 0;
	
	public MyVector() {
		this.elements = new double[2];
		this.elements[0] = 0.0;
		this.elements[1] = 0.0;
		count++;
	}
	
	public MyVector(double x, double y) {
		this.elements = new double[2];
		this.elements[0] = x;
		this.elements[1] = y;
		count++;
	}
	
	MyVector constMult(double k) {
		this.elements[0] = k * this.elements[0];
		this.elements[1] = k * this.elements[1];
		
		return this;
	}
	
	double getLength() {
		return Math.sqrt(this.elements[0] * this.elements[0] + this.elements[1] * this.elements[1]);
	}
	
	boolean isEqual(MyVector v) {
		boolean b = false;
		if (this.elements[0] == v.elements[0] && this.elements[1] == v.elements[1]) {
			b = true;
		}
		
		return b; 
	}
	
	static int getNumVec() {
		return count;
	}
	
	void print() {
		System.out.println("(" + this.elements[0] + ", " + this.elements[1] + ")");
	}
}
