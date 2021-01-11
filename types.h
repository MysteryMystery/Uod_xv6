typedef unsigned int   uint;
typedef unsigned short ushort;
typedef unsigned char  uchar;
typedef unsigned char bool;
typedef uint pde_t;

enum {
	false,
	true,
};

typedef struct GraphicsCall {
    char *callName; // The function name e.g setpixel, setvideomode, drawline 
    int *arguments;  // Hold the arguments
    char argumentsLength;

    struct GraphicsCall *nextCall;
    char terminal; // for some reason, checking null for *nextCall didnt work, so extra flag it is for the time being
} GraphicsCall;