import java.text.DecimalFormat;
import java.util.Scanner;

public class lab3_4 {

    public static double celsiusToFahrenheit(double celsius){
        return (9.0/5) * celsius + 32;
    }

    public static double fahrenheitToCelsius(double fahrenheit){
        return (5.0/9) * (fahrenheit - 32);
    }
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        DecimalFormat df = new DecimalFormat("#.##");

        System.out.print("Enter celsius: ");
        double celsius = input.nextDouble();

        System.out.print("Enter fahrenheint: ");
        double fahrenheint = input.nextDouble();

        System.out.println("Celsius To Fahrenheit: " + df.format(celsiusToFahrenheit(celsius)));
        System.out.println("Fahrenheit To Celsius: "+ df.format(fahrenheitToCelsius(fahrenheint)));
    }
}
