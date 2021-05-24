#include <iostream>
#include <fstream>
#include <string>
#include <time.h>
#include <thread>
#include <map>
using namespace std;
double MisscountCommonChimp = 0.0, MisscountActualChimp=0.0;
double MisscountCommonHuman = 0.0, MisscountActualHuman=0.0;
double MisscountCommonGorilla = 0.0, MisscountActualGorilla=0.0;


void SensivitySpecificityChimp(int kmerlen){
    /* common miss find */

    ifstream MissAF("E:\\Thesis\\Test\\15_11_3\\ChimpMissInAF");
    ifstream MissAlign("E:\\Thesis\\Test\\15_11_3\\OtherMissChimp");
    ofstream CommonMiss("E:\\Thesis\\Test\\15_11_3\\15_8_5ChimpCommonMiss");
   // ofstream NotCommonMiss("E:\\Thesis\\Test\\15_11_3\\18_13ChimpNotCommon");
    map<string, int> Miss;
    map<string, int>::iterator next;
   // double MisscountCommon = 0.0, MisscountActual=0.0;
    string row, subrow;

    if (MissAlign.is_open()) {
        while (getline(MissAlign, row)) {
            subrow = row.substr(0, kmerlen);
            Miss.insert(pair<string, int>(subrow, MisscountActualChimp));
            MisscountActualChimp++;
        }
        MissAlign.close();
    }
    cout<< "Chimp Actual Miss count " << MisscountActualChimp << endl;
    if (MissAF.is_open()) {
        while (getline(MissAF, row)) {
            next=Miss.find(row);
            if(next!=Miss.end()) {
                CommonMiss<<row<<endl;
                MisscountCommonChimp++;
            }
            else{
             //   NotCommonMiss<<row<<endl;
            }
        }
        MissAF.close();
    }
    cout<<"Chimp:: CommonMiss "<<MisscountCommonChimp<<endl;


}
void SensivitySpecificityHuman(int kmerlen){
    /* common miss find */

    ifstream MissAF("E:\\Thesis\\Test\\15_11_3\\HumanMissInAF");
    ifstream MissAlign("E:\\Thesis\\Test\\15_11_3\\OtherMissHuman");
    ofstream CommonMiss("E:\\Thesis\\Test\\15_11_3\\15_8_5HumanCommonMiss");
   // ofstream NotCommonMiss("E:\\Thesis\\Test\\15_11_3\\18_13HumanNotCommon");
    map<string, int> Miss;
    map<string, int>::iterator next;
    //double MisscountCommon = 0, MisscountActual=0;
    string row, subrow;

    if (MissAlign.is_open()) {
        while (getline(MissAlign, row)) {
            subrow = row.substr(0, kmerlen);
            Miss.insert(pair<string, int>(subrow, MisscountActualHuman));
            MisscountActualHuman++;
        }
        MissAlign.close();
    }
    cout<< "Human Actual Miss count " << MisscountActualHuman << endl;
    if (MissAF.is_open()) {
        while (getline(MissAF, row)) {
            next=Miss.find(row);
            if(next!=Miss.end()) {
                CommonMiss<<row<<endl;
                MisscountCommonHuman++;
            }
            else{
              //  NotCommonMiss<<row<<endl;
            }
        }
        MissAF.close();
    }
    cout<< "Human:: CommonMiss "<< MisscountCommonHuman<<endl;


}
void SensivitySpecificityGorilla(int kmerlen){
    /* common miss find */

    ifstream MissAF("E:\\Thesis\\Test\\15_11_3\\GorillaMissInAF");
    ifstream MissAlign("E:\\Thesis\\Test\\15_11_3\\OtherMissGorilla");
    ofstream CommonMiss("E:\\Thesis\\Test\\15_11_3\\15_8_5GorillaCommonMiss");
   // ofstream NotCommonMiss("E:\\Thesis\\Test\\15_11_3\\18_13GorillaNotCommon");
    map<string, int> Miss;
    map<string, int>::iterator next;
  // double MisscountCommon = 0, MisscountActual=0;
    string row, subrow;

    if (MissAlign.is_open()) {
        while (getline(MissAlign, row)) {
            subrow = row.substr(0, kmerlen);
            Miss.insert(pair<string, int>(subrow, MisscountActualGorilla));
            MisscountActualGorilla++;
        }
        MissAlign.close();
    }
    cout<< "Gorilla Actual Miss count " << MisscountActualGorilla << endl;
    if (MissAF.is_open()) {
        while (getline(MissAF, row)) {
            next=Miss.find(row);
            if(next!=Miss.end()) {
                CommonMiss<<row<<endl;
                MisscountCommonGorilla++;
            }
            else{
              //  NotCommonMiss<<row<<endl;
            }
        }
        MissAF.close();
    }
    cout<<"Gorilla:: CommonMiss "<<MisscountCommonGorilla<<endl;

//    /* Sensitivity and Specificity Calculation */
//
//    double sensitivity, specificity;
//
//    sensitivity = (MisscountCommon/MisscountActual)*100;
//    specificity = (MisscountCommon/MisscountPredict)*100;
//
//    CommonMiss << "Gorilla:: Sensitivity  " << sensitivity << "  Specificity  " << specificity << endl;
}
int main() {
    clock_t tStart = clock();

/* Miss in Alignment Free file */
    ifstream rfile("E:\\Thesis\\Test\\15_11_3\\outAll15_8_5.txt");
    ofstream ChimpMissInAF("E:\\Thesis\\Test\\15_11_3\\ChimpMissInAF");
    ofstream GorillaMissInAF("E:\\Thesis\\Test\\15_11_3\\GorillaMissInAF");
    ofstream HumanMissInAF("E:\\Thesis\\Test\\15_11_3\\HumanMissInAF");

    map<string, int> ChimpmissFile;
    map<string, int> GorillamissFile;
    map<string, int> HumanmissFile;
    map<string, int> missFile;
    map<string, int>::iterator itr;
    string line, str;
    int hmiss = 0, gmiss = 0, cmiss = 0, i=0, j = 0,k=0, kmerlen = 0, MisscountPredict=0;
    getline(rfile, line);
    while(j<line.length()){
        if (line[j] == 'A' || line[j] == 'C' || line[j] == 'G' || line[j] == 'T') {
            kmerlen++;
        }
        j++;
    }


    if (rfile.is_open()) {
        while (getline(rfile, line)) {
            if(line[line.length()-1]=='M'){
                if (line[0] == 'h') {
                    str = line.substr(7, kmerlen);
                    hmiss++;
                    HumanmissFile.insert(pair<string, int>(str, k));
                    k++;

                }
                else if (line[0] == 'g') {
                    str = line.substr(9, kmerlen);
                    gmiss++;
                    GorillamissFile.insert(pair<string, int>(str, k));
                    k++;
                }
                else if (line[0] == 'c') {
                    cmiss++;
                    str = line.substr(7, kmerlen);
                    ChimpmissFile.insert(pair<string, int>(str, k));
                    k++;
                }
            }
        }
//        for (itr = missFile.begin(); itr != missFile.end(); itr++) {
//            MissInAF << itr->first << endl;
//           MisscountPredict++;
//       }
        for (itr = ChimpmissFile.begin(); itr != ChimpmissFile.end(); itr++) {
            ChimpMissInAF << itr->first << endl;
            MisscountPredict++;
        }
        for (itr = HumanmissFile.begin(); itr != HumanmissFile.end(); itr++) {
            HumanMissInAF << itr->first << endl;
            MisscountPredict++;
        }
        for (itr = GorillamissFile.begin(); itr != GorillamissFile.end(); itr++) {
            GorillaMissInAF << itr->first << endl;
            MisscountPredict++;
        }

        cout << "Human Miss: " << hmiss << " Gorilla Miss: " << gmiss << " Chimp Miss: " << cmiss << endl;
        rfile.close();
    }

//    thread mythreads[5];
//
//    mythreads[0]= thread(SensivitySpecificityChimp, MisscountPredict);
//    mythreads[1]= thread(SensivitySpecificityHuman, MisscountPredict);
//    mythreads[2]= thread(SensivitySpecificityGorilla, MisscountPredict);
//
//    for (i=0; i<3; i++){
//        mythreads[i].join();
//    }
        MisscountPredict= cmiss + gmiss + hmiss;
        SensivitySpecificityChimp(kmerlen);
       SensivitySpecificityGorilla(kmerlen);
       SensivitySpecificityHuman(kmerlen);

       double MissCountActual = MisscountActualChimp + MisscountActualHuman + MisscountActualGorilla;
       double MissCountCommon= MisscountCommonChimp + MisscountCommonHuman + MisscountCommonGorilla;

       double sensitivity, specificity;
       sensitivity = (MissCountCommon/MissCountActual)*100;
       specificity= (MissCountCommon/MisscountPredict)*100;

       cout<<"Sensitivity: "<<sensitivity<<" "<<"Specificity: "<<specificity;




    printf("Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    return 0;

}



