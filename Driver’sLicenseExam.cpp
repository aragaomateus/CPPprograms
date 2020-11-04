
//  main.cpp
//  Driver’sLicenseExam
//  Created by Mateus Silva Aragao on 03/11/20.
/*The local Driver’s License Office has asked you to write a program that grades the writ- ten portion of the driver’s license exam. The exam has 20 multiple choice questions. Here are the correct answers:
 1. A 6. B 2.D 7.A 3. B 8. B 4.B 9.C 5.C 10.D
 11. A 12. C 13. D 14. B 15. D
 16. C 17. C 18. A 19. D 20. B
 Your program should store the correct answers shown above in an array. It should ask the user to enter the student’s answers for each of the 20 questions, and the answers should be stored in another array. After the student’s answers have been entered, the program should display a message indicating whether the student passed or failed the exam. (A student must correctly answer 15 of the 20 questions to pass the exam.) It should then display the total number of correctly answered questions, the total number of incorrectly answered questions, and a list showing the question numbers of the incorrectly answered questions.
 Input Validation: Only accept the letters A, B, C, or D as answers. */

//PROFESSOR: ADBBCBABCDACDBDCCADB
//ALUNO: ADCBABABCDACDADCCADB
#include <iostream>
using namespace std;

char passAnswerArray(char array[], int size);
char getstudentAnswer(char array[], int size);
void answersComparing(char array1[],char array2[],int size);

int main() {
    int size = 20;
    char profAnswer[size];
    char studentAnswer[size];
    
    passAnswerArray(profAnswer,size);
    
    getstudentAnswer(studentAnswer,size);
    
    answersComparing(profAnswer,studentAnswer,size);
    
    for (int i = 0; i < size; i++){
        if (studentAnswer[i] != profAnswer[i])
            cout << "Question " << i+1 << " is incorrect." << endl;
    }
    
    return 0;
}

// Fuction for passing the correct answersheet from professor.
char passAnswerArray(char array[], int size){
    for (int i = 0; i < size; i++){
        cout << "Professor Answer:" << endl;
        cout << "Enter answer " << i+1 << " : " << endl;
        cin >> array[i];
        if (array[i] != 'A' && array[i] !='B'&& array[i] !='C'&& array[i] !='D'){
            i=i-1;
            cout << "Invalid option" << endl;
        }
    }
    cout << endl;
    return array[size];
}

// Function for getting the answers from student.
char getstudentAnswer(char array[], int size){
    cout << "Student Answer:" << endl;
    for (int i = 0; i < size; i++){
        cout << "Enter answer " << i+1 << " : " << endl;
        cin >> array[i];
        if (array[i] != 'A' && array[i] !='B'&& array[i] !='C'&& array[i] !='D'){
            i=i-1;
            cout << "Invalid option" << endl;
        }
    }
    cout << endl;
    return array[size];
}

// Function for printing if the student failed or passed,the number of incorrect and correct questions.
void answersComparing(char array1[],char array2[],int size){
    int count1 =0,count2 = 0;
    for (int i = 0; i < size; i++){
        if(array2[i] == array1[i]){
            cout << "Student Answer " << i+1 << " is correct." << endl;
            count1++;
        }else{
            cout << "Student Answer " << i+1 << " is incorrect." << endl;
            count2++;
        }
    }
    if (count1 < 15 )
        cout << "Failed " << endl;
    else
        cout << "Passed" << endl;
    cout << endl;
    cout << count1 << " correct questions" << endl;
    cout << count2 << " incorrect questions" << endl;
    cout << endl;
}
