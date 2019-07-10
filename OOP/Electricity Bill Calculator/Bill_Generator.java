package bill;
class BillGenerator {
	int consumerNo;
	String consumerName, connectionType;

	BillGenerator(int consumerNo, 
		         String consumerName, 
		         String connectionType) {
		this.consumerNo = consumerNo;
		this.consumerName = consumerName;
		this.connectionType = connectionType;
	}

    double unitsToRupees(double rate1,
                         double rate2, 
                         double rate3, 
                         double rate4, 
                         int units) {
    	double rupees ;
        if(units <= 100) 
            rupees = 100*rate1;
        else if(units > 100 && units <= 200) 
            rupees = 100*rate1 + (200-100)*rate2; 
        else if(units >200 && units <= 500)
            rupees = 100*rate1 + 100*rate2 + (units-200)*rate3;
        else
            rupees = 100*rate1 + 100*rate2 + 300*rate3 + (units-500)*rate4;
        return rupees;

    }

	double calculate(int prevReading, int currReading) {
		  int units = currReading - prevReading;
          if(this.connectionType.equals("Domestic"))
              return unitsToRupees(1.0, 2.50, 4.0, 6.0, units);
          else
          	  return unitsToRupees(2.0, 4.50, 6.0, 7.0, units);
	}

	void display(int prevReading, int currReading) {
		System.out.println("Electricity Bill Information");
		System.out.println("-----------------------------");
		System.out.println("Bill ID : "+this.consumerNo);
		System.out.println("Name : "+this.consumerName);
		System.out.println("Bill Type : "+this.connectionType);
		System.out.println("Rupees : "+this.calculate(prevReading,currReading));
	}

}

