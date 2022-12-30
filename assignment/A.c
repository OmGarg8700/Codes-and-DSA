#include<stdio.h>

int visit_bishop = 1;
int visit_knight = 1;
int visit_rook = 1;

int is_safe(char arr[8][8], int x, int y){
    if((arr[x][y] == '.')&& (x>=0 && x<8)&&(y>=0 && y<8)){
        return 1;
    }
    return 0;
};

void bishop(char arr[8][8],int visited[8][8], int bx, int by, int moves){
    // base case
    if(moves==0){
        return;
    }
    int x,y;

    // for right down diagonal
    x = bx+1;
    y = by+1;
    while(is_safe(arr, x, y) == 1){
        // printf("right down diagonal \n");
        // *totalmoves += 1;
        if(visited[x][y] == 0){
            visited[x][y] = 1;
            visit_bishop++;
        }
        bishop(arr,visited, x, y, moves-1);
        x++;
        y++;
    }

    // for left up diagonal
    x = bx-1;
    y = by-1;
    while(is_safe(arr, x, y) == 1){
        // printf("left up diagonal \n");
        // *totalmoves += 1;
        if(visited[x][y] == 0){
            visited[x][y] = 1;
            visit_bishop++;
        }
        bishop(arr,visited, x, y, moves-1);
        x--;
        y--;
    }

    // for right up diagonal
    x = bx-1;
    y = by+1;
    while(is_safe(arr, x, y) == 1){
        // printf("right up diagonal \n");
        // *totalmoves += 1;
        if(visited[x][y] == 0){
            visited[x][y] = 1;
            visit_bishop++;
        }
        bishop(arr,visited, x, y, moves-1);
        x--;
        y++;
    }

    // for left down diagonal
    x = bx+1;
    y = by-1;
    while(is_safe(arr, x, y) == 1){
        // printf("left down diagonal \n");
        // *totalmoves += 1;
        if(visited[x][y] == 0){
            visited[x][y] = 1;
            visit_bishop++;
        }
        bishop(arr,visited, x, y, moves-1);
        x++;
        y--;
    }
    // return 0;
}

void knight(char arr[8][8], int visited[8][8], int kx, int ky, int moves){
    // base case
    if(moves==0){
        return;
    }
    int x,y;

    // for right up side
    x = kx-1;
    y = ky+2;
    if(is_safe(arr, x, y) == 1){
        // printf("right up side \n");
        // *totalmoves += 1;
        if(visited[x][y] == 0){
            visited[x][y] = 1;
            visit_knight++;
        }
        knight(arr,visited, x, y, moves-1);
        // x--;
        // y+=2;
    }

    // for right down side
    x = kx+1;
    y = ky+2;
    if(is_safe(arr, x, y) == 1){
        // printf("right down \n");
        // *totalmoves += 1;
        if(visited[x][y] == 0){
            visited[x][y] = 1;
            visit_knight++;
        }
        knight(arr,visited, x, y, moves-1);
        // x++;
        // y+=2;
    }

    // for down right side
    x = kx+2;
    y = ky+1;
    if(is_safe(arr, x, y) == 1){
        // printf("down right \n");
        // *totalmoves += 1;
        if(visited[x][y] == 0){
            visited[x][y] = 1;
            visit_knight++;
        }
        knight(arr,visited, x, y, moves-1);
        // x+=2;
        // y++;
    }

    // for down left side
    x = kx+2;
    y = ky-1;
    if(is_safe(arr, x, y) == 1){
        // printf("for down left \n");
        // *totalmoves += 1;
        if(visited[x][y] == 0){
            visited[x][y] = 1;
            visit_knight++;
        }
        knight(arr,visited, x, y, moves-1);
        // x+=2;
        // y--;
    }

    // for left up side
    x = kx-1;
    y = ky-2;
    if(is_safe(arr, x, y) == 1){
        // printf("left up side \n");
        // *totalmoves += 1;
        if(visited[x][y] == 0){
            visited[x][y] = 1;
            visit_knight++;
        }
        knight(arr,visited, x, y, moves-1);
        // x--;
        // y-=2;
    }

    // for left down side
    x = kx+1;
    y = ky-2;
    if(is_safe(arr, x, y) == 1){
        // printf("left down \n");
        // *totalmoves += 1;
        if(visited[x][y] == 0){
            visited[x][y] = 1;
            visit_knight++;
        }
        knight(arr,visited, x, y, moves-1);
        // x++;
        // y-=2;
    }

    // for up right side
    x = kx-2;
    y = ky+1;
    if(is_safe(arr, x, y) == 1){
        // printf("up right \n");
        // *totalmoves += 1;
        if(visited[x][y] == 0){
            visited[x][y] = 1;
            visit_knight++;
        }
        knight(arr,visited, x, y, moves-1);
        // x-=2;
        // y++;
    }

    // for up left side
    x = kx-2;
    y = ky-1;
    if(is_safe(arr, x, y) == 1){
        // printf("up left  \n");
        // *totalmoves += 1;
        if(visited[x][y] == 0){
            visited[x][y] = 1;
            visit_knight++;
        }
        knight(arr,visited, x, y, moves-1);
        // x-=2;
        // y--;
    }
    // return 0;
}

void rook(char arr[8][8],int visited[8][8], int rx, int ry, int moves){
    // base case
    if(moves==0){
        return;
    }
    int x,y;

    // for right side
    x = rx;
    y = ry+1;
    while(is_safe(arr, x, y) == 1){
        // printf("right side \n");
        // *totalmoves += 1;
        if(visited[x][y] == 0){
            visited[x][y] = 1;
            visit_rook++;
        }
        rook(arr,visited, x, y, moves-1);
        // x;
        y++;
    }

    // for left side
    x = rx;
    y = ry-1;
    while(is_safe(arr, x, y) == 1){
        // printf("left side \n");
        // *totalmoves += 1;
        if(visited[x][y] == 0){
            visited[x][y] = 1;
            visit_rook++;
        }
        rook(arr,visited, x, y, moves-1);
        // x;
        y--;
    }

    // for up side
    x = rx-1;
    y = ry;
    while(is_safe(arr, x, y) == 1){
        // printf("for up \n");
        // *totalmoves += 1;
        if(visited[x][y] == 0){
            visited[x][y] = 1;
            visit_rook++;
        }
        rook(arr,visited, x, y, moves-1);
        x--;
        // y;
    }

    // for down side
    x = rx+1;
    y = ry;
    while(is_safe(arr, x, y) == 1){
        // printf("for down \n");
        // *totalmoves += 1;
        if(visited[x][y] == 0){
            visited[x][y] = 1;
            visit_rook++;
        }
        rook(arr,visited, x, y, moves-1);
        x++;
        // y;
    }
    // return 0;
}

int main(){
    char arr[8][8];
    char garbage;
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            scanf("%c", &arr[i][j]);
        }
        scanf("%c", &garbage);
    }
    // for bishop
    int visited_bishop[8][8];
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            visited_bishop[i][j] = 0;
        }
    }
    // for knight
    int visited_knight[8][8];
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            visited_knight[i][j] = 0;
        }
    }
    // for rook
    int visited_rook[8][8];
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            visited_rook[i][j] = 0;
        }
    }

    // for all bishop, knight, rook
    int bx, by, kx,ky,rx,ry;
    scanf("%d %d", &bx, &by);
    scanf("%d %d", &kx, &ky);
    scanf("%d %d", &rx, &ry);
    bx--;
    by--;
    visited_bishop[bx][by] = 1;
    kx--;
    ky--;
    visited_knight[kx][ky] = 1;
    rx--;
    ry--;
    visited_rook[rx][ry] = 1;
    int moves;
    scanf("%d", &moves);
    // int totalmoves = 1;

    bishop(arr,visited_bishop, bx, by, moves);
    knight(arr, visited_knight, kx, ky, moves);
    rook(arr,visited_rook, rx, ry, moves);



    // int visit_bishop = 0;
    // int visit_knight = 0;
    // int visit_rook = 0;
    
    
    // for(int i=0;i<8;i++){
    //     for(int j=0;j<8;j++){
    //         if(visited_bishop[i][j]){
    //             visit_bishop++;
    //         }
    //     }
    // }
    // for(int i=0;i<8;i++){
    //     for(int j=0;j<8;j++){
    //         if(visited_rook[i][j]){
    //             visit_rook++;
    //         }
    //     }
    // }
    // for(int i=0;i<8;i++){
    //     for(int j=0;j<8;j++){
    //         if(visited_knight[i][j]){
    //             visit_knight++;
    //         }
    //     }
    // }

    printf("%d %d %d \n", visit_bishop, visit_knight, visit_rook);


    // for(int i=0;i<8;i++){
    //     for(int j=0;j<8;j++){
    //         printf("%d", visited_rook[i][j]);
    //     }
    //     printf("\n");
    // }
    return 0;
}