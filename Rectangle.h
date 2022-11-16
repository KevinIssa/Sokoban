#ifndef _RECTANGLE_H
#define _RECTANGLE_H

#include <iostream>
#include <FL/Fl.H>
#include <FL/fl_draw.H>
#include <FL/Fl_Double_Window.H>
#include <FL/Fl_Box.H>


typedef struct vector_2D {
    int x, y;
};

class Rectangle{

private:
    vector_2D center;
    int width=10, height=10;

    Fl_Color fillColor, frameColor;
public:
    Rectangle(vector_2D center, int w, int h,
            Fl_Color frameColor,
            Fl_Color fillColor);
    
     ~Rectangle()=default;


    void setFillColor(Fl_Color newFillColor);

    void setFrameColor(Fl_Color newFrameColor);

    Fl_Color getFillColor() {
        return fillColor;
    }
    
    FL_Color getframeColor(){
        return framecolor;
    }

    vector_2D getCenter() {
        return center;
    }

    void setWidth(int new_width);

    void setHeight(int new_height);

    int getWidth() {
        return width;
    }

    int getHeight() {
        return height;
    }

    bool contains(Point dot);

    void draw();

};


#endif