#include <stdio.h>
#include <math.h>

#define XMAX 320
#define YMAX 460

struct point {
    int x;
    int y;
};

struct rect {
    struct point pt1;
    struct point pt2;
};

double distance_to_zero(struct point);
struct point makepoint(int, int);
int ptinrect(struct point, struct rect);

int main(void)
{
    struct point pt1, middle, *pp;
    pt1 = makepoint(4, 4);
    pp = &pt1;

    printf("(*pp).x=%d, (*pp).y=%d\n", (*pp).x, (*pp).y);
    printf("pp->x=%d, p->y=%d\n", pp->x, pp->y);

    struct rect screen, *rp;
    screen.pt1 = makepoint(6, 6);
    screen.pt2 = makepoint(XMAX, YMAX);
    rp = &screen;

    printf("screen.pt1.x=%d,screen.pt1.y=%d,rp->pt1.x=%d,rp->pt1.y=%d\n", screen.pt1.x, screen.pt1.y, rp->pt1.x, (rp->pt1).y);

    printf("pt1 %s screen\n", ptinrect(pt1, screen) ? "in" : "not in");

    middle = makepoint(
            (screen.pt1.x + screen.pt2.x) / 2,
            (screen.pt1.y + screen.pt2.y) /2
            );
    printf("middle point:x=%d,y=%d\n", middle.x, middle.y);
    printf("x=%d, y=%d\n", pt1.x, pt1.y);
    printf("pt1 to zero's distance is %g\n", distance_to_zero(pt1));
    return 0;
}

double distance_to_zero(struct point pt)
{
    double distance;
    distance = sqrt(1.0 * (pt.x * pt.x + pt.y * pt.y));
    return distance;
}

struct point makepoint(int x, int y)
{
    struct point temp;
    temp.x = x;
    temp.y = y;
    return temp;
}

int ptinrect(struct point p, struct rect r)
{
    return p.x >= r.pt1.x && p.x <= r.pt2.x
        && p.y >= r.pt1.y && p.y <= r.pt2.y;
}
