
public class BigGoods extends Goods{
	public BigGoods(String Type, int num, int unitPrice, String destination) {
		super(Type, num, unitPrice, destination);
	}
	
	int getCharge() {
		return 3000;
	}
}
