class Solution {
private:
    random_device rd;
    mt19937 gen;
    double radius;
    double centerX;
    double centerY;

public:
    Solution(double radius, double x_center, double y_center) :
        gen(rd()), radius(radius), centerX(x_center), centerY(y_center) {
    }

    vector<double> randPoint() {
        std::uniform_real_distribution<> dist(0.0, 1.0);
        const auto pi = 3.14159265358979;
        const auto r = sqrt(dist(gen));
        const auto t = 2 * pi * dist(gen);
        return {centerX + (radius * r * cos(t)), centerY + (radius * r * sin(t))};
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(radius, x_center, y_center);
 * vector<double> param_1 = obj.randPoint();
 */
