package honda;

import mycar.Car;

public class HondaFK8R {
    public static void main(String[] args) {
        Car myCar = new Car();

        // Invoke accelerate() 10 times
        for (int i = 0; i < 10; i++) {
            myCar.accelerate();
        }

        // Invoke getKmh()
        System.out.println("Speed after accelerating 10 times: " + myCar.getKmh() + " km/h");

        // Invoke decelerate() 2 times
        for (int i = 0; i < 2; i++) {
            myCar.decelerate();
        }

        // Invoke getKmh()
        System.out.println("Speed after decelerating 2 times: " + myCar.getKmh() + " km/h");

        // Invoke accelerate() 3 times
        for (int i = 0; i < 3; i++) {
            myCar.accelerate();
        }

        // Invoke getKmh()
        System.out.println("Speed after accelerating 3 more times: " + myCar.getKmh() + " km/h");

        // Invoke brake()
        myCar.brake();

        // Invoke getKmh()
        System.out.println("Speed after applying brakes: " + myCar.getKmh() + " km/h");
    }
}
