#include "types.h"
#include "user.h"

int main(){
    setvideomode(0x13);

    drawline(5, 5, 20, 20, 0xd);
    drawline(22, 20, 25, 5, 0x4);
    drawline(27, 5, 40, 2, 0x3);
    drawline(42, 2, 42, 12, 0x2);

    drawline(100, 200, 100, 300, 0xd);

    drawcircle(150, 80, 10, 0xe);
    drawcircle(150, 80, 50, 0x1);
    
    fillrectangle(1, 100, 50, 158, 0xd);
    fillrectangle(1, 200, 70, 160, 0xe);

    exit();
}