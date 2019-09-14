
#include <stdio.h>
#include <stdarg.h>
#include <stddef.h>
#include "new.r"


struct Point {
    const void * class;
    int x, y; /* coordinates */
};

// All these methods are static because 
// they should only be called through new(), delete(), or the selectors.

static void * Point_ctor (void * _self, va_list * app) { 
    struct Point * self = _self;
    self -> x = va_arg(* app, int); 
    self -> y = va_arg(* app, int); 
    return self;
}

/*
 * example dtor for String

static void * String_dtor (void * _self) { 
    struct String * self = _self;
    free(self -> text), self -> text = 0; 
    return self;
}
*/

static void Point_draw (const void * _self) { 
    const struct Point * self = _self;
    printf("\".\" at %d,%d\n", self -> x, self -> y);
}

void move (void * _self, int dx, int dy) { 
    struct Point * self = _self;
    self -> x += dx, self -> y += dy;
}

static const struct Class _Point = {
    sizeof(struct Point), 
    Point_ctor, 
    0, 
    Point_draw
};
const void * Point = & _Point;

