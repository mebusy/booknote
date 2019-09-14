
#include <stdio.h>
#include <stdarg.h>
#include <stddef.h>

struct Point {
    const void * class;
    int x, y; /* coordinates */
};

static void * Point_ctor (void * _self, va_list * app) { 
    struct Point * self = _self;
    self -> x = va_arg(* app, int); 
    self -> y = va_arg(* app, int); 
    return self;
}

static void Point_draw (const void * _self) { 
    const struct Point * self = _self;
    printf("\".\" at %d,%d\n", self -> x, self -> y);
}


