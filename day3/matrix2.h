#ifndef MATRIX2_H
#define MATRIX2_H

#include "vector2.h"

struct mat2f {
    float m[ 2 ][ 2 ];
};

typedef struct mat2f mat2f;

mat2f* mat2f_alloc();
void   mat2f_init( mat2f* m, float m00, float m01, float m10, float m11 );
mat2f* mat2f_new( float m00, float m01, float m10, float m11 );

void   mat2f_delete( mat2f** m );

void   mat2f_print( const mat2f* m );

void   mat2f_mult_scalar( mat2f* m, float s );
void   mat2f_add_scalar( mat2f* m, float s );

void   mat2f_add( mat2f* dst, const mat2f* a, const mat2f* b );

void   mat2f_transform( vec2f* dst, const mat2f* m, const vec2f* v );

#endif
