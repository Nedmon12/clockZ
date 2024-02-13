#include <graphics.h>
#include <math.h>
#define PI 3.14159265

void rotatePoint(int &x, int &y, float angle) {
    float radians = angle * M_PI / 180.0;

    int new_x = x * cos(radians) - y * sin(radians);
    int new_y = x * sin(radians) + y * cos(radians);

    x = new_x;
    y = new_y;
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");
    int counter = 0;

    int pivotX = 200;
    int pivotY = 200;
    int length = 100;
    int angle = 0;

    while (true) {
        cleardevice();
        circle(pivotX, pivotY, 120);
        circle(pivotX, pivotY, 3);

        int endX = pivotX + length * cos(angle * PI / 180);
        int endY = pivotY + length * sin(angle * PI / 180);

        line(pivotX, pivotY, endX, endY);

        angle++;

        delay(50);
    }
    closegraph();
    return 0;
}
//
//
//
//
//
//
//
//
//
//
//
