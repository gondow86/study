
public class Truck extends Car{
	private Goods[] cargo;
	private int baggageNum;
	private int currentNum;
	
	public Truck(int baggageNum) {
		super();
		this.cargo = new Goods[baggageNum];
		this.currentNum = 0;
	}
	
	void addGoods(Goods product) {
		String newType = product.getType();
		int newNum = product.getNum();
		int newUnitPrice = product.getUnitPrice();
		String newDestination = product.getDestination();
		int sum;
		
		for (int i = 0; i < this.currentNum; i++) {
			String alreadyType = cargo[i].getType();
			int alreadyNum = cargo[i].getNum();
			int alreadyUnitPrice = cargo[i].getUnitPrice();
			String alreadyDestination = cargo[i].getDestination();
			
			if (newType == alreadyType && newUnitPrice == alreadyUnitPrice && newDestination == alreadyDestination) {
				sum = newNum + alreadyNum;
				cargo[i].setNum(sum);
				return;
			}
		}
		
		cargo[this.currentNum] = product;
		this.currentNum++;
	}
	
	int totalCargoValue() {
		int total = 0;
		
		for (int i = 0; i < this.currentNum; i++) {
			int num = cargo[i].getNum();
			int unitPrice = cargo[i].getUnitPrice();
			
			total += (num * unitPrice);
		}
		
		return total;
	}
	
	int getTotalCharge() {
		int total = 0;
		int charge;
		
		for (int i = 0; i < this.currentNum; i++) {
			charge = cargo[i].getCharge();
			total += charge;
		}
		
		return total;
	}
	
	void showStatus() {
		int totalValue = totalCargoValue();
		int totalCharge = getTotalCharge();
		String type;
		int num;
		int unitPrice;
		String destination;
		
		System.out.println("Info of Each Good.");
		for (int i = 0; i < this.currentNum; i++) {
			type = cargo[i].getType();
			num = cargo[i].getNum();
			unitPrice = cargo[i].getUnitPrice();
			destination = cargo[i].getDestination();
			
			System.out.println("Type: " + type + " Num: " + num + " UnitPrice: " + unitPrice + " Destination: " + destination);
		}
		System.out.println();
		System.out.println("Info of Total Cargo Value and Total Charge.");
		System.out.print("Total Value: ");
		System.out.println(totalValue);
		System.out.print("Total Charge: ");
		System.out.println(totalCharge);
	}
}
