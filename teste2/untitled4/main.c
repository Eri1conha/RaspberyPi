#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define String char*

typedef struct{
    int x,y;
}pos;


typedef struct{
    int id;
    String nome;
    char sym;
    int next_free;
    pos *History;
}player;


typedef struct{
    player *players[2];
    char array[3][3];
    int winner;
    bool won;
}Game;


player* create_Player(int id, String nome,char sym){

    player *new_player = (player*) malloc(sizeof(player));
    new_player->id=id;
    new_player->sym=sym;
    new_player->nome=nome;
    new_player->next_free=0;
    new_player->History=(pos*) calloc(100,sizeof(pos));
    return new_player;
}


Game* create_game(){

    Game* new_game = (Game*)(malloc(sizeof(Game)));
    new_game->won=false;
    new_game->winner=0;

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            new_game->array[i][j]='-';
        }
    }

    for (int i = 0; i < 2; ++i) {
        new_game->players[i]= NULL;
    }

    return new_game;
}


void add_player(String nomes[] ,Game* game, int size){

    for (int i = 0; i < size; ++i) {
        if(i==0) {
            game->players[i] = create_Player(i, nomes[i],'X');
        }
        else {
            game->players[i] = create_Player(i, nomes[i], 'O');
        }
    }
}


void make_move(player player1,Game game,pos pos1){

    if(game.array[pos1.x][pos1.y]=='-'){
        game.array[pos1.x][pos1.y]=player1.sym;
    }
    player1.History[player1.next_free]=pos1;
    player1.next_free++;
}

void printar_game(Game* game){

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            printf("%c  ",game->array[i][j]);
        }
        printf("\n");
    }



}





bool won(Game *game){





}






int main() {


    Game*game = create_game();

    String nome[] = {"eric","edu"};

    add_player(nome,game,2);

    printar_game(game);

    pos pos1={1,2};

    make_move(*(game->players[0]),*game,pos1);








    return 0;
}
