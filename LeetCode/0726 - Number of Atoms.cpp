class Solution {
public:
    map<string, int> parseElement(const string& s, int& i) {
        map<string, int> elements;

        if (isupper(s[i])) {
            int j = i;
            i++;
            while (islower(s[i])) {
                i++;
            }
            elements[s.substr(j, i - j)] = 1;
        }
        else if (s[i] == '(') {
            i++;
            elements = parseElementList(s, i);
            assert(s[i] == ')');
            i++;
        }
        else {
            return {};
        }

        if (isdigit(s[i])) {
            int number = 0;
            while (isdigit(s[i])) {
                number *= 10;
                number += s[i] - '0';
                i++;
            }
            for (auto& p : elements) {
                p.second *= number;
            }
        }

        return elements;
    }

    map<string, int> parseElementList(const string& s, int& i) {
        map<string, int> elements;

        while (true) {
            const auto subElements = parseElement(s, i);
            if (subElements.empty()) {
                break;
            }
            for (const auto& p : subElements) {
                elements[p.first] += p.second;
            }
        }

        return elements;
    }

    string countOfAtoms(string formula) {
        formula.append(1, '.');

        int i = 0;
        const auto elements = parseElementList(formula, i);
        assert(formula[i] == '.');

        string result;
        for (const auto& p : elements) {
            result.append(p.first);
            if (p.second != 1) {
                result.append(to_string(p.second));
            }
        }
        return result;
    }
};
