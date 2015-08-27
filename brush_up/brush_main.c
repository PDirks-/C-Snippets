/***************************
 C brush-up
***************************/
#include "brush_main.h"
#include "brush_util.h"
#include <stdio.h>

int main(void){

    point * p;
    node * n;
    node * n2;
	
    p = NULL;
    n = NULL;
    
    p = point_init( 1, 2 );
    n = node_init( p );
    
	n2 = node_init( point_init( 4, 5 ) );
	
	
	printf("a point...");
	printf("~~%d\n", p->x );
	
    printf("point...\n");
    print_p( n->point_data );
	print_p( n2->point_data );
	
	add_node( n, n2 );
	
	chain_clean( n );
	
    return 0;
}// end main