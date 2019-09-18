
#include "Object.h"

static int Any_differ (const void * _self, const void * b) {
    return 0; /* Any equals anything... */
}

int main () { 
    void * o = new(Object);
    const void * Any =
        new(Class, "Any", Object, sizeOf(o),
                differ, Any_differ,
                0);
    void * a = new(Any);

    puto(Any, stdout); 
    puto(o, stdout); 
    puto(a, stdout);

    if (differ(o, o) == differ(a, a)) 
        puts("ok");
    if (differ(o, a) != differ(a, o)) 
        puts("not commutative");
    delete(o), delete(a);
    // Clearly, we should not be able to delete a class description.
    // This error is already detected during compilation, because 
    // delete() does not accept a pointer to an area protected with const.
    delete(Any);
    return 0;
}

