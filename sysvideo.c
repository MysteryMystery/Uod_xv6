#include "types.h"
#include "defs.h"
#include "memlayout.h"

int sys_getch(void) {
    return consoleget();
}

// TODO: Implement your system call for switching video modes (and any other video-related syscalls)
// in here.

GraphicsCall *firstGraphicsCall;
GraphicsCall *lastGraphicsCall;

char isBatching = -1;

int appendGraphicsCall(char *fName, int arguments[], char argumentsLength){
    int *args;
    args = arguments;
    GraphicsCall graphicsCall = {
        fName, 
        args, 
        argumentsLength,
        0, // next ptr
        0 // terminal
    };

    if (!firstGraphicsCall){
        firstGraphicsCall = &graphicsCall;
        lastGraphicsCall = firstGraphicsCall;
    }

    if (lastGraphicsCall)
    {
        GraphicsCall *p;
        p = &graphicsCall;

        lastGraphicsCall->nextCall = p;
        lastGraphicsCall->terminal = -1;
        lastGraphicsCall = &graphicsCall;
        return 0;
    }
    return -1;
}

int sys_setpixel(void){
    int x, y, colour;
    argint(0, &x);
    argint(1, &y);
    argint(2, &colour);
    
    if (isBatching == 0)
    {
        int args[] = {x, y, colour};
        return appendGraphicsCall("setpixel", args, 3);
    }
    return setpixel(x, y, colour);
}

int sys_setvideomode(void){
    int mode;
    argint(0, &mode); //seems to always return 0 - status code i'm assuming?
    if (isBatching == 0)
    {
        char func[] = "setvideomode";
        int args[] = {mode};
        return appendGraphicsCall(&func[0], args, 1);
    }
    return setvideomode(mode);
}

int sys_drawline(void){
    int x0, y0, x1, y1, colour;
    argint(0, &x0);
    argint(1, &y0);
    argint(2, &x1);
    argint(3, &y1);
    argint(4, &colour);

    if (isBatching == 0)
    {
        int args[] = {x0, y0, x1, y1, colour};
        return appendGraphicsCall("drawline", args, 5);
    } 
    return drawline(x0, y0, x1, y1, colour);
}

int sys_begingraphics(){
    isBatching = 0;
    return 0;
}

int sys_endgraphics(){
    isBatching = -1;
    return executeGraphicsBatch(firstGraphicsCall);
}
