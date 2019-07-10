import bill.*;
class Main {
	public static void main(String args[]) {
        BillGenerator bg = new BillGenerator(1234, "Md Shahid", "Domestic");
        bg.display(1000,2000);
	}
}