#include <stdio.h>
#include <stdbool.h>

#include "geometry.h"

struct point add_point(struct point a, struct point b){

    struct point c;
    
    c.x = a.x + b.x;
    c.y = a.y + b.y;

    return c;
}

void print_point(struct point c){

    printf("(%d, %d)\n", c.x, c.y);

}

void print_line(struct line line){
    
    printf("y = %fx + %f\n", line.a, line.b);

}

struct line make_line(struct point p1, struct point p2){

    struct line line;

    line.a = (p2.y - p1.y) / (p2.x - p1.x);
    line.b = p1.y - (line.a * p1.x); 

    return line;
}

bool is_on_line(struct line l1, struct point p){
    
    return p.y == (l1.a * p.x) + l1.b;
}

bool is_parallel(struct line l1, struct line l2){

   return l1.a == l2.a; 

}

bool is_in_circle(struct cercle c1, struct point p1){

        return ((p1.x - c1.p.x)*(p1.x - c1.p.x))-((p1.y - c1.p.y)*(p1.y - c1.p.y)) <= c1.r*c1.r;

}
