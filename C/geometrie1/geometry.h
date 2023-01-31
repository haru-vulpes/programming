#pragma once

struct point {
        int x;
        int y;
};

struct line {
    float a;
    float b;
};

struct cercle {
        int r;
        struct point p;
};

struct point add_point(struct point a, struct point b);

struct line make_line(struct point p1, struct point p2);

bool is_on_line(struct line l1, struct point p);

bool is_parallel(struct line l1, struct line l2);

bool is_in_circle(struct cercle C1, struct point p1);

void print_point(struct point c);

void print_line(struct line line);
