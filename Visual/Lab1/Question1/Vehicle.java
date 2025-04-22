public abstract class Vehicle {
    private int seater;
    private int wheel;
    private int door;
    private String model;
    private double price;

    // setter method for the attributes
    public void setSeater(int seater){ 
        this.seater = seater; 
    }
    public void setWheel(int wheel){ 
        this.wheel = wheel; 
    }
    public void setDoor(int door){ 
        this.door = door;
    }
    public void setModel(String model){ 
        this.model = model; 
    }
    public void setPrice(double price){ 
        this.price = price; 
    }

    // getter method for attributes
    public int getSeater(){ 
        return seater; 
    }
    public int getWheel(){ 
        return wheel; 
    }
    public int getDoor(){ 
        return door;
    }
    public String getModel(){ 
        return model;
    }
    public double getPrice(){ 
        return price;
    }

    // Abstract method for addfuel
    public abstract void addFuel();
}
