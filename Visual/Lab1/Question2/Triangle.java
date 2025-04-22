public class Triangle implements Polygon {
    private double sideA, sideB, sideC;
    private double perimeter;
    private double area;

    public Triangle(double a, double b, double c) {
        this.sideA = a;
        this.sideB = b;
        this.sideC = c;
        setPerimeter();
        setArea();
    }

    @Override
    public void setPerimeter() {
        perimeter = sideA + sideB + sideC;
    }

    @Override
    public double getPerimeter() {
        return perimeter;
    }

    @Override
    public void setArea() {
        double s = perimeter / 2;
        area = Math.sqrt(s * (s - sideA) * (s - sideB) * (s - sideC));
    }

    @Override
    public double getArea() {
        return area;
    }
}
