#include <iostream>
#include <string>
#include <lorentzMomentum.h> 
#include <cmath>
using namespace std;

#ifndef _PARTICLE_H
#define _PARTICLE_H

class particle : public lorentzMomentum{
public:
    
    enum particleType{
        UNKNOWN = 0,
        ELECTRON = 1,
        MUON = 2,
        PION = 3
    };
        
    // constructor
    particle();
    
    //overloading the constructor
    particle(particleType type, double px, double py, double pz, int charge);
    
    //Class variables
    particleType c_type;
    double c_massParticle;
    string c_nameParticle;
    int c_charge;
     
    //Class methods
    void printInfo();
    double getMass(){return c_massParticle;}
    string getNameParticle() {return c_nameParticle;}
    int getCharge(){return c_charge;}

private:
    
    const double electronMass = 0.511; // mass in MeV
    const double pionMass = 139.570;
    const double muonMass = 105.658;
};

#endif 