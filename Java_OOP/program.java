import java.util.Scanner;

public class program {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        String name; 

        System.out.println("Enter your name:");
        name = in.nextLine();

        System.err.println("Thanks you for the response.");

        System.err.println("Your name is "+ name);


    }
}