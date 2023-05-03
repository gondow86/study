
public class MediumGoods extends Goods{
	public MediumGoods(String Type, int num, int unitPrice, String destination) {
		super(Type, num, unitPrice, destination);
	}
	
	int getCharge() {
		return 2000;
	}
}
