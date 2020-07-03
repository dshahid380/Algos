import java.util.*;

class MyDate{
	private int day;
	private int month;
	private int year;

	MyDate(int day, int month, int year){
		this.day = day;
		this.month = month;
		this.year = year;
	}

	int getDay(){
		return this.day;
	}

	int getMonth(){
		return this.month;
	}

	int getYear(){
		return this.year;
	}

	String getDate(){
		return Integer.toString(this.day) + "/" +
		       Integer.toString(this.month) + "/" +
		       Integer.toString(this.year);
	}

	boolean isValid(){
        if(this.month==2){
        	if(this.isLeapYear()){
        		if(this.day<=29) return true;
        	}else{
        		if(this.day<=28) return true;
        	}
        }else{
        	if(this.month==1 ||
        	  this.month==3 ||
        	  this.month==5 ||
        	  this.month==7 ||
        	  this.month==8 ||
        	  this.month==10 ||
        	  this.month==12) 
        		 if(this.day<=31)
        		 	return true;
        	  if(this.month==4 ||
        	  this.month==6 ||
        	  this.month==9 ||
        	  this.month==11) 
        		 if(this.day<=30)
        		 	return true;	
        }
        return false;
	}

	boolean isLeapYear(){
		if(((this.year%4==0) && (this.year%100!=0)) || (this.year % 400)==0)
			return true;
		else return false;
	}

	int calculateH(){
		int q, m, k, j, year;
		q = this.getDay();
		if(this.getMonth()<=2)
			m = this.getMonth() + 12;
		else 
			m = this.getMonth();
        if(m>12)
        	year = this.getYear() - 1;
        else
        	year = this.getYear();

        k = year % 100;
        j = year / 100;

		int h = (q + (13*(m+1))/5 + k + k/4 + j/4 + 5*j) % 7;
		return h;
	}
}

enum WeekDay{
	MONDAY, TUESDAY, 
	WEDNESDAY, THURSDAY,
	FRIDAY, SATURDAY, 
	SUNDAY; 
}

class MyCalendar{
	MyDate mydate;
	int days[][] = new int[6][7];

	MyCalendar(MyDate newDate){
		mydate = newDate;
	}

	WeekDay dayOfWeek(){
        int h = this.mydate.calculateH();
        if(h == 0) return WeekDay.SATURDAY;
        else if(h == 1) return WeekDay.SUNDAY;
        else if(h == 2) return WeekDay.MONDAY;
        else if(h == 3) return WeekDay.TUESDAY;
        else if(h ==4) return WeekDay.WEDNESDAY;
        else if(h ==5) return WeekDay.THURSDAY;
        else return WeekDay.FRIDAY;
	}

	int weekOfMonth(){

        int hForFirstDay = new MyDate(1,
        							 this.mydate.getMonth(),
        							 this.mydate.getYear()).calculateH();
        int dayNo;
        if(hForFirstDay <= 2)
        	dayNo = hForFirstDay + 4;
        else
        	dayNo = hForFirstDay - 2;
        System.out.println(hForFirstDay);
        int cnt=1;
        int weekNo=0;
        for(int i=0; i<6; i++){
        	for(int j=dayNo; j<7; j++){
                this.days[i][j] = cnt; 
                if(cnt==this.mydate.getDay()) weekNo=i+1;
                cnt++;  
        	}
        	dayNo = 0;
        }
        return weekNo;
	}

	 void printMonth(){
	 	 int totalDay=30;
	 	 if(this.mydate.getMonth()==2){
        	if(this.mydate.isLeapYear()){
        		totalDay = 29;
        	}else{
        		totalDay = 28;
        	}
        }else{
        	if(this.mydate.getMonth()==1 ||
        	  this.mydate.getMonth()==3 ||
        	  this.mydate.getMonth()==5 ||
        	  this.mydate.getMonth()==7 ||
        	  this.mydate.getMonth()==8 ||
        	  this.mydate.getMonth()==10 ||
        	  this.mydate.getMonth()==12) 
        		 totalDay = 31;
        		 	
        	  if(this.mydate.getMonth()==4 ||
        	  this.mydate.getMonth()==6 ||
        	  this.mydate.getMonth()==9 ||
        	  this.mydate.getMonth()==11) 
        		 totalDay = 30;
        }

        System.out.print("MON"+"   "+"TUE"+"   ");
        System.out.print("WED"+"   "+"THU"+"   ");
        System.out.print("FRI"+"   "+"SAT"+"   ");
        System.out.println("SUN");
        
        int cnt=1;
        for(int i=0; i<6; i++){
        	for(int j=0; j<7 && cnt<=totalDay; j++){
            	if(this.days[i][j]>0){
            		System.out.print(days[i][j]);
            		cnt++;
            	}
            	else
            		System.out.print(" ");
            	System.out.print("    ");
        	}
        	System.out.println("");
        }    
	 }

	public static void main(String args[]){
		Scanner sc = new Scanner(System.in);
		String[] num = new String[]{"First", "Second",
								  "Third", "Fourth",
								  "Fifth", "Sixth"};
		String[] monthName = new String[]{"January", "February",
										"March", "April","May",
									    "May", "June", "July",
									    "August","September",
									    "October", "November",
									    "December"};						  
		while(true){
			String input = sc.nextLine();
			String str[] = input.split("/");
			int day = Integer.parseInt(str[0]);
			int month = Integer.parseInt(str[1]);
			int year = Integer.parseInt(str[2]);

			MyDate mydate = new MyDate(day, month, year);
			if(mydate.isValid()){
                MyCalendar mycalendar = new MyCalendar(mydate);
                String s = input + "is a "+mycalendar.dayOfWeek()+" and locates in the "+
                           num[mycalendar.weekOfMonth()-1] + " week of "+ monthName[month-1]+
                           str[2];
                System.out.println(s);
                mycalendar.printMonth();
                break;            
			}
			else{
				System.out.println("Please Enter valid date");
			}
		}		
	}
}