#include<stdio.h>
#include<windows.h>
#include<stdlib.h>
#include <conio.h>
#include <time.h>
int* make_data10000();
int* make_data50000();
int* make_data200000();
int* make_data200000();
int* make_data100();

void quicksort(int arr[], int high, int low);
int pivotposition(int arr[], int high, int low);

void mergesort(int arr[], int n);
void msort(int arr[], int tempArr[], int left, int right);
void merge(int arr[], int tempArr[], int left, int mid, int right);

//int * counting_sort(int arr[], int count, int max);
void counting_sort(int* arr, int n);
void radixsort(int a[],int length);
void insert_sort(int a[], int n);

void coloursort(int a[], int length); 

void menu();
