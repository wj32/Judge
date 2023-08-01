class Solution {
public:
    bool isRobotBounded(string instructions) {
        using namespace std::complex_literals;
        struct State {
            std::complex<double> position = 0;
            std::complex<double> direction = 1;
        };
        State state;
        for (int i = 0; i < 4; ++i) {
            for (const auto c : instructions) {
                switch (c) {
                case 'G':
                    state.position += state.direction;
                    break;
                case 'L':
                    state.direction *= 1i;
                    break;
                case 'R':
                    state.direction *= -1i;
                    break;
                }
            }
        }
        assert(state.direction == 1.0);
        return state.position == 0.0;
    }
};