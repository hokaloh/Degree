public class Car extends Vehicle {

    public Car(int seater, int wheel, int door, String model, double price) {
        setSeater(seater);
        setWheel(wheel);
        setDoor(door);
        setModel(model);
        setPrice(price);
    }

    @Override
    public void addFuel() {
        System.out.println("Adding petrol to the car.");
    }
}
