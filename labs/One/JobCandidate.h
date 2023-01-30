//
// Created by Zachariah Magee on 1/26/23.
//

#pragma once

/**
 * Write a program that checks if a 'job candidate' meets the qualifications for the job.
 *
 * The job qualification is they have a bachelor or masters degree, speaks French and English,
 * and has more than 3 years of job experience but less than 10.
 *
 * The user will be prompted to enter answers to each question and then the program should output
 * whether or not the user is qualified for the job.
 *
 * Make a variable called degree that's is an enumeration type
 * AcademicDegree(possible values: none, associate, bachelor, master, doctor, professional).
 * Checks language with speaksFrench and speaksEnglish booleans.
 * If the user enters invalid values, they should immediately be disqualified
 * **/
void isQualified();
enum AcademicDegree {
    None = 0,
    Associate,
    Bachelor,
    Master,
    Doctor,
    Professional
};

AcademicDegree hasDegree(int input);