class Test{  
   public static void main(){
   	System.out.println("Hey Buddy!");
   }
   public static void main(String str){
   	   System.out.println("My Name is "+str);
   }
   public static void main(String args[]){
   	   System.out.println("This is main method.");
   	   main();
   	   main("Shahid");
   } 
}  