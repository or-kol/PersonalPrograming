package com.app.painter;

import com.app.shapes.Circle;
import com.app.shapes.ShapesEnlarger;

public class Main {

    public static void main(String[] args) {
        Circle c1 = new Circle(4.5);
        c1.draw();
        ShapesEnlarger.enlargeCircle(c1);
        c1.draw();
    }
}
