#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "split.h"
#include "particle.h"
#include "TFile.h"
#include "TTree.h"
#include "TH1F.h"

using namespace std;

int main(){
    
    unsigned int numberElecPos = 0;
    unsigned int numberElecNeg = 0;
    unsigned int numberMuonPos = 0;
    unsigned int numberMuonNeg = 0;
    unsigned int numberPionPos = 0;
    unsigned int numberPionNeg = 0;
    
    //Input file
    string line;
    ifstream myFile ("particle.dat");
    split pippo = split();
    
    //Branch variables
    int id=0;
    double particleEnergy=0;
    int idCharge = 0;
    
    //Root file and TTree
    TFile *particleFile = TFile::Open("macros/particleOutput.root", "RECREATE");
    TTree *events = new TTree("myTree","Particle Events");
    
    events->Branch("id",&id);
    events->Branch("particleEnergy", &particleEnergy);
    events->Branch("idCharge", &idCharge);
    
    
    if (myFile.is_open()){ //Open file
        
        while(getline (myFile, line)){
            
            vector<string> test = pippo.splitLine(line,' ');
            
            for(unsigned int i=0; i< test.size(); i++){
                
                if(test[i] == "muon"){      //Positive and negative particle count
                    
                    particle *muon = new particle(particle::MUON, stod(test[i+2]), stod(test[i+3]), stod(test[i+4]), stoi(test[i+1]));
                    id = 2;
                    particleEnergy = muon->getEnergy();
                    
                    if(muon->getCharge() == -1){
                        numberMuonNeg = numberMuonNeg + 1;
                        idCharge = -1;
                    }else{
                        numberMuonPos = numberMuonPos + 1;
                        idCharge = 1;
                    }
                    events->Fill();
                    delete muon;
                }
                
                if(test[i] == "pion"){
                    
                    particle *pion = new particle(particle::PION, stod(test[i+2]), stod(test[i+3]), stod(test[i+4]), stoi(test[i+1]));
                    id = 3;
                    particleEnergy = pion->getEnergy();
                    
                    if(pion->getCharge() == -1){
                        numberPionNeg = numberPionNeg + 1;
                        idCharge = -1;
                    }else{
                        numberPionPos = numberPionPos + 1;
                        idCharge = 1;
                    }
                    events->Fill();
                    delete pion;
                }
                
                if(test[i] == "electron"){
                    
                    particle *electron = new particle(particle::ELECTRON, stod(test[i+2]), stod(test[i+3]), stod(test[i+4]), stoi(test[i+1]));
                    id = 1;
                    particleEnergy = electron->getEnergy();
                    
                    if(electron->getCharge() == -1){
                        idCharge = -1;
                        numberElecNeg = numberElecNeg + 1;
                    }else{
                        numberElecPos = numberElecPos + 1;
                        idCharge = 1;
                    }
                    
                    events->Fill();
                    delete electron;
                }
                
            }
        }
    myFile.close();
    }
    else{
        cout << "unable to open file" << endl;
    }
    
    cout<<"The muons negative are "<<numberMuonNeg<<" and the positive "<< numberMuonPos <<endl;
    cout<<"The pions negative are "<<numberPionNeg<<" and the positive "<< numberPionPos <<endl;
    cout<<"The electrons negative are "<<numberElecNeg<<" and the positive "<< numberElecPos <<endl;
    
    particleFile->cd();
    events->Write("",TObject::kOverwrite);
    
    delete events;
    delete particleFile;
    
    return 0;
    
}//MAIN