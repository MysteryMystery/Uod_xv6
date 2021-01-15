#include "types.h"
#include "user.h"

int main(){
    printf(1, "This some text mode text\n");
    printf(1, "We would like to restore this line and the line above.\n");

    begingraphics();
    
    setvideomode(0x12);

    //drawline(40, 40, 20, 20, 0xd);

    //drawcircle(80, 80, 10, 0xe);
    
    //fillrectangle(2, 2, 50, 50, 0xd);

    //fillrectangle(2, 52, 70, 70, 0xe);

    int points[] = {30, 30, 50, 10, 70, 30, 50, 100, 0xd};
    fillpolygon(points, 9);

    endgraphics();    

    exit();
}