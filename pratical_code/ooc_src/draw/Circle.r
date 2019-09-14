
#include "Point.r"


// Information hiding demands that we should 
// never reach into the base structure directly; 
// therefore, we use `_`
// declare it to be const to ward off careless assignments.
//
// This is all there is to simple inheritance

struct Circle { 
    const struct Point _; 
    int rad; 
};

