#include <graphics.h>
#include <math.h>

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
    int x1, y1 = 50;
    int x2, y2 = 100;
    while (counter < 3) {
        int mid_x = (x1 + x2) / 2;
        int mid_y = (y1 + y2) / 2;

        x1 -= mid_x;
        y1 -= mid_y;
        x2 -= mid_x;
        y2 -= mid_y;

        // rotatePoint(x1, y1, 45);
        rotatePoint(x2, y2, 45);

        x1 += mid_x;
        y1 += mid_y;
        x2 += mid_x;
        y2 += mid_y;

        line(x1, y1, x2, y2);
        delay(5000);
        counter += 1;
        // line(x1, y1, x2, y2);
        // x = ()
    }
    getch();
    closegraph();
    return 0;
}
