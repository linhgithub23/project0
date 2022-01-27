/*
    * Ho Chi Minh City University of Technology
    * Faculty of Computer Science and Engineering
    * Initial code for Assignment 0
    * Programming Fundamentals Spring 2022
    * Author: Tran Huy
    * Date: 06.01.2022
*/

//The library here is concretely set, students are not allowed to include any other libraries.
#ifndef studyInPink_h
#define studyInPink_h

#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <fstream>

using namespace std;

////////////////////////////////////////////////////////////////////////
///STUDENT'S ANSWER BEGINS HERE
///Complete the following functions
///DO NOT modify any parameters in the functions.
////////////////////////////////////////////////////////////////////////

int firstMeet(int& EXP1, int& EXP2, const int& E1) {

    //first case
    //EXP1 = [0,399]
    //work with exp2
    if (E1 >= 0 && E1 <= 399) {
        //first case
        //EXP1 = [0,399]
        //work with exp2
        if (E1 >= 0 && E1 <= 49)//1
            EXP2 += 25;
        else if (E1 >= 50 && E1 <= 99)//2
            EXP2 += 50;
        else if (E1 >= 100 && E1 <= 149)//3
            EXP2 += 85;
        else if (E1 >= 150 && E1 <= 199)//4
            EXP2 += 75;
        else if (E1 >= 200 && E1 <= 249)//5
            EXP2 += 110;
        else if (E1 >= 250 && E1 <= 299)//6
            EXP2 += 135;
        else if (E1 >= 300 && E1 <= 399)//7
            EXP2 += 160;
        //work with EXP1
        if (E1 % 2 == 0) {
            EXP1 = ceil((double)EXP1-(double)E1/5);

        } else {
            EXP1 = EXP1 + ceil((double)E1/10);

        }

    }
    //Second case
    //E1 = [400,999]
    if (E1 >= 400 && E1 <= 999) {
        if (E1 >= 400 && E1 <= 499) {
            EXP2 = EXP2  + ceil((double) E1 / 7) + 9;
        } else if (E1 >= 500 && E1 <= 599) {
            EXP2 = EXP2 + ceil((double) E1 / 9) + 11;
        } else if (E1 >= 600 && E1 <= 699) {
            EXP2 = EXP2 + ceil((double) E1 / 5) + 6;
        } else if (E1 >= 700 && E1 <= 799) {
            EXP2 = EXP2 + ceil((double) E1 / 7) + 9;
            if (EXP2 > 200) {
                EXP2 = EXP2 + ceil((double) E1 / 9) + 11;
            }
        } else if (E1 >= 800 && E1 <= 999) {
            EXP2 = ceil(EXP2 +  (double)E1 / 7 + 9 + (double)E1 / 9 + 11);
            if (EXP2 > 600) {
                EXP2 = EXP2 + ceil((double) E1 / 5) + 6;
                EXP2 = EXP2 + ceil((double)EXP2 * 0.15);

            }
        }
        //work with EXP1
        EXP1 = ceil((double)EXP1 - (double)0.1 * E1);
    }
    //Guarantee the value of EXP1 & EXP 2
    if (EXP2 > 900) {
        EXP2 = 900;
    } else if (EXP2 < 0) {
        EXP2 = 0;
    }
    if (EXP1 > 900) {
        EXP1 = 900;
    } else if (EXP1 < 0) {
        EXP1 = 0;
    }
    if(E1 > 999 || E1 < 0){
        return -999;
    }
    else {
        return EXP1+EXP2;
    }

}


int investigateScene(int& EXP1, int& EXP2, int& HP2, int& M2, const int& E2){
    //Period 1
    //E2 = [0,299]
    if(E2 >= 0 && E2 <= 999) {
        double adder_1 = ceil((double) E2 / 9)+10;
        double adder_2 = ceil((double) E2 * 0.35);
        double adder_3 = ceil(0.17 * (double) (adder_1 + adder_2));


        if (E2 >= 0 && E2 <= 299) {
            //add value to watson's exp
            EXP2 = EXP2 + adder_1;
            //add value to sherlock's exp
            if (adder_1 >= 0) {
                EXP1 = EXP1 + ceil((double)adder_1 / 3);
            }
        }
        //E2 = [300,499]
        if (E2 >= 300 && E2 <= 499) {
            //add value to watson's exp
            EXP2 = EXP2 + adder_1 + adder_2;
            //add value to Sherlock exp
            if ((adder_2 + adder_1) >= 0) {
                EXP1=ceil((double)EXP1+adder_1/3)+ceil(adder_2/3);
            }
        }
        //E2 = [500,999]
        if (E2 >= 500 && E2 <= 999) {
            //add value to watson's exp
            EXP2 = EXP2 + adder_1 + adder_2 + adder_3;
            if (adder_3 > 0) {
                EXP1 = ceil((double)ceil((double)EXP1+adder_1/3)+adder_2/3) + ceil(adder_3/3);
            }
        }


        /* *************************** */

        //Period 2

        double road_length = pow(E2, 3);
         HP2=ceil((double)HP2-(double)road_length/(pow(2,23)));
        if (E2 % 2 == 0) {
            M2 = M2 + ceil((double)(pow(E2,2)/50));
            if (M2 >= 2000) {
                M2 = 2000;
            }
        } else {
            M2 += 0;
        }
        //guarantee the value of EXP1, EXP2, HP2, M2
        if (EXP1 < 0){
            EXP1 = 0;
        }
        else{
            if(EXP1 > 900){
                EXP1 = 900;
            }
        }

        if (EXP2 < 0){
            EXP2 = 0;
        }
        else{
            if(EXP2 > 900){
                EXP2 = 900;
            }
        }

        if (HP2 < 0){
            HP2 = 0;
        }
        else{
            if(HP2 > 999){
                HP2 = 999;
            }
        }

        if (M2 < 0){
            M2 = 0;
        }
        else{
            if(M2 > 2000){
                M2 = 2000;
            }
        }

        return EXP1+EXP2+HP2+M2;
    }
    else{
        return -999;
    }

}

int traceLuggage(int& HP1, int& EXP1, int& M1, const int& E3){
    int k1 =0,k2=0,k3=0,k4=0; //the position of the luggage
    if(E3 >= 0 && E3 <= 999) { //the conditions of E3
        bool check1 = false, check2 = false, check3 = false, check4 = false;
        //First road
        int p1j[9] = {1, 3, 5, 7, 9, 11, 13, 15, 17};
        int is80_1 = 0;
        for (int & i : p1j) {
            i = (i + E3) % 26 + 65;

        }
        for(int i = 0; i < 9; i++){
            if (p1j[i] == 80) {
                k1 = i + 1;
                is80_1+=1;
                break;
            }
        }
        //check whether it reaches 80 or not
        if(is80_1 == 1){
            check1 = true;
            HP1 = HP1 - 80 * k1 * 2;
            EXP1 = EXP1 + (1000 - 80 * k1) % 101;
            M1=ceil((double)M1-(double)(k1*E3/9));
        }
        else{
            M1=M1-9*E3;
        }

        // Second road
        int p2i[7] = {2, 3, 5, 7, 11, 13, 17};
        int s = 0, is80_2 = 0;
        int m;
        for (int & i : p2i) {
            i = (i + E3) % 26;
            s += i;
        }
        m = ceil((double)s / 7);
        for (int & i : p2i) {
            i = (i + s + m) % 26 + 65;

        }
        for(int i = 0; i<7; i++){
            if (p2i[i] == 80){
                k2 = i + 1;
                is80_2+=1;
                break;
            }
        }
        //check whether it reaches 80 or not
        if(is80_2 == 1){
            check2 = true;
            HP1 = HP1 - 80 * k2 * 2;
            EXP1 = EXP1 + (1000 - 80 * k2) % 101;
            M1 = ceil((double)M1 - (double)k2 * E3 / 9);
        }
        else{
            check2 = false;
            M1 = ceil((double)M1-(double)pow(7,2)/9);
        }



        //Third road
        int p3i[1000];
        int is80_3 = 0;
        for (int i = 2; i <= 40; i += 2) {
            p3i[i / 2] = pow(i, 2);
            p3i[i / 2] = (int) (p3i[i / 2] + E3 * E3) % 113;
        }
        //find max
        int max = p3i[1];
        for(int i = 1; i <= 20; i++ ){
            if(p3i[i] > max){
                max = p3i[i];
            }
        }
        for (int i = 1; i <= 20; i++) {
            p3i[i] = ((p3i[i] + E3) / max) % 26 + 65;
        }
        //he starts looking from end to start
        for(int i = 20; i >= 1; i--){
            if (p3i[i] == 80) {
                k3 = 20 - i + 1;
                is80_3+=1;
                HP1 = HP1 - 80 * k3 * 3;
                EXP1 = EXP1 + (3500 - 80 * k3) % 300;
                M1 = ceil((double)M1 - (double)k3 * E3 / 9);
                break;
            }
        }
        if(is80_3 == 1){
            check3 = true;

        }
        else{
            check3 = false;
            M1 = ceil((double)M1 - (double)400 * E3 / 9);
        }
        //Fourth road
        int p4i[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
        int is80_4 = 0;
        for (int i = 0; i<12; i++) {
            p4i[i] = (p4i[i]+(int)pow(ceil((double)E3 / 29), 3)) % 9;
        }
        int min = p4i[0];
        int min_idx=0;
        for (int i = 0; i < 12; i++) {
            if (p4i[i] < min) {
                min = p4i[i];
                min_idx = i + 1;
            }
            
        }
        //he starts looking from the end to start
        for(int i = 11; i >= 0; i--){
            p4i[i]=(int)((p4i[i]+E3)*(ceil((double)min/(double)min_idx  )))%26+65;
            if (p4i[i] == 80) {
                k4 = 11 - i + 1;
                is80_4+=1;
                break;
            }
        }
        if(is80_4 == 1){
            check4 = true;
            HP1 = HP1 - 80 * k4 * 4;
            EXP1 = EXP1 + (4500 - 80 * k4) % 400;
            M1 = ceil((double)M1 - (double)k4 * E3 / 9);
        }
        else{
            check4 = false;
            M1 = ceil((double)M1 - (double)pow(12, 2) * E3 / 9);
        }
        //guarantee the value of HP1,EXP1,M1
        if (HP1 < 0) {
            HP1 = 0;
        } else {
            if (HP1 > 999) {
                HP1 = 999;
            }
        }
        if (EXP1 < 0) {
            EXP1 = 0;
        } else {
            if (EXP1 > 900) {
                EXP1 = 900;
            }
        }
        if (M1 < 0) {
            M1 = 0;
        } else {
            if (M1 > 2000) {
                M1 = 2000;
            }
        }


        //check if he finds all the luggage or not
        if(check1 ||check2||check3||check4 ){
            return EXP1+HP1+M1;
        }
        else{
            HP1 = ceil(HP1 - (double)(59 * E3 % 900));
            EXP1 = ceil(EXP1 -(double)(79 * E3 % 300));
            M1 = ceil(M1 - (double)(pow(48, 2) / 9));
            //guarantee the value again
            if (HP1 < 0) {
                HP1 = 0;
            } else {
                if (HP1 > 999) {
                    HP1 = 999;
                }
            }
            if (EXP1 < 0) {
                EXP1 = 0;
            } else {
                if (EXP1 > 900) {
                    EXP1 = 900;
                }
            }
            if (M1 < 0) {
                M1 = 0;
            } else {
                if (M1 > 2000) {
                    M1 = 2000;
                }
            }
            return -1;
        }
    }
    else{
        return -999;
    }
}
   




////////////////////////////////////////////////
///END OF STUDENT'S ANSWER
////////////////////////////////////////////////
#endif /* studyInPink_h */
