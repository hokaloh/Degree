package mycar;

public class Car {
    private double kmh;

    public Car() {
        kmh = 0;
    }

    public void accelerate() {
        kmh += 10;
    }

    public void decelerate() {
        if (kmh >= 5) {
            kmh -= 5;
        } else {
            kmh = 0;
        }
    }

    public void brake() {
        kmh = 0;
    }

    public double getKmh() {
        return kmh;
    }
}
