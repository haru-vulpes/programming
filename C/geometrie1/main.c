#include <stdio.h>
#include <stdbool.h>

#include "geometry.h"

int main (void){

        struct cercle c1 = {.r = 5, .p = {.x = 200, .y = 40}};
        struct line l1 = {.a = 1, .b = 0};
        struct line l2 = {.a = 2, .b = 4};

        struct point test1 = {.x = 1, .y = 1};
        struct point test2 = {.x = 10, .y = 10};
        struct point test3 = {.x = 3, .y = 3};

        // struct point test4 = {.x = 5, .y = 5};

        printf("fonction add_point: ");
        print_point(add_point(test1, test2));    

        printf("fonction make_line: ");
        print_line(make_line(test1, test2));

        if (is_on_line(make_line(test1, test2), test3))
                printf("Le point est sur la ligne.\n");
        else 
                printf("Le point n'est pas sur la ligne.\n");

        if (is_parallel(l1, l2))
                printf("Les droites sont paralleles\n");
        else
                printf("Les droites ne sont pas paralleles\n");
        
        if (is_in_circle(c1, test1))
                printf("It's in circle.\n");
        else
                printf("It's not in circle.\n");

        return 0;
}
