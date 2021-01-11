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

GraphicsCall graphicsCalls[1024];
int graphicsCallCount = 0;

char isBatching = -1;

int appendGraphicsCall(char fName[], char arguments[], char argumentsLength){
    GraphicsCall graphicsCall;/*
    {
        .callName = fName, 
        args, 
        argumentsLength
    };
    */

   strncpy(graphicsCall.callName, fName, 50);
   strncpy(graphicsCall.arguments, arguments, 10);
   graphicsCall.argumentsLength = argumentsLength;

    graphicsCallCount++;

    if (graphicsCallCount  > 1023)
        return -1;
    
    graphicsCalls[graphicsCallCount - 1] = graphicsCall;

    return 0;
}

int sys_setpixel(void){
    int x, y, colour;
    argint(0, &x);
    argint(1, &y);
    argint(2, &colour);
    
    if (isBatching == 0)
    {
        char args[] = {x, y, colour};
        return appendGraphicsCall("setpixel", args, 3);
    }
    return setpixel(x, y, colour);
}

int sys_setvideomode(void){
    int mode;
    argint(0, &mode); //seems to always return 0 - status code i'm assuming?
    if (isBatching == 0)
    {
        char args[] = {mode};
        return appendGraphicsCall("setvideomode", args, 1);
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
        char args[] = {x0, y0, x1, y1, colour};
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
    int status = executeGraphicsBatch(firstGraphicsCall, graphicsCallCount);
    graphicsCallCount = 0;
    return status;
}
