#include "matrix2.h"

#include <stdio.h>
#include <stdlib.h>

mat2f* mat2f_alloc()
{
    mat2f* ret;
    ret = ( mat2f* ) malloc( sizeof( mat2f ) );
    if( !ret )
        printf("error allocating mat2f!\n");
    return ret;
}

void mat2f_init( mat2f* m, float m00, float m01, float m10, float m11 )
{
    m->m[ 0 ][ 0 ] = m00;
    m->m[ 0 ][ 1 ] = m01;
    m->m[ 1 ][ 0 ] = m10;
    m->m[ 1 ][ 1 ] = m11;
}

mat2f* mat2f_new( float m00, float m01, float m10, float m11 )
{
    mat2f* ret = mat2f_alloc();
    mat2f_init( ret, m00, m01, m10, m11 );
    return ret;
}

void mat2f_delete( mat2f** m )
{
    free( *m );
    *m = NULL;
}

void mat2f_print( const mat2f* m )
{
    printf("| %g %g |\n| %g %g |\n", m->m[ 0 ][ 0 ], m->m[ 0 ][ 1 ], m->m[ 1 ][ 0 ], m->m[ 1 ][ 1 ] );
}

void mat2f_mult_scalar( mat2f* m, float s )
{
    m->m[ 0 ][ 0 ] *= s;
    m->m[ 0 ][ 1 ] *= s;
    m->m[ 1 ][ 0 ] *= s;
    m->m[ 1 ][ 1 ] *= s;
}

void mat2f_add_scalar( mat2f* m, float s )
{
    m->m[ 0 ][ 0 ] += s;
    m->m[ 0 ][ 1 ] += s;
    m->m[ 1 ][ 0 ] += s;
    m->m[ 1 ][ 1 ] += s;
}

void mat2f_add( mat2f* dst, const mat2f* a, const mat2f* b )
{
    dst->m[ 0 ][ 0 ] = a->m[ 0 ][ 0 ] + b->m[ 0 ][ 0 ];
    dst->m[ 0 ][ 1 ] = a->m[ 0 ][ 1 ] + b->m[ 0 ][ 1 ];
    dst->m[ 1 ][ 0 ] = a->m[ 1 ][ 0 ] + b->m[ 1 ][ 0 ];
    dst->m[ 1 ][ 1 ] = a->m[ 1 ][ 1 ] + b->m[ 1 ][ 1 ];
}


void mat2f_transform( vec2f* dst, const mat2f* m, const vec2f* v )
{
    dst->x = m->m[ 0 ][ 0 ]* v->x + m->m[ 0 ][ 1 ] * v->y;
    dst->y = m->m[ 1 ][ 0 ]* v->x + m->m[ 1 ][ 1 ] * v->y;
}
