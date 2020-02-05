#include "fangkuai.h"

void Piece::set_shape(int &cshape, int shape[][4], int &size_w, int &size_h)
{    /*初始化4*4方块的数组*/
    int i,j;
    for (i=0;i<4;i++)
        for (j=0;j<4;j++)
            shape[i][j]=0;


    switch(cshape)
    {
    case 0:
        size_h = 1;
        size_w = 4;
        shape[0][0] = 1;
        shape[0][1] = 1;
        shape[0][2] = 1;
        shape[0][3] = 1;
        break;
    case 1:
        size_h = 2;
        size_w = 3;
        shape[0][0] = 1;
        shape[1][0] = 1;
        shape[1][1] = 1;
        shape[1][2] = 1;
        break;
    case 2:
        size_h = 2;
        size_w = 3;
        shape[0][2] = 1;
        shape[1][0] = 1;
        shape[1][1] = 1;
        shape[1][2] = 1;
        break;
    case 3:
        size_h = 2;
        size_w = 3;
        shape[0][1] = 1;
        shape[0][2] = 1;
        shape[1][0] = 1;
        shape[1][1] = 1;
        break;
    case 4:
        size_h = 2;
        size_w = 3;
        shape[0][0] = 1;
        shape[0][1] = 1;
        shape[1][1] = 1;
        shape[1][2] = 1;
        break;
    case 5:
        size_h = 2;
        size_w = 2;
        shape[0][0] = 1;
        shape[0][1] = 1;
        shape[1][0] = 1;
        shape[1][1] = 1;
        break;
    case 6:
        size_h = 2;
        size_w = 3;
        shape[0][1] = 1;
        shape[1][0] = 1;
        shape[1][1] = 1;
        shape[1][2] = 1;
        break;
    }

//设置方块的起始位置
head_x = game_win_width/2;
head_y = 1;

if(isaggin()）
        game_over=true;

}

void Piece::rotate()
{
    int temp[4][4]={0};
    int temp_piece[4][4] = {0};
    int i,j,tmp_size_h,tmp_size_w;

    tmp_size_w = size_w;
    tmp_size_h = size_h;

    for(int i=0;i<4;i++)
        for(int j=0;j<4;j++)
            temp_piece[i][j] = box_shape[i][j];//备份当前的方块，准备移动

    for(i=0;i<4;i++)
        for(j=0;j<4;j++)
            temp[j][i] = box_shape[i][j];

    i = size_h;
    size_h = size_w;
    size_w = i;
    for(i = 0;i<size_h;i++)
        for(j = 0;j<size_w;j++)
            box_shape[i][size_w-1-j]=temp[i][j];

    if(isaggin()){
        for(int i=0;i<4;i++)
            for(int j=0;j<4;j++)
                box_shape[i][j] = temp_piece[i][j];//重合后，返回备份的数组形状
        size_w = tmp_size_w;
        size_h = tmp_size_h;
    }

    else{
        for(int i=0;i<4;i++)
            for (int j=0;j<4;j++){
                if (temp_piece[i][j]==1){
                    mvwaddch(game_win,head_y+i,head_x+j,' ');
                    wrefresh(game_win);
                }
            }
        for(int i=0;i<size_h;i++)
            for(int j=0;j<size_w;j++){
                if(this->box_shape[i][j]==1){
                    mvwaddch(game_win,head_y+i,head_x+j,'#');
                    wrefresh(game_win);
                }
            }
    }
}

