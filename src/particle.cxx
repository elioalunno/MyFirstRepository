#include <particle.h>
//#include <lorentzMomentum.h>

#ifndef _PARTICLE_CXX
#define _PARTICLE_CXX

particle::particle() : lorentzMomentum(){
    
    c_type = particle::UNKNOWN;
    c_nameParticle = "UNKNOWN";
    c_massParticle = 0;
    c_charge = 0;
}

particle::particle(particleType type, double px, double py, double pz, int charge) : lorentzMomentum(px, py, pz, charge){
    
    if(type == particle::ELECTRON){
        c_massParticle = electronMass;
        c_nameParticle = "Electron";
    }else if(type == particle::MUON){
        c_massParticle = muonMass;
        c_nameParticle = "Muon";
    }else if(type == particle::PION){
        c_massParticle = pionMass;
        c_nameParticle = "Pion";
    }else{
        std::cout<<"Particle Type not defined"<<std::endl;
        c_massParticle = -1;
        c_nameParticle = "Unknown";
    }
    
    c_charge = charge;
}

void particle::printInfo(){
    
    cout<<"The particle is a "<< this -> getNameParticle() <<endl;
    cout<<"The momentum is px: " << this -> getMomentumPX() << " py: " << this -> getMomentumPY() <<" e pz: "<<this -> getMomentumPZ() <<endl;
    cout<<"mass: "<< this -> getMass()<< endl << "charge: "<< this -> getCharge() <<endl;
}

#endif