import java.util.*;
class test {
	static int solve(int matrixsize, List<String> cmds) {
		
		int a[][] = new int[matrixsize][matrixsize];

		for(int i=0; i<matrixsize; i++) {
			for(int j=0; j<matrixsize; j++) {
				a[i][j] = i*matrixsize + j;
			}
		}
        
        int pos1 = 0, pos2 = 0;
		for(int i=0; i<cmds.size(); i++) {

             String str = cmds.get(i);
			if(str.equals("UP")) {
				pos1--;
				if(pos1<0)
					pos1 = 0;
			}
			if(str.equals("LEFT")) {
				pos2--;
				if(pos2<0)
					pos2=0;
			}
			if(str.equals("RIGHT")) {
				pos2++;
				if(pos2>=matrixsize)
					pos2=matrixsize-1;
			}
			if(str.equals("DOWN")) {
				pos1++;
				if(pos1>=matrixsize)
					pos1=matrixsize-1;
			}

		}
		return a[pos1][pos2];
	}

	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		while(T-->0) {
			int a = sc.nextInt();
			int b = sc.nextInt();
			String s;
			List<String> l = new ArrayList<String>();
			for(int i=0; i<=b; i++) {
                 s = sc.nextLine();
                 l.add(s);
			}
			System.out.println(solve(a, l));
		}
	}
}