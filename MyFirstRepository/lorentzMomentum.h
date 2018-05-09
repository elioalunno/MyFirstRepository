#include <iostream>
#include <cmath>

#ifndef _LORENTZMOMENTUM_H
#define _LORENTZMOMENTUM_H

class lorentzMomentum{
    
public:
    lorentzMomentum(); //Constructor
    lorentzMomentum(double px, double py, double pz, int charge);
    void setMomentumPX(double px){c_px = px;};
    void setMomentumPY(double py){c_py = py;};
    void setMomentumPZ(double pz){c_pz = pz;};
    double getMomentumPX() const {return c_px;};
    double getMomentumPY() const {return c_py;};
    double getMomentumPZ() const {return c_pz;};
    double getEnergy(){return sqrt(pow(c_px,2) + pow(c_py,2) +pow(c_pz,2) + pow(c_mass,2));};
    double getP(){return sqrt(pow(c_px,2) + pow(c_py,2) +pow(c_pz,2));};
    double getBeta();
    double getGamma();
    
private:
    //const double electronMass = 0.511;
    double c_mass;
    double c_energy;
    double c_px;
    double c_py;
    double c_pz;
    double c_charge;
};
    
#endif