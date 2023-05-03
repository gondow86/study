
public class Prob76 {
	public static void main(String[] args) {
		double d;
		double r = 6371;
		double lat1 = Double.parseDouble(args[0]) * Math.PI / 180;
		double lon1 = Double.parseDouble(args[1]) * Math.PI / 180;
		double lat2 = Double.parseDouble(args[2]) * Math.PI / 180;
		double lon2 = Double.parseDouble(args[3]) * Math.PI / 180;
		double tmp = Math.pow(Math.sin((lat2 - lat1)/2), 2.0) + Math.cos(lat1) * Math.cos(lat2) * Math.pow(Math.sin((lon2 - lon1)/2), 2.0);
		
		d = 2 * r * Math.asin(Math.sqrt(tmp));
		System.out.println(d);
	}
}
