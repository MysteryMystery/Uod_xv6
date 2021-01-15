#include "types.h"
#include "defs.h"
#include "memlayout.h"

int sys_getch(void) {
    return consoleget();
}

// TODO: Implement your system call for switching video modes (and any other video-related syscalls)
// in here.

GraphicsCall graphicsCalls[1024];
int graphicsCallCount = 0;

char isBatching = -1;

int appendGraphicsCall(char fName[], int arguments[], char argumentsLength){
    GraphicsCall graphicsCall;

   strncpy(graphicsCall.callName, fName, 50);
   memmove(graphicsCall.arguments, arguments, 10 * sizeof(int));
   graphicsCall.argumentsLength = argumentsLength;

    graphicsCallCount++;

    if (graphicsCallCount  > 1023)
        return -1;
    
    //memmove(&graphicsCalls[graphicsCallCount - 1], &graphicsCall, sizeof(GraphicsCall));
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
        int args[] = {mode};
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
        int args[] = {x0, y0, x1, y1, colour};
        return appendGraphicsCall("drawline", args, 5);
    } 
    return drawline(x0, y0, x1, y1, colour);
}

int sys_drawcircle(void){
    int cx, cy, r, c;
    argint(0, &cx);
    argint(1, &cy);
    argint(2, &r);
    argint(3, &c);

    if (isBatching == 0)
    {
        int args[] = {cx, cy, r, c};
        return appendGraphicsCall("drawcircle", args, 4);
    }
    return drawcircle(cx, cy, r, c);
}

int sys_fillrectangle(void){
    int x0, y0, x1, y1, colour;
    argint(0, &x0);
    argint(1, &y0);
    argint(2, &x1);
    argint(3, &y1);
    argint(4, &colour);

    if (isBatching == 0)
    {
        int args[] = {x0, y0, x1, y1, colour};
        return appendGraphicsCall("fillrectangle", args, 5);
    } 
    return fillrectangle(x0, y0, x1, y1, colour);
}

// upto 10 points
int sys_fillpolygon(void){
    int pointsLen;
    char *points;
    argint(1, &pointsLen);
    argptr(0, &points, (pointsLen + 1) * sizeof(int));

    if (isBatching == 0)
        return appendGraphicsCall("fillpolygon", (int *) points, pointsLen);

    int colour = points[pointsLen - 1];
    return fillpolygon((int *) points, pointsLen - 1, colour);
}

int sys_begingraphics(){
    isBatching = 0;
    return 0;
}

int sys_endgraphics(){
    isBatching = -1;
    int status = executeGraphicsBatch(graphicsCalls, graphicsCallCount);
    graphicsCallCount = 0;
    return status;
}
