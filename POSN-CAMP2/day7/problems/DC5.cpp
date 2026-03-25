#include <bits/stdc++.h>
using namespace std;

struct point {
    int x = 0;
    int y = 0;
};

double roundToDecimalPlaces(double value, int decimal_places) {
    const double multiplier = std::pow(10.0, decimal_places);
    // Scale, round to nearest integer, then scale back
    return std::round(value * multiplier) / multiplier; 
}

// compute distance
double distance(const point& p1, const point& p2) {
    return sqrt(((p1.x - p2.x)*(p1.x - p2.x)) + (p1.y - p2.y)*(p1.y - p2.y));
}
// comparison for sorting
bool compareX(const point& p1, const point& p2) { return p1.x < p2.x; }
// comparison for sorting
bool compareY(const point& p1, const point& p2) { return p1.y < p2.y; }

// strip closest in y coordinate
double stripClosest(vector<point>& strip, double d) {
    double minDist = d;

    sort(strip.begin(), strip.end(), compareY);

    for (int i = 0; i < strip.size(); ++i) {
        for (int v = i+1; v < strip.size() && (strip[v].y - strip[i].y) < minDist; ++v)
            minDist = min(minDist, distance(strip[i],strip[v]));
    }

    return minDist;
};

// div con function
double minDistUtil(vector<point>& points, int l, int r) {

    // base case (2 or less points)
    if (r-l <= 2) {
        double minDist = 1e18;
        for (int i = l; i < r; ++i) {
            for (int v = i+1; v < r; ++v) {
                minDist = min(minDist, distance(points[i], points[v]));
            }
        }
        return minDist;
    }

    int mid = l + (r-l)/2;
    double midX = points[mid].x;

    double distL = minDistUtil(points, l, mid);
    double distR = minDistUtil(points, mid, r);

    double d = min(distL, distR);

    // get list of min points with distance d from middle
    int k = 0;
    vector<point> strip;
    for (int i = l; i < r; ++i) {
        if (abs(points[i].x - midX) < d) {
            strip.push_back(points[i]);
        }
    }

    double closestStrip = stripClosest(strip, d);

    return (min(closestStrip,d));
}

// main func
double minDist(vector<point>& points) {
    int n = points.size();
    sort(points.begin(), points.end(), compareX);
    return minDistUtil(points, 0, n);
}

int main() {
    int n; cin >> n;
    vector<point> points;
    while (n--) {
        point p;
        cin >> p.x >> p.y;
        points.push_back(p);
    }

    cout << fixed << setprecision(4) << minDist(points);

    return 0;
}