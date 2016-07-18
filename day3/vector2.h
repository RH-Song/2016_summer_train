#ifndef VECTOR2_H
#define VECTOR2_H

struct vec2f {
    float x;
    float y;
};

typedef struct vec2f vec2f;

vec2f* vec2f_alloc();
void   vec2f_init( vec2f* v, float x, float y );
vec2f* vec2f_new( float x, float y );
void   vec2f_delete( vec2f** v );
void   vec2f_print( const vec2f* v );

void   vec2f_mult_scalar( vec2f* v, float s );
void   vec2f_add_scalar( vec2f* v, float s );

void   vec2f_add( vec2f* dst, const vec2f* a, const vec2f* b );

#endif
