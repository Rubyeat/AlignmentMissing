#include <iostream>
#include <fstream>
#include <thread>
#include <string.h>
#include <time.h>
using namespace  std;


string  s1[1500000], s2[1500000], s3[1600000];


string reverse_complement(string s){
    int strlen= s.length();
    string RC = "";
    for(int i=strlen-1; i>=0; i--){
        if(s[i]=='A'||s[i]=='a') RC +='T';
        else if(s[i]=='C'|| s[i]=='c') RC +='G';
        else if(s[i]=='G'|| s[i]=='g') RC +='C';
        else if(s[i]=='T'|| s[i]=='t') RC +='A';
        else continue;
    }


    return RC;

}
int CompareWithOwnself (int startIndex, int kmerlen, int AlignFileLen, string s, string strCh){
    int i=0, j=0, flag=0, x=0, y=0;
    for(i=startIndex; i<AlignFileLen-kmerlen; i++){
        for(j=i; j< i+ kmerlen; j++){
            flag=1;
            if(strCh[j]!=s[j-i]) {
                flag=0;
                break;
            }
        }
        if(flag==1) break;
    }
    if(flag==1 ) return i;
    else
        return -1;
}
int CompareWithOwnselfRC (int startIndex, int kmerlen, int AlignFileLen, string RC, string strCh){
    int i=0, j=0, flag=0, x=0, y=0;

        for(x=startIndex; x<AlignFileLen-kmerlen; x++){
            for(y = x; y< x+ kmerlen; y++){
                flag=2;
                if(strCh[y]!=RC[y-x]) {
                    flag=0;
                    break;
                }
            }
            if(flag==2) break;
        }
    if (flag==2 ) return x;
    else
        return -1;
}
int ThresholdCheck(int MissInGorilla, int MissInHuman, int threshold){
    if(MissInGorilla < threshold && MissInHuman < threshold){
        return 1;
    }
    else
        return 0;
}
int CompareWithOthers(int startIndex, int endIndex, int kmerlen, string strCh, string strHu, string strGo){
    int i=0, MissInHuman=0, MissInGorilla=0, find;
    for (i=startIndex; i<endIndex; i++){
        if(strCh[i]!= strHu[i]) MissInHuman++;
        if(strCh[i]!= strGo[i]) MissInGorilla++;
    }
    find= ThresholdCheck(MissInGorilla, MissInHuman, kmerlen/3);
    return find;
}

int ChunkMissChimp (string s[], int len, string strCh, string strHu, string strGo) {
    ofstream fileOwnMiss("E:\\Thesis\\Test\\12_10\\OwnMissChimp");
    ofstream fileOtherMiss("E:\\Thesis\\Test\\12_10\\OtherMissChimp");
    ofstream fileNotMiss("E:\\Thesis\\Test\\12_10\\NotMissChimp");
    int i = 0, looplen=0, looplenRC=0, startIndex = 0, endIndex = 0, startIndexRC=0, endIndexRC=0, search,find, findRC,CountChimpMiss=0;
    int kmerlen= s[i].length();
    int AlignFileLen= strCh.length();
    for (i = 0; i < len; i++) {
        search=1;
       string RC= reverse_complement(s[i]);
       looplen =0;
       looplenRC=0;
        while (looplen < AlignFileLen-kmerlen || looplenRC < AlignFileLen-kmerlen ){
            startIndex= looplen;
            startIndexRC=looplenRC;
            startIndex=CompareWithOwnself(startIndex, kmerlen, AlignFileLen, s[i], strCh);
            startIndexRC=CompareWithOwnselfRC(startIndexRC, kmerlen, AlignFileLen, RC, strCh);
            if(startIndex== -1 && startIndexRC== -1) {
                (search == 0 ? fileOtherMiss : fileOwnMiss) << s[i] << endl;
                CountChimpMiss++;
                search = 1;
                break;
            }
            else {
                if (startIndex == -1) {
                    endIndexRC = startIndexRC + kmerlen;
                    endIndex = AlignFileLen;
                    findRC = CompareWithOthers(startIndexRC, endIndexRC, kmerlen, strCh, strHu, strGo);
                    find = 0;
                } else if (startIndexRC == -1) {
                    endIndex = startIndex + kmerlen;
                    endIndexRC = AlignFileLen;
                    find = CompareWithOthers(startIndex, endIndex, kmerlen, strCh, strHu, strGo);
                    findRC = 0;
                } else {
                    endIndex = startIndex + kmerlen;
                    endIndexRC = startIndexRC + kmerlen;
                    find = CompareWithOthers(startIndex, endIndex, kmerlen, strCh, strHu, strGo);
                    findRC = CompareWithOthers(startIndexRC, endIndexRC, kmerlen, strCh, strHu, strGo);
                }
            }
            if(find==1 || findRC== 1) {
                fileNotMiss<<s[i]<< endl;
                search=1;
                break;
            }
            else{
                 looplen= endIndex;
                 looplenRC = endIndexRC;
                 search=0;
            }
        }
        if(search==0) {
            fileOtherMiss<<s[i]<<endl;
            CountChimpMiss++;
        }
    }
    fileOwnMiss << "ChimpMissInAlign " << CountChimpMiss << endl;
}
int ChunkMissGorilla (string s[], int len, string strCh, string strHu, string strGo) {
    ofstream fileOwnMiss("E:\\Thesis\\Test\\12_10\\OwnMissGorilla");
    ofstream fileOtherMiss("E:\\Thesis\\Test\\12_10\\OtherMissGorilla");
    ofstream fileNotMiss("E:\\Thesis\\Test\\12_10\\NotMissGorilla");
    int i = 0, looplen = 0, looplenRC = 0, startIndex = 0, endIndex = 0, startIndexRC = 0, endIndexRC = 0, search, find, findRC, CountGorillaMiss = 0;
    int kmerlen = s[i].length();
    int AlignFileLen = strGo.length();
    for (i = 0; i < len; i++) {
        search = 1;
        string RC = reverse_complement(s[i]);
        looplen = 0;
        looplenRC = 0;
        while (looplen < AlignFileLen - kmerlen || looplenRC < AlignFileLen - kmerlen) {
            startIndex = looplen;
            startIndexRC = looplenRC;
            startIndex = CompareWithOwnself(startIndex, kmerlen, AlignFileLen, s[i], strGo);
            startIndexRC = CompareWithOwnselfRC(startIndexRC, kmerlen, AlignFileLen, RC, strGo);
            if(startIndex== -1 && startIndexRC== -1) {
                (search == 0 ? fileOtherMiss : fileOwnMiss) << s[i] << endl;
                CountGorillaMiss++;
                search = 1;
                break;
            }
            else {
                if (startIndex == -1) {
                    endIndexRC = startIndexRC + kmerlen;
                    endIndex = AlignFileLen;
                    findRC = CompareWithOthers(startIndexRC, endIndexRC, kmerlen, strGo, strHu, strCh);
                    find = 0;
                } else if (startIndexRC == -1) {
                    endIndex = startIndex + kmerlen;
                    endIndexRC = AlignFileLen;
                    find = CompareWithOthers(startIndex, endIndex, kmerlen, strGo, strHu, strCh);
                    findRC = 0;
                } else {
                    endIndex = startIndex + kmerlen;
                    endIndexRC = startIndexRC + kmerlen;
                    find = CompareWithOthers(startIndex, endIndex, kmerlen, strGo, strHu, strCh);
                    findRC = CompareWithOthers(startIndexRC, endIndexRC, kmerlen, strGo, strHu, strCh);
                }
            }
            if(find==1 || findRC== 1) {
                fileNotMiss<<s[i]<< endl;
                search=1;
                break;
            }
            else{
                looplen= endIndex;
                looplenRC = endIndexRC;
                search=0;
            }
        }
        if (search == 0) {
            fileOtherMiss << s[i] << endl;
            CountGorillaMiss++;
        }
    }
    fileOwnMiss << "GorillaMissInAlign " << CountGorillaMiss << endl;
}

int ChunkMissHuman (string s[], int len, string strCh, string strHu, string strGo){
    ofstream fileOwnMiss ("E:\\Thesis\\Test\\12_10\\OwnMissHuman");
    ofstream fileOtherMiss ("E:\\Thesis\\Test\\12_10\\OtherMissHuman");
    ofstream fileNotMiss ("E:\\Thesis\\Test\\12_10\\NotMissHuman");
    int i = 0, looplen = 0, looplenRC = 0, startIndex = 0, endIndex = 0, startIndexRC = 0, endIndexRC = 0, search, find, findRC, CountHumanMiss=0;
    int kmerlen= s[i].length();
    int AlignFileLen= strHu.length();
    for (i = 0; i < len; i++) {
        search=1;
        string RC= reverse_complement(s[i]);
        looplen =0;
        looplenRC= 0;
        while (looplen < AlignFileLen-kmerlen && looplenRC< AlignFileLen- kmerlen){
            startIndex= looplen;
            startIndexRC= looplenRC;
            startIndex=CompareWithOwnself(startIndex, kmerlen, AlignFileLen, s[i], strHu);
            startIndexRC=CompareWithOwnself(startIndexRC, kmerlen, AlignFileLen, RC, strHu);
            if(startIndex== -1 && startIndexRC== -1) {
                (search == 0 ? fileOtherMiss : fileOwnMiss) << s[i] << endl;
                CountHumanMiss++;
                search = 1;
                break;
            }
            else{
                if (startIndex == -1) {
                    endIndexRC = startIndexRC + kmerlen;
                    endIndex = AlignFileLen;
                    findRC = CompareWithOthers(startIndexRC, endIndexRC, kmerlen, strHu, strCh, strGo);
                    find = 0;
                } else if (startIndexRC == -1) {
                    endIndex = startIndex + kmerlen;
                    endIndexRC = AlignFileLen;
                    find = CompareWithOthers(startIndex, endIndex, kmerlen, strHu, strCh, strGo);
                    findRC = 0;
                } else {
                    endIndex = startIndex + kmerlen;
                    endIndexRC = startIndexRC + kmerlen;
                    find = CompareWithOthers(startIndex, endIndex, kmerlen, strHu, strCh, strGo);
                    findRC = CompareWithOthers(startIndexRC, endIndexRC, kmerlen, strHu, strCh, strGo);
                }
            }
            if(find==1 || findRC== 1) {
                fileNotMiss<<s[i]<< endl;
                search=1;
                break;
            }
            else{
                looplen= endIndex;
                looplenRC = endIndexRC;
                search=0;
            }
        }
        if(search==0) {
            fileOtherMiss<<s[i]<<endl;
            CountHumanMiss++;
        }
    }
    fileOwnMiss <<"HumanMissInAlign " <<CountHumanMiss<<endl;
}

int main() {
    clock_t tStart = clock();
    int  i=0,j=0;
    int a=0, b=0, c=0, kmerlen=0;
    string str, line;
    ifstream rfile ("E:\\Thesis\\Test\\12_10\\outAll12_11.txt");
    ifstream chfile ("E:\\Thesis\\Test\\12_10\\ChOut");
    ifstream hufile ("E:\\Thesis\\Test\\12_10\\HuOut");
    ifstream grfile ("E:\\Thesis\\Test\\12_10\\GorOut");
    getline(rfile,line);
    while(j<line.length()){
        if(line[j]=='A'|| line[j]=='C' || line[j]=='G' || line[j]=='T'){
            kmerlen++;
        }
        j++;
    }

    if(rfile.is_open()){
        while (getline(rfile, line)){
            if(line[0]=='c') {
                s1[a] = line.substr(7,kmerlen);
                a++;
                i++;
            }

            else if(line[0]=='g'){
                s2[b] = line.substr(9,kmerlen );
                b++;
                i++;
            }
            else if(line[0]=='h'){
                s3[c] = line.substr(7,kmerlen );
                i++;
                c++;
            }
            else{
                i++;
            }

        }
        rfile.close();

    }
    else{
        cout<<"Unable to Open file"<< endl;
    }
    string strCh, strHu, strGo;
    if(chfile.is_open())
        getline(chfile, strCh);
    if(hufile.is_open())
        getline(hufile, strHu);
    if(grfile.is_open())
        getline(grfile, strGo);

//    thread mythreads[5];
//    mythreads[0]= thread(ChunkMissChimp, s1, a);
//    mythreads[1]= thread(ChunkMissGorilla, s2, b);
//    mythreads[2]= thread(ChunkMissHuman, s3, c);
//
//    for(i=0; i<3; i++){
//        mythreads[i].join();
//    }

   ChunkMissChimp (s1, a, strCh, strHu, strGo);
   ChunkMissGorilla (s2, b, strCh, strHu, strGo);
   ChunkMissHuman (s3, c, strCh, strHu, strGo);
//  string s = reverse_complement("AAATATTGTCTCCCA");
//    cout<<s<<endl;
    printf("Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);


    return 0;
}
