void histFile(){
    
    int id;
    double particleEnergy;
    int idCharge;
    
    TCanvas *d = new TCanvas;
    d->SetWindowSize(1000,1000);
    
    TCanvas *d1 = new TCanvas;
    d1->SetWindowSize(1000,1000);
    
    TCanvas *d2 = new TCanvas;
    d2->SetWindowSize(1000,1000);
    
    TFile *file = new TFile("particleOutput.root","READ");
    TTree *particle = (TTree*)file -> Get("myTree");    
    
    particle -> SetBranchAddress("id",&id);
    particle -> SetBranchAddress("particleEnergy",&particleEnergy);
    particle -> SetBranchAddress("idCharge",&idCharge);
    
    
    TH1F *histElecPos = new TH1F("histElecPos","Electron Energy Spectrum",200,0,500);
    TH1F *histElecNeg = new TH1F("histElecNeg","Electron Energy Spectrum",200,0,500);
    
    TH1F *histPionPos = new TH1F("histPionPos","Pion Energy Spectrum",200,0,500);
    TH1F *histPionNeg = new TH1F("histPionNeg","Pion Energy Spectrum",200,0,500);    
    
    TH1F *histMuonPos = new TH1F("histMuonPos","Muon Energy Spectrum",200,0,500);
    TH1F *histMuonNeg = new TH1F("histMuonNeg","Muon Energy Spectrum",200,0,500);

    
    for(int i=0; i<particle->GetEntries(); i++){
        
        particle->GetEntry(i);
        
        if(id == 1){
            if(idCharge == 1){
                histElecPos->Fill(particleEnergy);
            }else{
                histElecNeg->Fill(particleEnergy);
            }
        }
        
        if(id == 2){
            if(idCharge == 1){
                histMuonPos->Fill(particleEnergy);
            }else{
                histMuonNeg->Fill(particleEnergy);
            }
        }
        
        if(id == 3){
            if(idCharge == 1){
                histPionPos->Fill(particleEnergy);
            }else{
                histPionNeg->Fill(particleEnergy);
            }
            
        }
    }
    
    //Histogram 1
    d->cd();
    
    histElecPos->SetFillStyle(3395);
    histElecNeg->SetFillStyle(3021);

    histElecPos->SetFillColor(kBlue);
    histElecNeg->SetFillColor(kRed);
    
    histElecPos->GetYaxis()->SetTitle("Counts");
    histElecPos->GetXaxis()->SetTitle("E (MeV)");
    histElecPos->GetYaxis()->SetLabelSize(0.03);
    histElecPos->GetXaxis()->SetLabelSize(0.03);
    histElecPos->GetYaxis()->SetTitleSize(0.035);
    histElecPos->GetXaxis()->SetTitleSize(0.035);
    histElecPos->GetYaxis()->SetTitleOffset(1.3);
    histElecPos->GetXaxis()->SetTitleOffset(1);
    
    histElecPos->Draw();
    histElecNeg->Draw("SAME");
    
    TLegend *leg = new TLegend(0.7,0.65,0.85,0.75);
    leg->SetFillStyle(0);
    leg->SetBorderSize(0);
    leg->AddEntry(histElecPos,"Positive Electron","f");
    leg->AddEntry(histElecNeg,"Negative Electron","f");
    leg->Draw();
    
    d->SaveAs("ElectronsSpectrum.jpg");
    
    //Histogram 2
    d1->cd();
    
    histMuonPos->SetFillStyle(3395);
    histMuonNeg->SetFillStyle(3021);

    histMuonPos->SetFillColor(kBlue);
    histMuonNeg->SetFillColor(kRed);
    
    histMuonPos->GetYaxis()->SetTitle("Counts");
    histMuonPos->GetXaxis()->SetTitle("E (MeV)");
    histMuonPos->GetYaxis()->SetLabelSize(0.03);
    histMuonPos->GetXaxis()->SetLabelSize(0.03);
    histMuonPos->GetYaxis()->SetTitleSize(0.035);
    histMuonPos->GetXaxis()->SetTitleSize(0.035);
    histMuonPos->GetYaxis()->SetTitleOffset(1.3);
    histMuonPos->GetXaxis()->SetTitleOffset(1);
    
    histMuonPos->Draw();
    histMuonNeg->Draw("SAME");
    
    TLegend *leg2 = new TLegend(0.7,0.65,0.85,0.75);
    leg2->SetFillStyle(0);
    leg2->SetBorderSize(0);
    leg2->AddEntry(histMuonPos,"Positive Muons","f");
    leg2->AddEntry(histMuonNeg,"Negative Muons","f");
    leg2->Draw();
    
    d1->SaveAs("MuonsSpectrum.jpg");
    
    //Histogram 1
    d2->cd();
        
    histPionPos->SetFillStyle(3395);
    histPionNeg->SetFillStyle(3021);

    histPionPos->SetFillColor(kBlue);
    histPionNeg->SetFillColor(kRed);
    
    histPionPos->GetYaxis()->SetTitle("Counts");
    histPionPos->GetXaxis()->SetTitle("E (MeV)");
    histPionPos->GetYaxis()->SetLabelSize(0.03);
    histPionPos->GetXaxis()->SetLabelSize(0.03);
    histPionPos->GetYaxis()->SetTitleSize(0.035);
    histPionPos->GetXaxis()->SetTitleSize(0.035);
    histPionPos->GetYaxis()->SetTitleOffset(1.3);
    histPionPos->GetXaxis()->SetTitleOffset(1);
    
    histPionPos->Draw();
    histPionNeg->Draw("SAME");
    
    TLegend *leg3 = new TLegend(0.7,0.65,0.85,0.75);
    leg3->SetFillStyle(0);
    leg3->SetBorderSize(0);
    leg3->AddEntry(histPionPos,"Positive Pions","f");
    leg3->AddEntry(histPionNeg,"Negative Pions","f");
    leg3->Draw();

    d2->SaveAs("PionsSpectrum.jpg");
}