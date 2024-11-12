package lab2;

public class Main {
    public static void main(String[] args) {
        Iphone myphone = new Iphone("Iphone 14", 5600.00);
        Faculty lecture = new Faculty("Dr Samad Ali", "Computer Science");
        
        myphone.display();
        lecture.display();
    }
}
