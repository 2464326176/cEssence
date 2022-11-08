/*
 * @Author: yh
 * @Date: 2022/10/26 23:57
 * @Description: 
 * @FilePath: stone.h
 */

#ifndef CESSENCE_OBJECTORIENTEDPROGRAM_CONVERSIONFUNCTION_STONE_H
#define CESSENCE_OBJECTORIENTEDPROGRAM_CONVERSIONFUNCTION_STONE_H

class Stonewt {
public:
    Stonewt() = default;
    Stonewt(double lbs);
    Stonewt(int stn, double lbs);
    ~Stonewt() = default;
    void show_lbs() const;
    void show_stn() const;
    // conversion functions
    operator int() const;
    operator double() const;
private:
    enum { Lbs_per_stn = 14 };      // pounds per stone
    int stone = 0;                    // whole stones
    double pds_left = 0.0l;              // fractional pounds
    double pounds = 0.0l;                // entire weight in pounds
};

#endif //CESSENCE_OBJECTORIENTEDPROGRAM_CONVERSIONFUNCTION_STONE_H
