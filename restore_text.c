#include "types.h"
#include "user.h"

int main(){
    printf(1, "This some text mode text\n");
    printf(1, "We would like to restore this line and the line above.\n");

    setvideomode(0x13);

    setvideomode(0x3);
    exit();
}