package lab2;

public class Iphone {
    String model;
    double price; 

    public Iphone(String model, double price){
        this.model = model;
        this.price = price;
    }

    public void display() {
        System.out.println("iphone model : " + model);
        System.out.println("Price: RM" + price);
    }
}
