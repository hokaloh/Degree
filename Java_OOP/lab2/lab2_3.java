import java.util.Scanner;

public class lab2_3 {

    static double x1(double a, double b, double c){
        return (-b + Math.sqrt(b * b - 4 * a * c)) / 2 * a;
    }

    static double x2(double a, double b, double c){
        return (-b - Math.sqrt(b * b - 4 * a * c)) / 2 * a;
    }

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);

        double a; 
        do{
            System.out.println("a: ");
            a = input.nextDouble();
        }while(a == 0);

        System.out.println("b: ");
        double b = input.nextDouble();

        System.out.println("c: ");
        double c = input.nextDouble();

        System.out.println("x1 = " + x1(a, b, c));
        System.out.println("x2 = " + x2(a, b, c));
    }
}