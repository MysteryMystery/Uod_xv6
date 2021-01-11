#include "types.h"
#include "user.h"

int main(){
    printf(1, "This some text mode text\n");
    printf(1, "We would like to restore this line and the line above.\n");

    setvideomode(0x13);
    //set some pixels
   // setpixel(1, 1, 4);
    // draw some lines
   // drawline(3, 3, 6, 6, 5);

    printf(1, "This is some text in video memory.\n");
    printf(1, "This is another pieceof etxt that should be saved to the buffer.\n");

    setvideomode(0x03);

    exit();
}