/*
Student Name:Berkay Demirtaş
Student Number:2017400234
Project Number: 5
Compile Status: [SUCCESS]
Running Status: [SUCCESS]
Notes: Anything you want to say about your code that will be helpful in the grading process.
*/

#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <bits/stdc++.h>
#include <time.h>

using namespace std;


void parseInput(ifstream& ifstream, vector<int> &vector, long long int &pInt, long long int &pInt1);




int main(int argc, char* argv[]){
    clock_t tStart = clock();


    long long  int M;
     long long int N;
    vector<int> price;


    ifstream inFile(argv[1]);
    string line, tmp;



    parseInput(inFile,price, N,M);






    inFile.close();

    sort(price.begin(),price.end());



    ofstream outFile(argv[2]);
    long long int choc[N+1];

   choc[0]=0;

    for(int i=1;i<M+1;i++){

        choc[i]=choc[i-1]+price[i];
        outFile << choc[i] << " ";
    }


    for(int i=M+1;i<N+1;i++){

        choc[i]=choc[i-1]-choc[i-1-M]+choc[i-M]+price[i];

        outFile << choc[i] <<  " ";
    }








    return 0;


}



void parseInput(ifstream& inFile,vector<int> &price, long long int &N,long long int &M) {
    string line, tmp;
    getline(inFile, line);
    istringstream linestream(line);
    getline(linestream, tmp, ' ');
    N=stoi(tmp);
    getline(linestream, tmp, ' ');
    M = stoi(tmp);


    price.push_back(-1);

    for (int i = 0; i < 1; i++) {
        int a;
        getline(inFile, line);
        istringstream linestream(line);
        for(int i=0;i<N;i++) {
            getline(linestream, tmp, ' ');
            price.push_back(stoi(tmp));

        }
    }


    inFile.close();


}