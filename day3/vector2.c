#include "vector2.h" //or <vector2.h if the file is in the header lookup path

#include <stdio.h>
#include <stdlib.h>

vec2f* vec2f_alloc()
{
    vec2f* ret;
    ret = ( vec2f* ) malloc( sizeof( vec2f ) );
    if( !ret )
        printf( "error allocation failed!\n" );
    return ret;
}

void vec2f_init( vec2f* v, float x, float y )
{
    v->x = x;
    v->y = y;
}

vec2f* vec2f_new( float x, float y )
{
    vec2f* ret = vec2f_alloc();
    vec2f_init( ret, x, y );
    return ret;
}

void vec2f_delete( vec2f** v )
{
    free( *v );
    *v = NULL;
}

void vec2f_mult_scalar( vec2f* v, float s )
{
    v->x *= s;
    v->y *= s;
}

void vec2f_add_scalar( vec2f* v, float s )
{
    v->x += s;
    v->y += s;
}

void vec2f_add( vec2f* dst, const vec2f* a, const vec2f* b )
{
    dst->x = a->x + b->x;
    dst->y = a->y + b->y;
}

void vec2f_print( const vec2f* v )
{
    printf( "[ %g %g ]\n", v->x, v->y );
}


