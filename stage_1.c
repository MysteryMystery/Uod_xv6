#include "types.h"
#include "user.h"

int main(){
    setvideomode(0x13);

    //set some pixels
    setpixel(1, 1, 4);

    // draw some lines
    for (int i = 0; i < 16; i++)
    {
        drawline(0, i * 10, 639, 479 - (i * 10), i);
        drawline(639, i * 10, 0, 479 - (i * 10), i);
    } 

    exit();
}