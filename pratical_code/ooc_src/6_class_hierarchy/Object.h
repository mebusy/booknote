#ifndef OBJECT_H
#define OBJECT_H

// define a class Object with the ability to 
// create, destroy, compare, and display objects.

extern const void * Object; /* new(Object); */
void * new (const void * class, ...); 
void delete (void * self);
int differ (const void * self, const void * b); 
int puto (const void * self, FILE * fp);

extern const void * Class; /* new(Class, "name", super, size sel, meth, ... 0); */

#endif
