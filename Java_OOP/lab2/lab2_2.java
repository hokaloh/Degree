public class lab2_2 {
    static int[] num_a = {1,2,3,4,5}; 
    static int[] num_b = {2,3,4,5,6};
    
        static double calpower(int a, int b){
            return Math.pow(a, b);
        }
    
        public static void main(String[] args) {
            System.out.println("a \t b \t a to the power of b");
            for (int i=0;i<5;i++){
                System.out.println(num_a[i] + "\t" + num_b[i] + "\t" + calpower(num_a[i], num_b[i]));
        }    
    }
    


}
