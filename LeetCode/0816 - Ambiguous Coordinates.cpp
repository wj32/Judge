class Solution {
public:
    struct NumberState {
        string a;
        bool complete = false;
        bool dot = false;
        bool leadingZero = false;
    };

    struct State {
        NumberState x;
        NumberState y;
    };

    void recurse(const string& s, size_t index, State& state, vector<string>& r) {
        const auto recurseNumber = [&](NumberState& ns) {
            assert(!ns.complete);

            if (!ns.a.empty() && (ns.a.back() != '.') && (!ns.dot || (ns.a.back() != '0'))) {
                ns.complete = true;
                recurse(s, index, state, r);
                ns.complete = false;
            }

            if (index < s.size() - 1) {
                if (!ns.a.empty() && !ns.dot) {
                    ns.dot = true;
                    ns.a.push_back('.');
                    recurse(s, index, state, r);
                    ns.a.pop_back();
                    ns.dot = false;
                }

                if (!ns.dot) {
                    if (!ns.leadingZero) {
                        if (ns.a.empty() && (s[index] == '0')) {
                            ns.leadingZero = true;
                        }
                        ns.a.push_back(s[index]);
                        recurse(s, index + 1, state, r);
                        ns.a.pop_back();
                        ns.leadingZero = false;
                    }
                }
                else {
                    ns.a.push_back(s[index]);
                    recurse(s, index + 1, state, r);
                    ns.a.pop_back();
                }
            }
        };

        if (!state.x.complete) {
            recurseNumber(state.x);
        }
        else if (!state.y.complete) {
            recurseNumber(state.y);
        }
        else if (index == s.size() - 1) {
            r.push_back("(" + state.x.a + ", " + state.y.a + ")");
        }
    }

    vector<string> ambiguousCoordinates(string S) {
        State state;
        vector<string> r;
        recurse(S, 1, state, r);
        return r;
    }
};
