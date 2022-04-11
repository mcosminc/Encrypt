#include<iostream>  //include library and add std
#include<fstream>
#include<stdio.h>
using namespace std;

int main() {
    char file[30], ch;  //create a char file and i think ch is equal to the letters.
    fstream fps, fpt;   //create 2 fstream files
    cout<< "Enter filename";    //write 
    gets(file);                 //user input data that goes into file
    fps.open(file, fstream::in);    //open file(char) with fps(fstream), fstream recieving input data

    if(!fps) {      //if there is no fps = error
        cout << "Error \n";
        return 0;
    }

    fpt.open("file.txt", fstream::out); //create a file called file.txt and write it's data
    if(!fpt) {  //if there is no fpt = error
        cout << "Error\n";
        return 0;
    }

    while (fps >> ch) {     //while fps data goes to ch
        ch = ch * 120 - 12; //ch becomes equal to ch * 120 - 12
        fpt << ch;  //fpt recieves ch data
    }

    fps.close();    //close fps 
    fpt.close();    //close fpt
    fps.open(file, fstream::out);   //open fps file, and recieves it's data
    if(!fps) {  //if there is no fpt = error
        cout << "Error\n";
        return 0;
    }

    fpt.open("file.txt", fstream::in);  //fpt opens file.txt and input data into it
    if(!fpt){   //if there is no fpt = error
        cout << "Error";
    }

    while (fpt >> ch) //while fpt data goes to ch
        fps << ch; //fps recieves ch data
        fpt.close();    //fpt closes
        fps.close();    //fps closes
        cout << "File encrypted";
        return 0;  //close
}