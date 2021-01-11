#include "types.h"
#include "user.h"

int main(){
    printf(1, "This some text mode text\n");
    printf(1, "We would like to restore this line and the line above.\n");

    begingraphics();

    setvideomode(0x12);

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