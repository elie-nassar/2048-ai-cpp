#include "2048.hpp"

Game::Game() {
    tiles = std::vector<std::vector<int>>(4,std::vector<int>(4,0));
    score = 0;
    add_number();
}

void Game::add_number() {
    std::vector<std::pair<int,int>> empty_tiles;

    for(int i=0;i<4;i++) {
        for(int j=0;j<4;j++) {
            if(tiles[i][j]==0) empty_tiles.push_back({i,j});
        }
    }

    if(empty_tiles.empty()) {
        return;
    }

    auto [i,j] = empty_tiles[rand()%empty_tiles.size()];

    tiles[i][j] = rand()%10==0 ? 4 : 2;
}

bool Game::move_left() {
    bool is_moving = false;
    for(int i=0;i<4;i++) {
        for(int j=0;j<4;j++) {
            for(int k=j+1;k<4;k++){
                if(tiles[i][j]==0 && tiles[i][k]!=0){
                    tiles[i][j]=tiles[i][k];
                    tiles[i][k]=0;
                    is_moving=true;
                }
                if(tiles[i][j]==tiles[i][k] && tiles[i][k]!=0){
                    tiles[i][j]*=2;
                    score+=tiles[i][j];
                    tiles[i][k]=0;
                    is_moving=true;
                    break;
                }if(tiles[i][k]!=0 && tiles[i][k]!=tiles[i][j]){
                    break;
                }
            }
        }
    }
    return is_moving;
}

bool Game::move_right() {
    bool is_moving=false;
    for(int i=0;i<4;i++) {
        for(int j=3;j>=0;j--) {
            for(int k=j-1;k>=0;k--){
                if(tiles[i][j]==0 && tiles[i][k]!=0){
                    tiles[i][j]=tiles[i][k];
                    tiles[i][k]=0;
                    is_moving = true;
                }
                if(tiles[i][j]==tiles[i][k] && tiles[i][k]!=0){
                    tiles[i][j]*=2;
                    score+=tiles[i][j];
                    tiles[i][k]=0;
                    is_moving = true;
                    break;
                }if(tiles[i][k]!=0 && tiles[i][k]!=tiles[i][j]){
                    break;
                }
            }
        }
    }
    return is_moving;
}

bool Game::move_up() {
    bool is_moving = false;
    for(int i=0;i<4;i++) {
        for(int j=0;j<4;j++) {
            for(int k=i+1;k<4;k++){
                if(tiles[i][j]==0 && tiles[k][j]!=0){
                    tiles[i][j]=tiles[k][j];
                    tiles[k][j]=0;
                    is_moving=true;
                }
                if(tiles[i][j]==tiles[k][j] && tiles[k][j]!=0){
                    tiles[i][j]*=2;
                    score+=tiles[i][j];
                    tiles[k][j]=0;
                    is_moving=true;
                    break;
                }if(tiles[k][j]!=0 && tiles[k][j]!=tiles[i][j]){
                    break;
                }
            }
        }
    }
    return is_moving;
}
bool Game::move_down() {
    bool is_moving = false;
    for(int i=3;i>=0;i--) {
        for(int j=0;j<4;j++) {
            for(int k=i-1;k>=0;k--){
                if(tiles[i][j]==0 && tiles[k][j]!=0){
                    tiles[i][j]=tiles[k][j];
                    tiles[k][j]=0;
                    is_moving=true;
                }
                if(tiles[i][j]==tiles[k][j] && tiles[k][j]!=0){
                    tiles[i][j]*=2;
                    score+=tiles[i][j];
                    tiles[k][j]=0;
                    is_moving=true;
                    break;
                }if(tiles[k][j]!=0 && tiles[k][j]!=tiles[i][j]){
                    break;
                }
            }
        }
    }
    return is_moving;
}
bool Game::move(direction dir) {
    bool is_moving = false;
    switch (dir) {
        case LEFT:
            is_moving = move_left();
            break;
        case RIGHT:
            is_moving = move_right();
            break;
        case UP:
            is_moving = move_up();
            break;
        case DOWN:
            is_moving = move_down();
            break;
    }
    if(is_moving) add_number();
    return is_moving;
}

int Game::get_score() {
    return score;
}

bool Game::is_over() {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (tiles[i][j] == 0) return false;
            if (j < 3 && tiles[i][j] == tiles[i][j + 1]) return false; 
            if (i < 3 && tiles[i][j] == tiles[i + 1][j]) return false;
        }
    }
    return true;
}

std::string to_string(const Game& game) {
    std::string result  = "";
    for(int i=0;i<9;i++){
        if(i%2==0){
            for(int j=0; j<13+7*4;j++){
                result+= "*";
            }
            result+="\n";
        }else{
            for(int j=0;j<4;j++){
                result+= "* ";
                for(int k=0;k<7 - std::to_string(game.tiles[(i-1)/2][j]).size();k++){
                    result+=" ";
                }
                if(game.tiles[(i-1)/2][j]==0){
                    result+="  ";
                }else{
                    result+=std::to_string(game.tiles[(i-1)/2][j])+" ";
                }
            }
            result+="*\n";
        }
    }
    return result;
}