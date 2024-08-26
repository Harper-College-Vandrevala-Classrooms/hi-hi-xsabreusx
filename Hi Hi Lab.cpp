/*
Name: Humberto
Class: CSC122
Lab: Hi==hi? Lab
*/

//information on the function of strcmp() obtaine from https://cplusplus.com/reference/cstring/strcmp/
//inforamtion on the meaning of lexicographic order comparison obtained from: https://raytracing-docs.nvidia.com/mdl/api/mi_def_lexicographic_order.html#:~:text=If%20the%20first%20element%20of,is%20lexicographically%20greater%20than%20B%20.


#include <iostream>
using namespace std;
#include <string>
#include <cctype> //to allow use of tolower function

int strcmp_case_insensitive(const string&, const string&);

int main () 
{

string str1 = "Apple";      //defining strings that will be used for driver testing
string str2 = "apple";
string str3 = "Appl";
string str4 = "Apply";
string str5 = "";


cout << "\n\nComparison driver is now running... Compares lexicographic order of two strings.\n";  //information about the program

//below I test various edge cases to ensure the function is working properly
cout << "\nComparing " << str1 << " to " << str2 << " results in: " << strcmp_case_insensitive(str1,str2);  //testing case insensitivity
cout << "\nComparing " << str2 << " to " << str1 << " results in: " << strcmp_case_insensitive(str2,str1);  //testing case insensitivity in the opposite direction
cout << "\nComparing " << str1 << " to " << str3 << " results in: " << strcmp_case_insensitive(str1,str3);  //different length strings
cout << "\nComparing " << str1 << " to " << str4 << " results in: " << strcmp_case_insensitive(str1,str4);   //diffrent value strings
cout << "\nComparing " << str1 << " to " << str5 << " results in: " << strcmp_case_insensitive(str1,str2);    //non empty sting to an empty string

cout << "\n\nComparison driver finished running.\n\n"; //message indicating end of program

return 0;

}

int strcmp_case_insensitive(const string& s1, const string& s2)
{
size_t len = min(s1.length(), s2.length());  //getting the minimum length needed for comparison

for (size_t i = 0; i < len; ++i)  //here using for loop to compare the characters along the specific length obtained above
{
    char c1 = tolower(s1[i]);   //here we create two character variables which will be set equal to the specific character element of the string
    char c2 = tolower(s2[i]);
    if (c1 < c2)                 //here we determine order and return the appropriate value
    {
        return -1;
    }
    else if (c1 > c2)   
    {
        return 1;
    }
}
//if all characters compared so far are equal then I use length to determine order:
if (s1.length() < s2.length())
{
    return -1;
}
else if (s1.length() > s2.length())
{
    return 1;
}
else
{
    return 0;
}
//if the above finds no difference then  return 0

}