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

int hour_position(int hour) {
    int hour_head = ((hour % 12) * 30) - 90;
    return hour_head;
}

int minute_postion(int minute) {
    int minute_head = (minute * 6) - 90;
    return minute_head;
}

int second_position(int second) {
    int second_head = (second * 6) - 90;

    return second_head;
}
int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");
    int counter = 0;

    int pivotX = 200;
    int pivotY = 200;
    int length = 100;
    int sh_length = 80;
    int minute_angle = minute_postion(10);
    int hour_angle = hour_position(6);
    int second_angle = second_position(40);
    while (true) {
        cleardevice();
        // the clock
        circle(pivotX, pivotY, 120);
        circle(pivotX, pivotY, 3);

        int secX = pivotX + length * cos(second_angle * PI / 180);
        int secY = pivotY + length * sin(second_angle * PI / 180);

        int houX = pivotX + sh_length * cos(hour_angle * PI / 180);
        int houY = pivotY + sh_length * sin(hour_angle * PI / 180);

        int minX = pivotX + 90 * cos(minute_angle * PI / 180);
        int minY = pivotY + 90 * sin(minute_angle * PI / 180);

        line(pivotX, pivotY, secX, secY);
        line(pivotX, pivotY, houX, houY);
        line(pivotX, pivotY, minX, minY);

        second_angle++;
        minute_angle +=
            static_cast<int>(sqrt(second_angle * second_angle)) % 60;
        hour_angle += static_cast<int>(sqrt(minute_angle * minute_angle)) % 60;

        delay(100);
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
