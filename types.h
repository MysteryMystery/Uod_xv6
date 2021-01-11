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
    char callName[50]; // The function name e.g setpixel, setvideomode, drawline 
    int arguments[10];  // Hold the arguments
    char argumentsLength;
} GraphicsCall;