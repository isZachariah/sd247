//
// Created by Zachariah Magee on 1/26/23.
//

#include "iostream"
#include "JobCandidate.h"

using namespace std;

void isQualified() {
    bool isQualified, speaksFrench, speaksEnglish;
    int degreeInput, yearsExperience;
    cout << "What kind of degree do you have?"
            "    None         = 0,\n"
            "    Associate    = 1,\n"
            "    Bachelor     = 2,\n"
            "    Master       = 3,\n"
            "    Doctor       = 4,\n"
            "    Professional = 5\n"
            "Enter you degree: ";
    cin >> degreeInput;
    AcademicDegree degree = hasDegree(degreeInput);
    isQualified = degree == Bachelor || degree == Master;
    if(!isQualified){
        cout << "You are disqualified";
        return;
    }
    cout << "Do you speak French?\n"
            "     No   = 0\n"
            "     Yes  = 1\n"
            "Response: ";
    cin >> speaksFrench;
    if(!speaksFrench){
        cout << "You are disqualified";
        return;
    }
    cout << "Do you speak English?\n "
            "     No   = 0\n"
            "     Yes  = 1\n"
            "Response: ";
    cin >> speaksEnglish;
    if(!speaksEnglish){
        cout << "You are disqualified";
        return;
    }
    cout << "Number of years experience: ";
    cin  >> yearsExperience;
    isQualified = yearsExperience >= 3 && yearsExperience <= 10;
    if(!isQualified){
        cout << "You are disqualified";
        return;
    }
    cout << "You match all our qualifications!\n"
            "Let's schedule an in person interview"
            << endl;

}

AcademicDegree hasDegree(int input) {
    switch(input){
        case 0: return None;
        case 1: return Associate;
        case 2: return Bachelor;
        case 3: return Master;
        case 4: return Doctor;
        case 5: return Professional;
        default: return None;
    }
}