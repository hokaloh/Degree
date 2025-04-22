public class Van extends Vehicle {

    public Van(int seater, int wheel, int door, String model, double price) {
        setSeater(seater);
        setWheel(wheel);
        setDoor(door);
        setModel(model);
        setPrice(price);
    }

    @Override
    public void addFuel() {
        System.out.println("Adding diesel to the van.");
    }
}
