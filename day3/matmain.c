#include "matrix2.h"

#include <stdio.h>

int main()
{
    mat2f* m = mat2f_new( 0.0f, 0.0f, 0.0f, 0.0f );
    mat2f* a = mat2f_new( 1.0f, 2.0f, 0.0f, 0.0f );
    mat2f* b = mat2f_new( 0.0f, 0.0f, 1.0f, 2.0f );

    mat2f_print( m );

    mat2f_add( m, a, b );
    printf("m:\n");
    mat2f_print( m );

    mat2f_init( m, 1.0f, 0.0f, 0.0f, 1.0f );
    printf("m:\n");
    mat2f_print( m );

    vec2f va, vb;
    vec2f_init( &va, 1.0f, 2.0f );
    mat2f_transform( &vb, m, &va );
    printf("vb:\n");
    vec2f_print( &vb );


    mat2f_delete( &m );
    mat2f_delete( &a );
    mat2f_delete( &b );


}
