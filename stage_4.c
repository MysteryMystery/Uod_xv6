#include "types.h"
#include "user.h"

int main(){
    printf(1, "This some text mode text\n");
    printf(1, "We would like to restore this line and the line above.\n");

    begingraphics();
    
    setvideomode(0x12);
    /*
    for (int i = 0; i < 16; i++)
    {
        drawline(0, i * 10, 639, 479 - (i * 10), i);
        drawline(639, i * 10, 0, 479 - (i * 10), i);
    }
    */
    
    /*
    setpixel(1, 1, 0xd);
    setpixel(2, 2, 0xf);
    setpixel(1, 2, 0xe);
    */

    drawline(1, 1, 10, 1, 0xe);
    drawline(1, 3, 10, 3, 0xc);
    endgraphics(); 

    /*
    int status = endgraphics();
    if (status == -1)
        printf(1, "Empty first call\n");
    else 
        printf(1, "First call exists\n");
        */
    

    exit();
}