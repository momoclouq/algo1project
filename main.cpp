//
//  main.cpp
//  practical7
//
//  Created by cis2mye on 12/17/19.
//  Copyright © 2019 cis2mye. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;

string practical2 (int value, string numbers[], int number_used); // p2
void delete_repeats (char Arr[], int size); //p3
void practical4 (string name[][2],double score[][3], ifstream& input, int number_used); //p4
void practical5 (int arr[][2], istream& input, int number_used); //p5
void practical6 (int arr[], int number_used); //p6
bool practical7 (char number1[], char number2[], int number3[], int length); //p7
bool moveValid (int move, int used[]); //p10
void showBoard(int board [][3], int used[], int initial); //p10
bool winnable (int used[], bool isfirst); //p10
void practical10(); //p10
void showseat (char seats[][5], int numseat, bool occupied[][5]); //p11
bool choiceValid(char choice, int row, bool occupied[][5], int numseat); //p11
void practical11(); //p11
bool turntoLive(char value, char game[][80], int row, int i, int k); //p13
bool turntoDead(char value, char game[][80], int row, int i, int k); //p13
void showGame (char game[][80], int row); //p13
void generation (char game[][80], int row); //p13
void practical13(); //p13
void practical14(ifstream& file, int number); //p14
int getnumberofvalue (ifstream& file); //p14
void practical16(); //p16
void practical19(); //p19

int main(int argc, const char * argv[]) {
    /*
    //practical 2
    int value;
    string numbers[28] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen", "twenty", "thirty", "fourty", "fifty","sixty","seventy","eighty","ninety"};
    cout << "practical 2: Please enter your number(0-99): ";
    cin >> value;
    while (value > 99 || value < 0){
        cout << "Wrong, exceed limit!, again: ";
        cin >> value;
    }
    cout << "Answer: " << practical2(value, numbers, 28) << endl;
    
    //practical 3
    char a[10];
    a[0] = 'a';
    a[1] = 'b';
    a[2] = 'c';
    a[3] = 'a';
    a[4] = 'd';
    a[5] = 'd';
    
    int size = 6;
    delete_repeats(a, size);
    
    //practical 4
    int numberstu = 4;
    string name[numberstu][2];
    double score[numberstu][3];
    ifstream input;
    input.open("p4i.txt");
    if (input.fail()) {
        cout << "Cannot open file!" << endl;
        exit(1);
    }
    practical4(name,score,input,numberstu);
    input.close();
    //display average
    for (int i = 0; i < numberstu; i++){
        cout.setf(ios::fixed);
        cout.setf(ios::showpoint);
        cout.precision(2);
        cout << name[i][0] <<" " << name[i][1] << " has average of: " << score[i][2] << endl;
    }
    
    //practical 5
    char filename[20];
    int choice = 0;
    cout << "Practical 5: Please enter your desired method of input (keyboard: 1) or (file : 2): ";
    cin >> choice;
    while (choice != 1 && choice != 2){
        cout << "wrong method of input, please try again: ";
        cin >> choice;
    }
    
    int lengtharr5 = 50;
    int arr[lengtharr5][2];
    if (choice == 1) practical5(arr, cin, lengtharr5);
    if (choice == 2) {
        cout << "Please enter the filename: ";
        cin >> filename;
        input.open(filename);
        if (input.fail()){
            cout << "Cannot open file!" <<endl;
            exit(1);
        } else practical5(arr, input, lengtharr5);
    }
    
    //practical 6
    int length6 = 10;
    int arr6[10] = {1,2,1,2,1,2,1,2,1,2};
    practical6(arr6, length6);

    
    //practical 7
    cout << "Practical 7." <<endl;
    
    char number1[20];
    char number2[20];
    char value;
    int count = 0;
    
    cout << "Addition of large integer, please remember that integers below 20 digit (<=20) are allowed."<<endl;
    
    //set all element in the array to be 'a'
    for (int i = 0; i < 20; i++){
        number1[i] = 'a';
        number2[i] = 'a';
    }
    
    //input first number
    cout << "The first number: ";
    
    while (true){
        cin.get(value);
        if (value == '\n' || count == 21) break;
        if (!isdigit(value)){
            cout << "number contains letter!" << endl;
                   count = 20;
                   break;
               }

        number1[count] = value;
        count++;
    }
    
    cin.clear();
    cin.ignore(INT_MAX, '\n');
    
    while (count == 21){
        for (int i = 0; i < 20; i++){
            number1[i] = 'a';
        }
        
        cout << "please re-enter number 1:";
        count = 0;
        while (true){
            cin.get(value);
            if (value == '\n'|| count == 21) break;
            if (!isdigit(value)){
                cout << "number contains letter!" << endl;
                       count = 21;
                       break;
                   }
            number1[count] = value;
            count++;
        }
        cin.clear();
        cin.ignore(INT_MAX, '\n');
    }
    
    cout << "number1: ";
    for (int i = 0; i < 20; i++) {
        cout << number1[i] << " ";
    }
    cout << endl;
    
    //input second number
    count = 0;
    cout << "The second number: ";
    
    while (true){
        cin.get(value);
        if (value == '\n' || count == 21) break;
        if (!isdigit(value)){
            cout << "number contains letter!" << endl;
                   count = 21;
                   break;
               }
        number2[count] = value;
        count++;
    }
    
    cin.clear();
    cin.ignore(INT_MAX, '\n');
    
    while (count == 21){
        for (int i = 0; i < 20; i++){
            number2[i] = 'a';
        }
        
        cout << "please re-enter number 2:";
        count = 0;
        while (true){
            cin.get(value);
            if (value == '\n'|| count == 21) break;
            if (!isdigit(value)){
                cout << "number contains letter!" << endl;;
                       count = 21;
                       break;
            }
            number2[count] = value;
            count++;
        }
       cin.clear();
       cin.ignore(INT_MAX, '\n');
    }
    
    cout << "number2: ";
    for (int i = 0; i < 20; i++) {
        cout << number2[i] << " ";
    }
    cout << endl;
    
    //algorithm
    int number3[20];
    practical7(number1, number2, number3, 20);
    
    //display
    bool still0 = true;
    cout << "answer: ";
    if (practical7(number1, number2, number3, 20)) cout << "Array overflow for large integers!." << endl;
    else
    for (int i = 0; i<20; i++){
        if (number3[i] != 0) still0 = false;
        if (!still0) cout <<number3[i];
    }
    cout << endl;
    
    //repeat: if we use function then yes, but no
    
    
    //practical 8
    cout << "Practical 8." << endl;
    
    int choice;
    int vote;
    char cont;
    string president[4] = {"Charles","Tom","Anne","christine"};
    int prevote[4] = {0,0,0,0};
    string vicepresident[3] = {"Higgins","Jerry","James"};
    int vicevote[3] = {0,0,0};
    
    do {
        cout << "Please enter the position you wish to vote for(1: president, 2: vive president): ";
        
        cin >> choice;
        while ((choice < 1) || (choice > 2)){
            cout << "Choice is invalid, please reenter: ";
            cin >> choice;
        }
        //vote for president
        if (choice == 1){
            for (int i = 0; i < 4; i++){
                cout <<i + 1 <<". "<< president[i] <<endl;
            }
            cout << "Vote for (use numbers): ";
            cin >> vote;
            while (vote < 1 || vote > 4){
                       cout << "vote is invalid, please reenter: ";
                       cin >> vote;
                   }
            prevote[vote - 1]++;
            vote = 0;
        }
        //vote for vicepresident
        if (choice == 2){
            for (int i = 0; i < 3; i++){
                           cout <<i + 1 <<". "<< vicepresident[i] <<endl;
                       }
                       cout << "Vote for (use numbers): ";
                       cin >> vote;
                       while (vote < 1 || vote > 3){
                                  cout << "vote is invalid, please reenter: ";
                                  cin >> vote;
                              }
                       vicevote[vote - 1]++;
        }
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        
        cout << "Continue? (Y/N): ";
        cin.get(cont);
    } while (cont == 'Y' || cont == 'y');
    //display the vote
    cout << setw(10) << "Name" << setw(10) << "Position" << setw(20) << "Number of votes" << endl;
    for (int i = 0; i < 4; i++){
        cout << setw(10) << president[i] <<setw(10) << "President" << setw(10) << prevote[i] << endl;
    }
    for (int i = 0; i < 3; i++){
        cout << setw(10) << vicepresident[i] <<setw(10) << " vice pres" << setw(10) << vicevote[i] << endl;
    }
    
    //practical 9
    string order[10][10];
    int meal[6] = {0,0,0,0,0,0};
    string mealtext[6] = {"shrimp" ,"lobster", "crab", "advocado", "james","pork"};
    char cont;
    int table;
    int mealscount;
    
    //algorithm
    do {
        //input asking for table
        do {
            cout << "Please enter the table: ";
            cin >> table;
        } while (table < 1 || table > 10);
    
        //menu
        mealscount = 0;
        int ordernumber = 11;
        cout << "To stop the order, press 11 \n";
        cout << "Here are the items: " << endl;
        cout << "1. shrimp" << endl << "2. lobster" << endl << "3. crab" << endl << "4. advocado" << endl << "5. james" <<endl << "6. pork" <<endl;
        do {
            cout << "Order (in number) : ";
            cin >> ordernumber;
            switch (ordernumber){
                case 1: order[table-1][mealscount] = "shrimp";
                        meal[ordernumber-1]++;
                        break;
                case 2: order[table-1][mealscount] = "lobster";
                        meal[ordernumber-1]++;
                        break;
                case 3: order[table-1][mealscount] = "crab";
                        meal[ordernumber-1]++;
                        break;
                case 4: order[table-1][mealscount] = "advocado";
                        meal[ordernumber-1]++;
                        break;
                case 5: order[table-1][mealscount] = "james";
                        meal[ordernumber-1]++;
                        break;
                case 6: order[table-1][mealscount] = "pork";
                        meal[ordernumber-1]++;
                        break;
                case 11: break;
                default: cout << "Unknown meal!" << endl;
                    break;
            }
            mealscount++;
            cin.clear();
            cin.ignore(INT_MAX, '\n');
            if (ordernumber == 11) break;
            if (mealscount >= 10) break;
        
        } while (true);
            cin.clear();
            cin.ignore(INT_MAX, '\n');
            cout << "Another table? (Y/N): ";
            cin.get(cont);
    } while ((cont == 'y') || (cont == 'Y'));
    
    //output
    for (int i = 0; i < 6; i++){
        cout << mealtext[i] << ": " << meal[i] << " order!"<< endl;
    }
    */
    // practical 10
    //practical10();
    
    //practical 11
    //practical11();
    
    //practical 13
    //practical13();
    
    //practical 14
    /*ifstream file;
    int number14;
    file.open("p14i.txt");
    if (file.fail()) {
        cout << "Cant not open file" <<endl;
        exit(1);
    }
    
    number14 = getnumberofvalue(file) - 1;
    cout << "number = " << number14 <<endl;
    
    file.close();
    file.open("p14i.txt");
    if (file.fail()) {
        cout << "Cant not open file" <<endl;
        exit(1);
    }
    
    practical14(file, number14);
    
    file.close();
     */
    //practical 16
    //practical16();
    
    //practical 19
    practical19();
    return 0;
}

string practical2 (int value, string numbers[], int number_used){
    int donvin = value % 10;
    int chucn = value / 10;
    
    string donvi, chuc, total;
    
    if (number_used >  28) return "Error, array overflow!";
    switch (value){
        case 0: return numbers[0]; break;
            case 1: return numbers[1]; break;
            case 2: return numbers[2]; break;
            case 3: return numbers[3]; break;
            case 4: return numbers[4]; break;
            case 5: return numbers[5]; break;
            case 6: return numbers[6]; break;
            case 7: return numbers[7]; break;
            case 8: return numbers[8]; break;
            case 9: return numbers[9]; break;
            case 10: return numbers[10]; break;
        case 11: return numbers[11]; break;
            case 12: return numbers[12]; break;
            case 13: return numbers[13]; break;
            case 14: return numbers[14]; break;
        case 15: return numbers[15]; break;
            case 16: return numbers[16]; break;
            case 17: return numbers[17]; break;
            case 18: return numbers[18]; break;
            case 19: return numbers[19]; break;
        default: break;
    }
    
    switch (donvin)
    {
        case 1: donvi = numbers[1]; break;
        case 2: donvi = numbers[2]; break;
        case 3: donvi = numbers[3]; break;
        case 4: donvi = numbers[4]; break;
        case 5: donvi = numbers[5]; break;
        case 6: donvi = numbers[6]; break;
        case 7: donvi = numbers[7]; break;
        case 8: donvi = numbers[8]; break;
        case 9: donvi = numbers[9]; break;
        default: donvi = ""; break;
    }
    
    switch (chucn)
    {
            case 2: chuc = numbers[20]; break;
            case 3: chuc = numbers[21]; break;
            case 4: chuc = numbers[22]; break;
            case 5: chuc = numbers[23]; break;
            case 6: chuc = numbers[24]; break;
            case 7: chuc = numbers[25]; break;
            case 8: chuc = numbers[26]; break;
            case 9: chuc = numbers[27]; break;
            default: chuc = ""; break;
    }
    total = chuc + "-" + donvi;
    return total;
}

void delete_repeats (char Arr[], int size) //practical 3
{
    char Arr2[size];
    bool found = false;
    int counter = 0;
    
    if (size > 10) {
        cout << " Wrong size!" << endl;
        exit(1);
    } else{
        for (int i = 0; i < size; i++){
            for (int j = 0; j < counter; j++){
                if (Arr[i] == Arr2[j]) {
                    found = true;
                    break;
                }
            }
            if (found == false){
                Arr2[counter] = Arr[i];
                counter++;
            }
            found = false;
        }
    }
    
    Arr = Arr2;
    for (int i = 0; i < counter; i++){
        cout << i+1 <<":" <<Arr[i] <<" ";
    }
    cout << endl;
}

void practical4 (string name[][2],double score[][3], ifstream& input, int number_used){
    string names;
    double grade;
    int count = 0;
    
    if (number_used > 50) {
        cout << "the number of student exceeds the limit!" << endl;
        exit(1);
    }
    
    while (input >> names){
        if (count <= number_used-1){
            name[count][0] = names;
            input >> names;
            name[count][1] = names;
            input >> grade;
            score[count][0] = grade;
            input >> grade;
            score[count][1] = grade;
            //average score
            score[count][2] = (score[count][0]+score[count][1]) / 2;
            count++;
        }
    }
}

void practical5 (int arr[][2], istream& input, int number_used){
    int value;
    int count = 0;
    char checker;
    bool found = false;
    
    if (number_used > 50){
        cout << "the total values exceed the limit (50)"<<endl;
        exit(1);
    }
    
    while (input >> value){
        for (int i = 0; i < count; i++){
            if (value == arr[i][0]) {
                found = true;
                arr[i][1]++;
                break;
            }
        }
        if (found == false){
            arr[count][0] = value;
            arr[count][1] = 1;
            count++;
        }
        found = false;
        
        if (&input == &cin){ //check if input is cin
            cin.get(checker);
            if (checker == '\n') break;
        }
    }
    
    //sort algorithm bubble
    for (int i = count-1; i > 0; i--)
    for (int j = 0; j <i; j++)
        if (arr[j][0] < arr[j+1][0])
        {
            int temp1 = arr[j+1][0];
            int temp2 = arr[j+1][1];
            arr[j+1][0] = arr[j][0];
            arr[j+1][1] = arr[j][1];
            arr[j][0] = temp1;
            arr[j][1] = temp2;
        }
    
    //output
    cout.setf(ios::left);
    cout <<setw(4)<< "N"<< setw(5) <<"Count"<< endl;
    for (int i = 0; i < count; i++){
        cout << setw(4) << arr[i][0] << setw(5) << arr[i][1] << endl;
    }
}

void practical6 (int arrNot[], int number_used){
    if (number_used > 10) {
        cout << "Array exceeds requirements" <<endl;
        exit(1);
    }
    else {
        int arrDone[number_used];
        int count = 1;
        bool sorted = false;
        
        for (int i = 0; i < number_used; i++){
            cout << "++" << endl;
            if (i == 0) arrDone[0] = arrNot[0];
            else {
                for (int z = 0; z < count; z++){
                    if (arrNot[i] <= arrDone[z]){
                        sorted = true;
                        for (int k = number_used-1; k >= (z+1) ; k--){
                            arrDone[k] = arrDone[k-1];
                        }
                        arrDone[z] = arrNot[i];
                        break;
                    }
                }
                if (!sorted) arrNot[count-1] =  arrDone[i];
                sorted = false;
            }
            count++;
        }
        
        //output
        for (int i = 0; i < number_used; i++){
            cout << arrDone[i] <<" ";
        }
    }
}

bool practical7 (char number1[], char number2[], int number3[], int length){
    if (length > 20) {
        cout << "Error, array overflow" << endl;
        exit(1);
    }
    
    int shift1 = 0;
    int shift2 = 0;
    
    int checker = 0;
    for (int i = 0; i < length; i++){
        if (number1[i] == 'a') shift1++;
        if (number2[i] == 'a') shift2++;
    }
    
    for (int i = length-1; i >= 0; i--){
        int num1 = 0;
        int num2 = 0;
        if (i-shift1 >=0 )
            if (number1[i-shift1] != 'a') num1 = number1[i] - '0';
        if (i-shift2 >= 0)
            if (number2[i-shift2] != 'a') num2 = number2[i] - '0';
        
        if (num1 + num2 + checker < 10) {
            number3[i] = num1 + num2 + checker;
            checker = 0;
        }
        else {
            number3[i] = num1 + num2 + checker - 10;
            checker = 1;
        }
    }
    
    if (checker == 1) return true;
    else return false;
}

void showBoard(int board [][3], int used[], int initial){
    if(initial > 3){
        cout << "error in the first element of board, please re-check" <<endl;
        exit(1);
    }
    else {
        for (int i = 0; i < initial; i++){
            for (int k = 0; k < initial; k++){
                //check if the element is used or not
                if (used[board[i][k] - 1] == 0) cout << board[i][k];
                else if (used[board[i][k] - 1] == 1) cout << 'X';
                else cout << 'O';
                cout << " ";
                //endline at the end of each 3 elements
                if (k == (initial - 1)) cout << endl;
            }
        }
    }
}

bool moveValid (int move, int used[]){
    if (move > 9 || move < 1) return false;
    if (used[move-1] != 0) return false;
    return true;
}

bool winnable (int used[], bool isfirst){
    int value;
    
    if (isfirst) value = 1;
    else value = 2;
    
    if (used[0] == used[3] && used[3] == used[6] && used[6] == value) return true;
    if (used[0] == used[4] && used[4] == used[8] && used[8] == value) return true;
    if (used[0] == used[1] && used[1] == used[2] && used[2] == value) return true;
    if (used[1] == used[4] && used[4] == used[7] && used[7] == value) return true;
    if (used[2] == used[5] && used[5] == used[8] && used[8] == value) return true;
    if (used[2] == used[4] && used[4] == used[6] && used[6] == value) return true;
    if (used[6] == used[7] && used[7] == used[8] && used[8] == value) return true;
    if (used[3] == used[4] && used[4] == used[5] && used[5] == value) return true;
    return false;
}
    
void practical10(){
    int board [3][3] = {{1,2,3}, {4,5,6}, {7,8,9}};
    int used[9];
    bool isfirst = true;
    int move;
    
    for ( int i = 0; i < 9; i++){
        used[i] = 0;
    }
    
    //show the board
    showBoard(board, used, 3);
    
    cout << "First player will be X and second player will be O." <<endl;
    while(true){
        if (isfirst) {
            cout << "first player move: ";
            cin >> move;
            while (cin.fail() || !moveValid(move, used)){
                cout << "move is invalid, please reenter: ";
                cin >> move;
            }
        }
        else
        {
           cout << "second player move: ";
            cin >> move;
            while (cin.fail() || !moveValid(move, used)){
                cout << "move is invalid, please reenter: ";
                cin >> move;
            }
        }
            if (isfirst) {
                used[move - 1] = 1;
            }
            else {
                used[move - 1] = 2;
            }
            
            //show board after move
            showBoard(board, used, 3);
            
            if (winnable(used, isfirst)){
                if (isfirst){
                    cout << "First player has won!" <<endl;
                    break;
                }
                else {
                    cout <<"Second player has won!" <<endl;
                    break;
                }
            }
        
            isfirst = !isfirst;
    }
}

void showseat (char seats[][5], int numseat, bool occupied[][5]){
    if (numseat < 0 || numseat > 50) {
        cout << "Problem with number of seats, please re-check!" <<endl;
        exit(1);
    }
    else
    {
        for (int i = 0; i < numseat; i++){
            for (int k = 0; k < 5; k++){
                if (!occupied[i][k]){
                    cout << seats[i][k] << " ";
                }
                else cout << 'X' << " ";
                if (k == 4) cout << endl;
            }
        }
    }
}

bool choiceValid(char choice, int row, bool occupied[][5], int numseat){
    int choicenum;
    switch(choice){
        case 'A': choicenum = 1; break;
        case 'B': choicenum = 2; break;
        case 'C': choicenum = 3; break;
        case 'D': choicenum = 4; break;
        default: return false;
    }
    if (occupied[row-1][choicenum]) {
        return false;
    }
    occupied[row-1][choicenum] = true;
    return true;
}
    
void practical11(){
    int numseat;
    char choice;
    int row;
    //get the number of seats
    do{
        cout << "Please enter the number of seats: ";
        cin >> numseat;
    } while (cin.fail() || numseat < 0 || numseat > 50);
    
    char seats [numseat][5];
    bool occupied [numseat][5];
    
    
    //fill the seats && occupation
    for (int i = 0; i < numseat; i++){
        for (int k = 0; k < 5; k++){
            if (k == 0) seats[i][k] = '0' + (i + 1);
            if (k == 1) seats[i][k] = 'A';
            if (k == 2) seats[i][k] = 'B';
            if (k == 3) seats[i][k] = 'C';
            if (k == 4) seats[i][k] = 'D';
            occupied[i][k] = false;
        }
    }
    
    //show first available seats
    showseat(seats, numseat, occupied);
    
    while (true){
        cout << "Please enter your desired row (number): ";
        cin >> row;
        while (cin.fail() || row < 0 || row > numseat){
            cout << "row is not valid, please retry: ";
            cin >> row;
        }
        
        cout << "Please enter your desired seat (A,B,C,D): ";
        cin >> choice;
        
        while (cin.fail() || !choiceValid(choice, row , occupied, numseat)){
            cout << "choice is not valid, please reenter: ";
            cin >> choice;
        }
        
        showseat(seats, numseat, occupied);
        
        char continuec;
        cout << "continue? (Y/N)";
        cin >> continuec;
        if (continuec == 'n' || continuec == 'N') break;
    }
}

void showGame (char game[][80], int row){
    if (row < 0 || row > 22){
        cout << "Problem with row, please check again!" << endl;
        exit(1);
    }
    else {
        for (int i = 0; i < row; i++){
            for (int k = 0; k < 80; k++){
                cout << game[i][k];
                if (k == 79) cout << endl;
            }
        }
    }
}

bool turntoLive(char value, char game[][80], int row, int i, int k){
    if (value == '*') return false;
    
    int neighborcount = 0;
    
    if (i-1 > 0 && k-1 > 0) if(game[i-1][k-1] == '*') neighborcount++;
    if (i-1 > 0) if(game[i-1][k] == '*') neighborcount++;
    if (i-1 > 0 && k+1 < 80) if(game[i-1][k+1] == '*') neighborcount++;
    if (k-1 > 0) if(game[i][k-1] == '*') neighborcount++;
    if (k+1 < 80) if(game[i][k+1] == '*') neighborcount++;
    if (i+1 < row && k-1 > 0) if(game[i+1][k-1] == '*') neighborcount++;
    if (i+1 < row) if(game[i+1][k] == '*') neighborcount++;
    if (i+1 < row && k+1 < 80) if(game[i+1][k+1] == '*') neighborcount++;
    
    if (neighborcount == 3) return true;
    return false;
}

bool turntoDead(char value, char game[][80], int row, int i, int k){
    if (value == '-') return false;
    
    int neighborcount = 0;
    
    if (i-1 > 0 && k-1 > 0) if(game[i-1][k-1] == '*') neighborcount++;
    if (i-1 > 0) if(game[i-1][k] == '*') neighborcount++;
    if (i-1 > 0 && k+1 < 80) if(game[i-1][k+1] == '*') neighborcount++;
    if (k-1 > 0) if(game[i][k-1] == '*') neighborcount++;
    if (k+1 < 80) if(game[i][k+1] == '*') neighborcount++;
    if (i+1 < row && k-1 > 0) if(game[i+1][k-1] == '*') neighborcount++;
    if (i+1 < row) if(game[i+1][k] == '*') neighborcount++;
    if (i+1 < row && k+1 < 80) if(game[i+1][k+1] == '*') neighborcount++;
    
    if (neighborcount > 3) return true;
    if (neighborcount < 2) return true;
    return false;
}

void generation (char game[][80], int row){
    char newgame [row][80];
    char continuec;
    
    for (int i = 0; i < row; i++){
        for (int k = 0; k < 80; k++){
            newgame[i][k] = game[i][k];
            if (turntoLive(game[i][k], game, row, i , k)) newgame[i][k] = '*';
            else if(turntoDead(game[i][k], game, row, i, k)) newgame[i][k] = '-';
        }
    }
    
    showGame(newgame, row);
    
    cout << "continue? (Y/N)";
    cin >> continuec;
    
    if (continuec == 'Y' ||continuec == 'y') {
        cout << string(50, '\n');
        generation(newgame, row);
    }
    else cout <<"end" <<endl;
}
    
void practical13(){
    char game [22][80];
    
    //create game
    for (int i = 0;i < 22; i++){
        for (int k = 0; k < 80; k++){
            game[i][k] = '-';
        }
    }
    
    game[1][22] = '*';
    game[2][22] = '*';
    game[4][42] = '*';
    game[1][24] = '*';
    game[5][22] = '*';
    game[3][15] = '*';
        
    //showGame(game, 22);
    generation(game, 22);
}

int getnumberofvalue (ifstream& file){
    //get the total amount of names
       int number = 0;
       char value;
       
       while (true){
           file.get(value);
           if (value == '\n') number++;
           if (file.eof()) break;
       }
    return number;
}

void practical14(ifstream& file, int number){
    char boys [number][20];
    char girls [number][20];
    
    int index = 0;
    int counter = 0;
    char value;
    
    while (true){
        file.get(value);
        if (file.eof()) break;
        file.get(value);
        
        file.get(value);
        while (value != ' '){
            boys[index][counter] = value;
            file.get(value);
            counter++;
        }
        for (int i = counter; i < 20; i++){
            boys[index][counter] = '0';
        }
        
        counter = 0;
        file.get(value);
        while (value != '\n'){
            girls[index][counter] = value;
            file.get(value);
            counter++;
        }
        for (int i = counter; i < 20; i++){
            girls[index][counter] = '0';
        }
        
        counter = 0;
        index++;
    }
    
    cout << "Index = " <<index <<endl;
    
    string searchvalue;
    
    bool foundboy = false;
    int positionboy = 0;
    int positiongirl = 0;
    bool foundgirl = false;
    cout << "Who do you wanna search for?";
    cin >> searchvalue;
    cout << searchvalue <<endl;
    
    for (int i = 0; i < number; i++){
        for (int k =0; k <20 ;k++){
            if (boys[number][k] == '0') break;
            if (searchvalue[k] != boys[number][k]) break;
            if (searchvalue[k] == boys[number][k]) if (k == 19) {
                foundboy = true;
                positionboy = k;
                break;
            }
            else
                if ((boys[number][k+1] == '0') && (searchvalue[k] == '0'))
            {
                foundboy = true;
                positionboy = number;
                break;
            }
        }
        
        for (int k =0; k <20 ;k++){
            if (girls[number][k] == '0') break;
            if (searchvalue[k] != girls[number][k]) break;
            if (searchvalue[k] == girls[number][k]) if (k == 19) {
                foundgirl = true;
                positiongirl = k;
                break;
            }
            else
                if ((girls[number][k+1] == '0') && (searchvalue[k] == '0')){
                    foundgirl = true;
                    positiongirl = k;
                    break;
                }
            }
        }
    
    if (foundboy) {
        cout << "Boy: " <<positionboy <<endl;
    } else cout << "We dont find any boys with that name!"<<endl;
    
    if (foundgirl) {
        cout << "girl: " <<positiongirl <<endl;
    } else cout << "We dont find any girls with that name!"<<endl;
}

void displayboard( int arrangement[][4], bool faceup [][4]){
    cout << setw(3) << ' ' <<setw(3) << ' ' << setw(3) << '1' << setw(3) << '2' <<setw(3) << '3' << setw(3) << '4' << endl;
    cout << setw(3) << ' ' <<setw(3) << ' ' << "------------" << endl;
    for (int i = 0; i < 4; i++){
        cout << setw(3) << i+1;
        cout << setw(3) << '|';
           for (int k = 0; k < 4; k++){
               if (faceup[i][k]) cout <<setw(3) << arrangement[i][k];
               else cout << setw(3) << '*';
               if (k == 3) cout << endl;
           }
       }
}

bool validchoice (int a, int b){
    if (a < 1 || a > 4) return false;
    if (b < 1 || b > 4) return false;
    return true;
}

bool isWon(bool board[][4]){
    for (int i = 0; i < 4; i++){
        for (int k = 0; k< 4; k++){
            if(board[i][k] == false) return false;
        }
    }
    return true;
}

void practical16(){
    int arrangement [4][4] = {{1,2,3,4},{5,6,7,8}, {1,2,3,4},{5,6,7,8}};
    bool faceup [4][4];
    
    for (int i = 0; i < 4; i++){
        for (int k = 0; k < 4; k++){
            faceup [i][k] = false;
        }
    }
    //mix the arrangement
    int randomness = 20;
    while (randomness > 0) {
        int value1a = rand() % 4;
        int value2a = rand() % 4;
        int value1b = rand() % 4;
        int value2b = rand() % 4;
        
        int intermediate;
        intermediate = arrangement[value1a][value1b];
        arrangement[value1a][value1b] = arrangement[value2a][value2b];
        arrangement[value2a][value2b] = intermediate;
        randomness--;
    }
   
    //testing
    for (int i = 0; i < 4; i++){
        for (int k = 0; k < 4; k++){
            faceup [i][k] = true;
        }
    }
    
    displayboard(arrangement, faceup);
    for (int i = 0; i < 4; i++){
        for (int k = 0; k < 4; k++){
            faceup [i][k] = false;
        }
    }
    //
    
    cout << endl;
    
    int choice1a;
    int choice1b;
    int choice2a;
    int choice2b;
    
    displayboard(arrangement, faceup);
    cout << endl;
    
    while (true){
        do {
            cout << "Please enter your first choice 'x y': ";
            cin >> choice1a >>choice1b;
        } while (!validchoice(choice1a,choice1b));
        
        do {
            cout << "Please enter your second choice 'x y': ";
            cin >> choice2a >>choice2b;
        } while (!validchoice(choice2a,choice2b));
        
        faceup[choice1a-1][choice1b-1] = true;
        faceup[choice2a-1][choice2b-1] = true;
        
        displayboard(arrangement, faceup);
        
        if (isWon(faceup)) {cout << "You have won the game!" <<endl; break;}
        if (arrangement[choice1a-1][choice1b-1] != arrangement[choice2a-1][choice2b-1]) {
            faceup[choice1a-1][choice1b-1] = false;
            faceup[choice2a-1][choice2b-1] = false;
        }
    }
}

bool checkpass(int pass, int pin[5], int randomsq[10]){
    int sum = 0;
    
    for (int i = 0; i<5; i++){
        sum  = sum + randomsq[pin[i]] * (pow(10,(4-i)));
    }
    cout <<"sum: "<< sum << endl;
    
    if (sum == pass) return true;
    else return false;
}

void practical19() {
    int pinint;
    int pin[5];
    
    do {
        cout << "Enter your pin: ";
        cin >> pinint;
    } while (pinint < 0 || pinint > 99999);
    
    for (int i = 4; i>= 0; i--){
        pin[i] = pinint % 10;
        pinint = pinint / 10;
    }

    for (int i = 0; i< 5; i++){
        cout << pin[i];
    }
    cout <<endl;
    
    bool continuex = true;
   do {
       int pass;
       
        srand((unsigned)time(NULL));
        int randomsq[10];
        for (int i = 0; i<10; i++){
            randomsq[i] = rand() % 3 + 1;
        }
        
        
        cout << "PIN: 0 1 2 3 4 5 6 7 8 9" <<endl;
        cout << "NUM: ";
        for (int i = 0; i<10; i++){
            cout << randomsq[i] << ' ';
        }
        cout << endl;
       
       cout << "Please enter your pass: ";
       cin >> pass;
       
       if (checkpass(pass, pin, randomsq)) continuex = false;
   } while (continuex);
}

