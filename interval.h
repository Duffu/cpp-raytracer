#pragma once

class interval {
    public:
        double min;
        double max;

        interval() : min(+infinity), max(-infinity) {}
        interval(double min, double max) : min(min), max(max) {}
        bool size() const {
            return max - min;
        }
        bool contains(double x) const {
            return x >= min && x <= max;
        }
        bool surrounds(double x) const {
            return min < x && x < max;
        }
        const static interval empty;
        const static interval universe;
};



const interval interval::empty = interval(+infinity, -infinity);
const interval interval::universe = interval(-infinity, +infinity);