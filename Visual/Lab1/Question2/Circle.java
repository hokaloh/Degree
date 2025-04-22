public class Circle implements Polygon {
    private double radius;
    private double perimeter;
    private double area;

    public Circle(double radius) {
        this.radius = radius;
        setPerimeter();
        setArea();
    }

    @Override
    public void setPerimeter() {
        perimeter = 2 * Math.PI * radius;
    }

    @Override
    public double getPerimeter() {
        return perimeter;
    }

    @Override
    public void setArea() {
        area = Math.PI * radius * radius;
    }

    @Override
    public double getArea() {
        return area;
    }
}

