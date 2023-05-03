
public class SmallGoods extends Goods{
	public SmallGoods(String Type, int num, int unitPrice, String destination) {
		super(Type, num, unitPrice, destination);
	}
	
	int getCharge() {
	    return 1000;
	}
}
