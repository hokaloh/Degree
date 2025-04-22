public class Rectangle implements Polygon {
    private double length, width;
    private double perimeter;
    private double area;

    public Rectangle(double length, double width) {
        this.length = length;
        this.width = width;
        setPerimeter();
        setArea();
    }

    @Override
    public void setPerimeter() {
        perimeter = 2 * (length + width);
    }

    @Override
    public double getPerimeter() {
        return perimeter;
    }

    @Override
    public void setArea() {
        area = length * width;
    }

    @Override
    public double getArea() {
        return area;
    }
}
