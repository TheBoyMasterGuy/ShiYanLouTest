#include <iostream>
#include <sys/time.h>
#include <sys/types.h>
#include <stdlib.h>
#include <ncurses.h>
#include <unistd.h>

/* swap function, swap a and b */
void swap(int &a, int &b){
    int t = a;
    a = b;
    b = t;
}

int getrand(int min, int max)
{
    return (min+rand()%(max-min+1));
}

class Piece
{
    public:
        int score;
        int shape;
        int next_shape;

        int head_x;
        int head_y;

        int size_h;
        int size_w;

        int next_size_h;
        int next_size_w;

        int box_shape[4][4];
        int next_box_shape[4][4];

        int box_map[30][45];

        bool game_over;

    public:
        void initial();
        void set_shape(int &cshape, int box_shape[][4], int &size_w, int &size_h);

        void score_next();
        void judge();
        void move();
        void rotate();
        bool isaggin();
        bool exsqr(int row);

};
