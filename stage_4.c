#include "types.h"
#include "user.h"

int main(){
    printf(1, "This some text mode text\n");
    printf(1, "We would like to restore this line and the line above.\n");

    begingraphics();
    setvideomode(0x13);
    for (int i = 0; i < 16; i++)
    {
        drawline(0, i * 10, 639, 479 - (i * 10), i);
        drawline(639, i * 10, 0, 479 - (i * 10), i);
    }
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