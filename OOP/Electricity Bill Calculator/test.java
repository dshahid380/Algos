import bill.*;
class test {
	public static void main(String args[]) {
		//Test 1
		BillGenerator bg1 = new BillGenerator(1234, "Shahid", "Domestic");
		BillGenerator bg2 = new BillGenerator(12345, "Adrika", "Commercial");

		if(bg1.calculate(1000, 2000)==4550.0)
			System.out.println("Test case 1 passed");
		else
			System.out.println("Test case 1 failed");

		if(bg2.calculate(1000, 2000)==5950.0)
			System.out.println("Test case 2 passed");
		else
			System.out.println("Test case 2 failed");


	}
}