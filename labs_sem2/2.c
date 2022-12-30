#include<stdio.h>

int main(){
    int row,col;
    scanf("%d %d", &row,&col);
    int arr[row][col];
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            scanf("%d", &arr[i][j]);
        }
    }

    int right=0,down=0,pos_x=0,pos_y=0,amount = 0;
    while(pos_x < col && pos_y < row){
        // if(pos_y==row && (pos_x+2)<col){
        //     break;
        // }
        // if(pos_x==col && (pos_y+2)<row){
        //     break;
        // }
        amount += arr[pos_y][pos_x];

        if (pos_x == col-1){
            if(down<2){
                down++;
                pos_y++;
            }
            else{
                break;
            }
        }

        else if(pos_y == row-1){
            if(right<2){
                right++;
                pos_x++;
            }
            else{
                break;
            }
        }

        else if(arr[pos_y+1][pos_x]<=arr[pos_y][pos_x+1]){
            if(down<2){
                down++;
                pos_y++;
                right = 0;
            }
            else{
                pos_x++;
                right++;
                down=0;
            }
        }
        else if(arr[pos_y+1][pos_x]>arr[pos_y][pos_x+1]){
            if(right<2){
                right++;
                pos_x++;
                down = 0;
            }
            else{
                pos_y++;
                down++;
                right=0;
            }
        }
        
        
        printf("%d %d %d \n", pos_x,pos_y,amount);
    }

    if (pos_x == col){
        pos_x--;
    }
    else if (pos_y == row){
        pos_y--;
    }

    if(pos_x==col-1 && pos_y==row-1){
        printf("%d", amount);
    }
    else{
        printf("-1");
    }

    // for(int i=0;i<row;i++){
    //     for(int j=0;j<col;j++){
    //         printf("%d", arr[i][j]);
    //     }
    //     printf("\n");
    // }
    return 0;
}