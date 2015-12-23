/*
 Tom Anderson 2015
 Check if two words are anagrams using heap sort.
*/

#include <iostream>
#include <string.h>
using namespace std;
bool is_anagram (string, string);
void buildHeap( char[] , string);
void sortHeap(char[], int);
bool isEqual(char[], char[], int);
int main()
{
    string stringOne = "SALTED";
    string stringTwo = "LASTAD";
    if (is_anagram(stringOne, stringTwo))
    {
        cout << "They were anagrams" << endl;
    }
    else
    {
        cout << "Too bad, they were not anagrams" << endl;
    }
    return 0;
}

bool is_anagram (string stringOne, string stringTwo)
{
    if (stringOne.length() != stringTwo.length())
    {
        return false;
    }
    int lastIndex = stringOne.length();
    char heapOne [lastIndex] ;
    char heapTwo[lastIndex] ;
    buildHeap( heapOne, stringOne);
    buildHeap( heapTwo, stringTwo);
    sortHeap(heapOne, lastIndex);
    sortHeap(heapTwo, lastIndex);
    return (isEqual(heapOne,heapTwo, lastIndex));
}

void buildHeap(char heap[], string inputString)
{
    int elements =0;
    int i;
    for (i =1; i <=inputString.length(); i++)
    {
        heap[i] = inputString[i -1];                //add to last position of array
        elements ++;
        int childIndex = i;
        while (childIndex > 1 && heap [childIndex/2] < heap [childIndex]) //upHeaping
        {
            char temp = heap [childIndex];
            heap [childIndex] = heap [childIndex/2];
            heap [childIndex/2] = temp;
            childIndex =childIndex /2;
        }
    }
}
void sortHeap(char heap [], int lastIndex)
{
    char temp;
    while (lastIndex >1)
    {
        temp = heap[1];                 //swap first with last
        heap[1] = heap[lastIndex];
        heap[lastIndex] = temp;
        lastIndex --;                   //set last sorted out of our range
        int parent =1;
        bool isHeap =false;
        while (!isHeap)                 //downHeap
        {
            if ((heap[parent] < heap[parent*2]) || (heap[parent] < heap[parent * 2+1] ))
            {
                if ((heap[parent*2] <= heap[parent*2+1]) && (parent*2+1 <= lastIndex))
                {
                    temp = heap[parent];        //swap
                    heap[parent] = heap[parent *2 +1];
                    heap[parent *2 +1] = temp;
                    parent = parent *2 +1;      //next level
                }
                else if (heap[parent] < heap[parent * 2] && (parent*2 <= lastIndex))
                {
                    temp = heap[parent];        //swap
                    heap[parent] = heap[parent *2];
                    heap[parent *2] = temp;
                    parent = parent *2;         //next level
                }
                else
                {
                    isHeap = true;
                }
            }
            else
            {
                isHeap = true;
            }
        }
    }
}
bool isEqual(char heapOne[], char heapTwo[], int lastIndex)
{
    int current = 1;
    while (current <= lastIndex )
    {
        if (heapOne[current] != heapTwo[current])
        {
            return false;
        }
        current++;
    }
    return true;
}
