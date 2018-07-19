//
// Created by king on 7/17/18.
//
#include <stdio.h>

/*static unsigned short stopwatch[] = {
        0x07C6,
        0x1FF7,
        0x383B,
        0x600C,
        0x600C,
        0xC006,
        0xC006,
        0xDF06,
        0xC106,
        0xC106,
        0x610C,
        0x610C,
        0x3838,
        0x1FF0,
        0x07C0,
        0x0000
};*/

#define X )*2+1
#define _ )*2
#define s ((((((((((((((((0 /* For building glyphs 16 bits wide */

static unsigned short stopwatch[] = {
        s _ _ _ _ _ X X X X X _ _ _ X X _,
        s _ _ _ X X X X X X X X X _ X X X,
        s _ _ X X X _ _ _ _ _ X X X _ X X,
        s _ X X _ _ _ _ _ _ _ _ _ X X _ _,
        s _ X X _ _ _ _ _ _ _ _ _ X X _ _,
        s X X _ _ _ _ _ _ _ _ _ _ _ X X _,
        s X X _ _ _ _ _ _ _ _ _ _ _ X X _,
        s X X _ X X X X X _ _ _ _ _ X X _,
        s X X _ _ _ _ _ X _ _ _ _ _ X X _,
        s X X _ _ _ _ _ X _ _ _ _ _ X X _,
        s _ X X _ _ _ _ X _ _ _ _ X X _ _,
        s _ X X _ _ _ _ X _ _ _ _ X X _ _,
        s _ _ X X X _ _ _ _ _ X X X _ _ _,
        s _ _ _ X X X X X X X X X _ _ _ _,
        s _ _ _ _ _ X X X X X _ _ _ _ _ _,
        s _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
};


int main()
{
}

