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
    unsigned int x;
    unsigned int y;
};

static struct Ship_struct ships[TOTAL_SHIPS];
static unsigned int board[BOARD_SIZE * BOARD_SIZE];


unsigned int get_coord(struct Coordinates coords){
    // returns tile value
    if (coords.y > 1){
        return (BOARD_SIZE * (coords.y - 1)) + coords.x;
    }
    else{
        return coords.x;
    }
}

int shoot(struct Coordinates coords){
    unsigned int index = get_coord(coords);
    unsigned int tile = board[index];
    if (tile == 0){
        // Tile was empty!
        printf("Shot hit the water!\n");
        board[index] = TOTAL_SHIPS;
        return 1;
    }
    else if (tile == TOTAL_SHIPS){
        //Tile already fired at!
        printf("Tile was already fired at before!\n");
        return 0;
    }
    else {
        //Ship was hit
        ships[tile].hits++;
        printf("A ship was hit!\n");

        if (ships[tile].hits >= ships[tile].len){
            //Ship sunk; set tile to sizeof(ships)
            board[index] = TOTAL_SHIPS;
            printf("Ship sunk!\n");
        }
        return 1;
    }

}
int _check_for_space_x(struct Coordinates coords, unsigned int space, int dir){
    // dir is either 1 or -1;
    // space is the len of the ship (aka space required to place the ship)
    struct Coordinates next_coords;
    next_coords.x = coords.x;
    next_coords.y = coords.y;
    int i;
    for (i = dir; i < (space * dir); i += dir){
        //add i to x,
           next_coords.x = coords.x + i;
        if(board[get_coord(next_coords)] == 0){
            continue;
        }
        else{
            return 0;
        }
    }
    return 1;
}

int _check_for_space_y(struct Coordinates coords, unsigned int space, int dir){
    // dir is either 1 or -1;
    // space is the len of the ship (aka space required to place the ship)
    struct Coordinates next_coords;
    next_coords.x = coords.x;
    next_coords.y = coords.y;
    int i;
    for (i = dir; i < (space * dir); i += dir){
        //add i to x,
        next_coords.y = coords.y + i;
        if(board[get_coord(next_coords)] == 0){
            continue;
        }
        else{
            return 0;
        }
    }
    return 1;
}

int check_for_space_up(struct Coordinates coords, struct Ship_struct ship){
    return _check_for_space_y(coords, ship.len, -1);
}
int check_for_space_left(struct Coordinates coords, struct Ship_struct ship){
    return _check_for_space_x(coords, ship.len, -1);
}
int check_for_space_down(struct Coordinates coords, struct Ship_struct ship){
    return _check_for_space_y(coords, ship.len, 1);
}
int check_for_space_right(struct Coordinates coords, struct Ship_struct ship){
    return _check_for_space_x(coords, ship.len, 1);
}


struct Coordinates random_coords(){
    struct Coordinates coords;
    coords.x = 1;
    coords.y = 1;
    return coords;
}

void place_ship(struct Coordinates coords, struct Ship_struct ship){
    srand(time(NULL));
    int vertical = rand() % 2;

    if (vertical == 1){
        //check for space vertically
        if (check_for_space_down(coords, ship) == 1){
            //There's enough room for the ship to be placed this way;
        }
        else if (check_for_space_up(coords, ship) == 1){
            //There's enough room for the ship to be placed this way;
            
        }
        else{
            //There isn't enough room for the ship to be placed; get new coords!
        }
    }
    else{
        //check horizontally
        if (check_for_space_right(coords, ship) == 1){
            //There's enough room for the ship to be placed this way;
        }
        else if (check_for_space_left(coords, ship) == 1){
            //There's enough room for the ship to be placed this way;
        }
        else{
            //There isn't enough room for the ship to be placed; get new coords!
        }
    }

}


int main(){


    int c;
    for (c = 0; c < TOTAL_SHIPS; c++){
        srand(time(NULL));
        ships[c].len = SHIP_SIZE;
        ships[c].hits = 0;
        printf("%zu\n", ships[c].len);
    }

    return 0;
}

