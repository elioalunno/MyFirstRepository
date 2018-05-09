#include "lorentzMomentum.h"
using namespace std;

#ifndef _LORENTZMOMENTUM_CXX
#define _LORENTZMOMENTUM_CXX

lorentzMomentum::lorentzMomentum(){
    c_px = 0;
    c_py = 0;
    c_pz = 0;
    c_charge = 0;
}

lorentzMomentum::lorentzMomentum(double px, double py, double pz, int charge){

    c_px = px;
    c_py = py;
    c_pz = pz;
    c_charge = charge;
}

double lorentzMomentum::getBeta() {
    
    double energy = this->getEnergy();
    double beta = 0;
    if(energy<0.0000001){
        cout<<"Energy is 0"<<endl;
    }else{
        beta = this->getP()/this->getEnergy();
    }
    return beta;
}

double lorentzMomentum::getGamma() {
    
    double beta = this->getBeta();
    double gamma = -1;
    if(beta==1.){
        cout<<"Beta is equal to 1, so gamma is infinite"<<endl;
    }else{
        gamma = 1./(sqrt(1-pow(beta,2)));
    }
    return gamma;
}

#endif