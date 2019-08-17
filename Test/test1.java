class Init{
	static int[] A = new int[100];
    
    
    static 
	{
		for(int i=0; i<100; i++){
		A[i]=i;
		} 
    }

    int get(int idx){
    	return A[idx];
    }
}

class Test{
	public static void main(String args[]){
		Init it = new Init();
		System.out.println(it.get(44));
	}
}