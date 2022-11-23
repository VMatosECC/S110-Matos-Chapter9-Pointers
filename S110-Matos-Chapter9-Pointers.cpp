// S110-Matos-Chapter9-Pointers.cpp 

#include <iostream>
#include <string>
using namespace std;

void experiment01();
void experiment02();
void experiment03();

void getUserData(string& first, string& last, string& email);
void getUserData2(string* pfirst, string* plast, string* pemail);
void showArray(int* pa, int* pn);
int* getArray(int* pn);
int findPosMax(int* pa, int* pn);
void bubbleSort(int* pa, int* pn);


int main()
{
    //experiment01();
    //experiment02();
    experiment03();
}
//-------------------------------------------------------------------------
void experiment03()
{
    int* pn = new int(0);
    int* pa = getArray(pn);

    showArray(pa, pn);
    int posMax = findPosMax(pa, pn);
    cout << "The largest value in the array is: " << *(pa + posMax) << endl;

    bubbleSort(pa, pn);
    showArray(pa, pn);
}
//--------------------------------------------------------------------------
void bubbleSort(int* pa, int* pn)
{
    for (int last = *pn - 1; last > 0; last--)
    {
        for (int i = 0; i < last; i++)
        {
            if (*(pa + i) > *(pa + i + 1)) 
            {
                int temp = *(pa + i);
                *(pa + i) = *(pa + i + 1);
                *(pa + i + 1) = temp;
            }
        }
    }
}
//--------------------------------------------------------------------------
int findPosMax(int* pa, int* pn)
{
    int maxValue = *pa;
    int maxPos = 0;

    for (int i = 1; i < *pn; i++)
    {
        if (*(pa + i) > maxValue) 
        {
            maxValue = *(pa + i);
            maxPos = i;
        }
    }

    return maxPos;
}



//--------------------------------------------------------------------------
int* getArray(int* pn)
{
    cout << "How many data items are there? ";
    cin >> *pn;

    int* pa = new int[*pn];
    for (int i = 0; i < *pn; i++)
    {
        cin >> *(pa + i);
    }
    return pa;
}


//--------------------------------------------------------------------------
void showArray(int* pa, int* pn)
{
    cout << endl;
    for (int i = 0; i < *pn; i++)
    {
        cout << i << ":" << *(pa + i) << "  ";
    }
    cout << endl;
}




void experiment01()
{
    //Obtain from the user the first, last-name, and email
    string first;
    string last;
    string email;
    getUserData(first, last, email);  //passing parameters by reference
    cout << "Hello " << first << " " << last << " at " << email << endl;
}

void getUserData(string& first, string& last, string& email)
{
    cout << "Enter first name:  ";
    getline(cin, first);
    cout << "Enter Last name:   ";
    getline(cin, last);
    cout << "Enter email:       ";
    getline(cin, email);
}

void experiment02()
{
    //Obtain from the user the first, last-name, and email
    string* pfirst = new string("");
    string* plast = new string("");
    string* pemail = new string("");

    getUserData2(pfirst, plast, pemail);  //passing parameters by reference

    cout << "Hello " << pfirst << " " << plast << " at " << pemail << endl;
    cout << "Hello " << *pfirst << " " << *plast << " at " << *pemail << endl;
}

void getUserData2(string* pfirst, string* plast, string* pemail)
{
    cout << "Enter first name:  ";
    getline(cin, *pfirst);
    cout << "Enter Last name:   ";
    getline(cin, *plast);
    cout << "Enter email:       ";
    getline(cin, *pemail);
}