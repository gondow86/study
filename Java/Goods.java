
public abstract class Goods {
	private String type;
	private int num;
	private int unitPrice;
	private String destination;
	
	public Goods(String type, int num, int unitPrice, String destination) {
		this.type = type;
		this.num = num;
		this.unitPrice = unitPrice;
		this.destination = destination;
	}
	
	String getType() {
		return this.type;
	}
	
	int getNum() {
		return this.num;
	}
	
	int getUnitPrice() {
		return this.unitPrice;
	}
	
	String getDestination() {
		return this.destination;
	}
	
	void setDestination(String destination) {
		this.destination = destination;
	}
	
	void setNum(int num) {
		this.num = num;
	}
	
	int getTotalPrice() {
		return this.num * this.unitPrice;
	}
	
	void print() {
		System.out.println("Type: " + this.type + " Num: " + this.num + " UnitPrice: " + this.unitPrice + " Destination " + this.destination);
	}
	
	abstract int getCharge();
}
