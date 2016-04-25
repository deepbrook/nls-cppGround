#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define BOARD_SIZE 5
#define TOTAL_SHIPS 6
#define SHIP_SIZE 3

struct Ship_struct {
    size_t hits;
    size_t len;
};

struct Coordinates {
    char x;
    char y;
};

// Construct Arrays for ships and board.
static struct Ship_struct ships[TOTAL_SHIPS];
static char board[BOARD_SIZE * BOARD_SIZE];


// Func to convert user input x,y coordinate to array index;
char coord_to_index(struct Coordinates coords){
    // returns tile value
    if (coords.y > 1){
        return (BOARD_SIZE * (coords.y - 1)) + coords.x;
    }
    else{
        return coords.x;
    }
}

char check_direction(char index, char dir){
    char counter = 0;
    // Check if we're within bounds..
    if((index % BOARD_SIZE !=  0 && index % BOARD_SIZE != 4) && 
       (index > BOARD_SIZE-1 && index < BOARD_SIZE * (BOARD_SIZE - 1))){ //If we're within bounds.
       
       char other_dir; // stores value for opposite axis.
       
       if (dir == BOARD_SIZE || dir == BOARD_SIZE * -1){
           other_dir = 1;} // Set value to 1, since dir is vertical
       else if (dir == 1 || dir == -1){
           other_dir = BOARD_SIZE; // Set value to BOARD_SIZE, since dir is horizontal
       }
        if (check_space(index + dir) + check_space(index - dir) +
            check_space(index + other_dir) + check_space(index - other_dir) == 4){
            // If all neighbouring fields are empty
            counter ++;
            counter += check_neighbors(index, dir);
            return counter;
        }
    }
}


char place_ship(struct Ship_struct ship)
{
    srand(time(0))
    char x = rand() % BOARD_SIZE * BOARD_SIZE;

}

int main(){

}