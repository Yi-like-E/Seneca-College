public class Extended extends Base {
	public String s = "Extended";

	public String show() {
		return s;
	}	

	public static void main(String[] x) {
		Extended e = new Extended();
		Base b = e; //implicit casting (upcasting)

		System.out.println("b.show: " + b.show());
		System.out.println("e.show: " + e.show());		
		System.out.println("b.s: " + b.s);
		System.out.println("e.s: " + e.s);
	}
}
