import java.util.Scanner;

public class lab2_4 {

    static final double pi = 3.14; 

    static double area (double radius){ 
        return radius * radius * pi;
    } 

    static double volume (double area, double length){
        return area * length;
    }
    public static void main(String[] args) {
        
        Scanner input = new Scanner(System.in);
        
        System.out.println("radius: ");
        double radius = input.nextDouble();

        System.out.println("length: ");
        double length = input.nextDouble();

        double area = area(radius);
        System.out.println("area: " + area);

        double volume = volume(area, length);
        System.out.println("volume: " + volume);
        
    }
}
