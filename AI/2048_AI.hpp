#pragma once
#include "../2048/2048.hpp"

class AI {
    private:
        Game game;
        int search_depth;

        int score_heuristic(const std::vector<std::vector<int>> tiles);

    public:
        AI(Game& game, int search_depth) : game(game), search_depth(search_depth) {}
        direction calculate_next_move();
};