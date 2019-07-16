import java.util.*;
class redone {
	static long MOD=1000000007;
	static long[] dp = new long[1000005];
	static void preprocess() {
		dp[1] = 1;
		for(int i=2; i<1000005; i++) {
			dp[i] = ((dp[i-1] + (long)i)%MOD + ((dp[i-1]%MOD)*((long)i%MOD))%MOD)%MOD;
			//System.out.println(i+" -> "+dp[i]);
		}
	}
	public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();
        preprocess();

        
        while(T-->0) {
        	int a = sc.nextInt();
        	System.out.println(dp[a]);
        } 
	}
}