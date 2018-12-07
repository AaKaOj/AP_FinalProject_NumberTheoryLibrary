#include<stdbool.h>
#include<stdio.h>
#include<stdlib.h> 
#include<math.h>

typedef struct
{
   int quotient, remain; 
}QRT;

typedef struct factoring
{
	int arr1[100];		// Stores factor 1
	int arr2[100];		//Exponents associeted with factor 1
	int common;		//Stores factor 2
	int expcom;		// Exponent asociated with factor 2
}fac;

long factorial (int n); //Developed by Ojasvin Nagpal
int sumUpto(int n); //Developed by Ojasvin Nagpal
int exponent(int a, int b); //Developed by Ojasvin Nagpal
int* sortArray(int *arr, int n); //Developed by Ojasvin Nagpal
int gcd(int a, int b); //Developed by Ojasvin Nagpal
int lcm(int c, int d); //Developed by Ojasvin Nagpal
int arrayGCD(int nums[], int n); //Developed by Aastha Girotra
int arrayLCM(int nums[], int n); //Developed by Aastha Girotra
bool isPrime(int n); //Developed by Ojasvin Nagpal
bool areCoPrime(int a, int b); //Developed by Ojasvin Nagpal
int nextPrime(int n); //Developed by Ojasvin Nagpal
int prevPrime(int n); //Developed by Ojasvin Nagpal
int nearestPrime(int n); //Developed by Ojasvin Nagpal 
int* listPrimes (int n); //Developed by Aastha Girotra
int countPrimesTill (int n); //Developed by Aastha Girotra
int* listPrimesTill (int n); //Developed by Aastha Girotra
int getMod(int a, int b); //Developed by Aastha Girotra
bool isCongruent(int a, int b, int n); //Developed by Aastha Girotra
int addMod (int a, int b, int m); //Developed by Aastha Girotra
int subMod (int a, int b, int m); //Developed by Aastha Girotra
int multiplyMod (int a, int b, int m); //Developed by Aastha Girotra
int inverseMod(int a, int m); //Developed by Aastha Girotra
int expMod(int a, int b, int m); //Developed by Aastha Girotra
int squareMod(int a, int m); //Developed by Aastha Girotra
QRT QRtheorem(int a, int b); //Developed by Aastha Girotra
int countFactors (int n); //Developed by Aastha Girotra
int countPrimeFactors (int n); //Developed by Aastha Girotra
int* listFactors (int n); //Developed by Aastha Girotra
int* listPrimeFactors (int n); //Developed by Aastha Girotra
int divTimes(int n, int a); //Developed by Aastha Girotra
int* primeFactorize(int n); //Developed by Aastha Girotra
int discreteLogarithm(int a, int b, int m);//Developed by Aastha Girotra
int degree(int coefficient[], int exponent[], int n); //Developed by Kavya Narain
void sort(int sortarr[], int corrarr[], int n); //Developed by Kavya Narain
void combine(int coefficient[], int exponent[], int n); //Developed by Kavya Narain
int *uniform(int coefficient[], int exponent[], int n); //Developed by Kavya Narain
void standard(int coefficient[], int exponent[], int n); //Developed by Kavya Narain
int *sum(int coefficient1[], int n1, int coefficient2[], int n2); //Developed by Kavya Narain
int *dif(int coefficient1[], int n1, int coefficient2[], int n2); //Developed by Kavya Narain
int *product(int coefficient1[], int n1, int coefficient2[], int n2); //Developed by Kavya
fac *factor(int coefficient1[],int exponent1[], int n1); //Developed by Kavya Narain







