public class Main {
    public static void main(String[] args) {
        Polygon circle = new Circle(5);
        Polygon rectangle = new Rectangle(4, 7);
        Polygon triangle = new Triangle(3, 4, 5);

        System.out.println("Circle:");
        System.out.println("Perimeter: " + circle.getPerimeter());
        System.out.println("Area: " + circle.getArea());

        System.out.println("\nRectangle:");
        System.out.println("Perimeter: " + rectangle.getPerimeter());
        System.out.println("Area: " + rectangle.getArea());

        System.out.println("\nTriangle:");
        System.out.println("Perimeter: " + triangle.getPerimeter());
        System.out.println("Area: " + triangle.getArea());
    }
}
