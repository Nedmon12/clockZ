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
    int second_angle = second_position(0);
    int iterator = 0;
    int minIterator = 0;

    while (true) {
        cleardevice();
        for (int i = 0; i < 12; i++) {
            double angle = (-1 * (2 * PI * i / 12)) + 45;

            int x = pivotX + (int)(110 * cos(angle));
            int y = pivotY - (int)(110 * sin(angle));

            char numStr[3];
            sprintf(numStr, "%d", i + 1);
            outtextxy(x, y, numStr);
        }
        // the clock

        circle(pivotX, pivotY, 120);
        circle(pivotX, pivotY, 3);

        int secX = pivotX + length * cos(second_angle * M_PI / 180);
        int secY = pivotY + length * sin(second_angle * M_PI / 180);

        int houX = pivotX + sh_length * cos(hour_angle * M_PI / 180);
        int houY = pivotY + sh_length * sin(hour_angle * M_PI / 180);

        int minX = pivotX + 90 * cos(minute_angle * M_PI / 180);
        int minY = pivotY + 90 * sin(minute_angle * M_PI / 180);

        line(pivotX, pivotY, secX, secY);
        line(pivotX, pivotY, houX, houY);
        line(pivotX, pivotY, minX, minY);

        second_angle = second_angle + (360 / 60);
        iterator++;
        if (iterator == 60) {
            minute_angle = minute_angle + (360 / 60);
            minIterator++;
            iterator = 0;
        }
        if (minIterator == 60) {
            hour_angle = hour_angle + (360 / 12);
            minIterator++;
        }

        delay(990);
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
