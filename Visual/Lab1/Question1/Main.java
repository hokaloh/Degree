public class Main {
    public static void main(String[] args) {
        Car car = new Car(5, 4, 4, "Toyota", 85000);
        Van van = new Van(12, 4, 4, "Nissan", 120000);

        System.out.println("Car:");
        System.out.println(car.getModel() + " - " + car.getSeater() + " seats, " + car.getDoor() + " doors, " + car.getWheel() + " wheels, RM" + car.getPrice());
        car.addFuel();

        System.out.println("\nVan:");
        System.out.println(van.getModel() + " - " + van.getSeater() + " seats, " + van.getDoor() + " doors, " + van.getWheel() + " wheels, RM" + van.getPrice());
        van.addFuel();
    }
}
