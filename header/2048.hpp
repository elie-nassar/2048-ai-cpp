#include <vector>

enum direction {LEFT,RIGHT,UP,DOWN};

class Game {
    private:
        std::vector<std::vector<int>> tiles; 
        int score;

        void add_number();
        bool move_left();
        bool move_right();
        bool move_up();
        bool move_down();

    public:
        Game();
        Game(const Game& other) : tiles(other.tiles), score(other.score) {}
        bool move(direction dir);
        int get_score();
        bool is_over();

        friend std::string to_string(const Game& game);
};