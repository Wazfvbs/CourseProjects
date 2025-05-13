package com.demo1;

import java.awt.*;

public class Circle {

    public static final double PI=3.14;
    private double rad;
    private Color color;

    public Circle(){}

    public Circle(double rad){
        this.rad=rad;
    }

    public Circle(double rad, Color color) {
        this.rad = rad;
        this.color = color;
    }

    public void setRad(double rad){
        if(rad<=0) this.rad=10;
        this.rad=rad;
    }
    public double getRad() {
        return rad;
    }

    public Color getColor() {
        return color;
    }

    public void setColor(Color color) {
        this.color = color;
    }

    public double computerArea(){
        return PI*rad*rad;
    }

    public String toString2(){
        return "[rad="+rad+",color="+color+"]";
    }

}
