class Temp {
    public static int solve(int n) throws Exception{
        if(n<0){
            throw new Exception("");
        }
        int a = 0, b = 1, ans = 0;
        for(int i = 0; i < n; i++){
            ans += b;
            int c = b;
            b = a + b;
            a = c;
        }
        return ans;
    }

    public static void main(String[] args) throws Exception {
        System.out.println(solve(4));
        System.out.println(solve(5));
    }
}
