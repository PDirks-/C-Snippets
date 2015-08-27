/***************************
 C brush-up
 brush_util.c
***************************/
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "brush_util.h"

/**********************************************************
 point_init() : create point
**********************************************************/
point * point_init ( 
    int x, 
    int y 
){
    point * p;
	p = malloc( sizeof(point) );
	assert( p != NULL );
	
    p->x = x;
    p->y = y;
	
	return p;
}// end point_init

/**********************************************************
 node_init() : create node
**********************************************************/
node * node_init (
    point * point
){
	node * n;
    n = malloc( sizeof(node) );
    assert( n != NULL && point != NULL );
	
	n->point_data = point;

	return n;
}// end node_init

/**********************************************************
 add_node() : add node to tree
**********************************************************/
void add_node(
	node * home,
	node * new
){
	assert( home != NULL && new != NULL );
	
	if( home->point_data->x > new->point_data->x ){
		if( home->left == NULL ){
			home->left = new;
		}
		else{
			add_node( home->left, new );
		}
	}
	else if( home->point_data->x < new->point_data->x ){
		if( home->right == NULL ){
			home->right = new;
		}
		else{
			add_node( home->right, new );
		}
	}
	return;
}// end add_node

/**********************************************************
 print_p() : print x and y values of point
**********************************************************/
void print_p (
    point * p
){
    printf("x: %d y: %d\n", p->x, p->y);
	return;
}// end print_p

/**********************************************************
 chain_print() : prints x & y values of point in node, 
 	traversing down tree until at a dead-end node
**********************************************************/
void chain_print( 
	node * home
){
	print_p( home->point_data );
	
	if( home->right != NULL ){
		chain_print( home->right );
	}
	else if( home->left != NULL ){
		chain_print( home->left );
	}
	
	return;
}// end chain_print

/**********************************************************
 clean functions : deallocate respective structs...
**********************************************************/
void clean_n (
	node * n
){
	assert( n != NULL && n->point_data != NULL );
	clean_p( n->point_data );
	return;
}

void clean_p (
	point * p
){
	assert( p != NULL );
	free( p );
	return;
}

void chain_clean (
	node * n
){
	if( n->right != NULL ){
		chain_clean( n->right );
	}
	else if( n->left != NULL ){
		chain_clean( n->left );
	}
	return;
}

/**********************************************************
**********************************************************/