package com.app.shapes;

public class Circle {

    Background background;
    private double radius;

    public Circle(double radius) {
        this.background = new Background("Black", 3.754f);
        this.radius = radius;
    }

    public double getRadius() {
        return radius;
    }

    public String getColor () {
        return background.color;
    }

    void enlarge (Double scale) {
        radius *= scale;
    }

    public void draw () {
        System.out.println(String.format("Drawing the circle with %f radius in colors: %s", radius, background.color));
    }
}
