#include "./2048/2048.hpp"
#include "./AI/2048_AI.hpp"
#include <iostream>

int main() {
    srand(time(0));
    Game game = Game();
    AI ai = AI(game,1);

    std::cout << to_string(game);
        std::cout << "score = " << game.get_score() << "\n";
    while(!game.is_over()) {
        game.move(ai.calculate_next_move());
        std::cout << to_string(game);
        std::cout << "score = " << game.get_score() << "\n";

    }

    return 0;
}