/***************************
 C brush-up
 brush_util.h
***************************/

/************
 DATA TYPES
************/
typedef struct point {
    int x;
    int y;
} point;

typedef struct node {
    struct point * point_data;
    struct node * left;
    struct node * right;
} node;

/************
 HEADERS
************/

point * point_init ( 
    int x, 
    int y 
);

node * node_init (
    point * point
);

void add_node(
	node * home,
	node * new
);

void print_p (
    point * p
);

void chain_print ( 
	node * home
);

void clean_n (
	node * n
);

void chain_clean (
	node * n
);

void clean_p (
	point * p
);