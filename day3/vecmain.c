#include "vector2.h"

int main()
{
    vec2f* v = vec2f_new( 0.0f, 0.0f );
    vec2f* a = vec2f_new( 1.0f, 2.0f );
    vec2f* b = vec2f_new( 3.0f, 4.0f );

    vec2f_print( v );

    vec2f_add( v, a, b );
    vec2f_print( v );

    vec2f_delete( &a );
    vec2f_delete( &b );
    vec2f_delete( &v );
}
