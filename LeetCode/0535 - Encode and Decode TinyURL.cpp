class Solution {
private:
    map<long long, string> shortToUrl;
    map<string, long long> urlToShort;
    long long nextShort = 1;

public:

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        const auto it = urlToShort.find(longUrl);
        if (it != urlToShort.end()) {
            return to_string(it->second);
        }
        const auto s = nextShort++;
        shortToUrl.insert({s, longUrl});
        urlToShort.insert({longUrl, s});
        return to_string(s);
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        const auto it = shortToUrl.find(stoll(shortUrl));
        if (it != shortToUrl.end()) {
            return it->second;
        }
        else {
            return "";
        }
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));
