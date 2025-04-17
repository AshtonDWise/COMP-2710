/*
Ashton Wise
adw0082
project3_wise_adw0082.cpp
compiled using g++

Resources Used:
    http://www.cplusplus.com/reference/vector/vector/
    http://www.cplusplus.com/reference/vector/vector/push_back/
    https://www.educative.io/answers/how-to-iterate-through-a-vector-in-cpp
    Dr.Li Help code
    Dr.Li Lecture Slides
*/

#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

bool check_file(string);
vector<int> read_file(string);
void write_file(string, vector<int>);
vector<int> merge(vector<int>, vector<int>);


int main() {
    string file1, file2, file3;
    vector<int> numbers1, numbers2, numbers3;


    cout << "***Welcome to Ashton's sorting program.***" << endl;
    do {
        cout << "Enter the name of the first file: ";
        cin >> file1;
    } while (cin.fail() || !check_file(file1));
    numbers1 = read_file(file1);

    cout << "The list of " << numbers1.size() << " numbers in file " << file1 << " is:\n";
    for (int i = 0; i < numbers1.size(); i++) {
        cout << numbers1[i] << "\n";
    }
    cout << endl;

    do {
        cout << "Enter the name of the second file: ";
        cin >> file2;
    } while (cin.fail() || !check_file(file2));
    numbers2 = read_file(file2);
    numbers3 = merge(numbers1, numbers2);

    cout << "The list of " << numbers2.size() << " numbers in file " << file2 << " is:\n";
    for (int i = 0; i < numbers2.size(); i++) {
        cout << numbers2[i] << "\n";
    }
    cout << endl;

    cout << "The sorted list of " << numbers3.size() << " numbers is:";
    for (int i = 0; i < numbers3.size(); i++) {
        cout << numbers3[i] << ",";
    }
    cout << endl;


    do {
        cout << "Enter the name of the output file: ";
        cin >> file3;
    } while (cin.fail());
    write_file(file3, numbers3);

    cout << "***Please check the new file - " << file3 << "***" <<endl;
    cout << "***Goodbye.***" << endl;

    return 1;
}


//check if file exists

bool check_file(string file) {
    ifstream stream;
    stream.open(file.c_str());
    if (stream.fail()) {
        cout << "Error: File does not exist." << endl;
        return false;
    }
    stream.close();
    return true;
}

//read file into vector
vector<int> read_file(string file) {
    ifstream stream;
    vector<int> numbers;
    int number;
    stream.open(file.c_str());
    while (stream >> number) {
        numbers.push_back(number);
    }
    stream.close();
    return numbers;
}

//write vector to file
void write_file(string file, vector<int> numbers) {
    ofstream stream;
    stream.open(file.c_str());
    for (int i = 0; i < numbers.size(); i++) {
        stream << numbers[i] << endl;
    }
    stream.close();
}

//merge two sorted vectors
vector<int> merge(vector<int> numbers1, vector<int> numbers2) {
    vector<int> numbers3;
    int i = 0, j = 0;
    while (i < numbers1.size() && j < numbers2.size()) {
        if (numbers1[i] < numbers2[j]) {
            numbers3.push_back(numbers1[i]);
            i++;
        } else {
            numbers3.push_back(numbers2[j]);
            j++;
        }
    }
    while (i < numbers1.size()) {
        numbers3.push_back(numbers1[i]);
        i++;
    }
    while (j < numbers2.size()) {
        numbers3.push_back(numbers2[j]);
        j++;
    }
    return numbers3;
}
