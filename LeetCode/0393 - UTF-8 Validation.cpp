class Solution {
public:
    enum class State {
        Initial,
        One,
        Two,
        Three,
    };

    bool validUtf8(vector<int>& data) {
        auto state = State::Initial;
        for (const int x : data) {
            switch (state) {
            case State::Initial:
                if ((x & 0x80) == 0) {
                    state = State::Initial;
                }
                else if ((x & 0xe0) == 0xc0) {
                    state = State::One;
                }
                else if ((x & 0xf0) == 0xe0) {
                    state = State::Two;
                }
                else if ((x & 0xf8) == 0xf0) {
                    state = State::Three;
                }
                else {
                    return false;
                }
                break;

            case State::One:
                if ((x & 0xc0) == 0x80) {
                    state = State::Initial;
                }
                else {
                    return false;
                }
                break;

            case State::Two:
                if ((x & 0xc0) == 0x80) {
                    state = State::One;
                }
                else {
                    return false;
                }
                break;

            case State::Three:
                if ((x & 0xc0) == 0x80) {
                    state = State::Two;
                }
                else {
                    return false;
                }
                break;
            }
        }
        return state == State::Initial;
    }
};
