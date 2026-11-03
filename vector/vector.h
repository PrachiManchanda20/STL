#ifndef  VECTOR_H
#define VECTOR_H
#include <vector>
#include <iostream>
using namespace std;

template<typename T>
class Vector{
    private:
    T* arr;
    int current_Size;
    int capacity;
    
    public:

        int grow(){

            capacity *=2;
            
            T* newArr = new T[capacity];

            for(int i=0; i<capacity; i++){
                newArr[i] = arr[i];
            }

            delete[arr]; 
            // arr = newArr;
            }

        Vector(T *arr1 , int capacity, int size){

            arr = new T[capacity];

            for(int i = 0; i< capacity ; i++){
                this->arr[i] = arr1[i];
            }
           
            this->current_Size = size;//indexes
            this->capacity = capacity; //total sizd of array 
        }

        int push_back(int element){

            if(current_Size >= capacity){
                grow();
            }
            else{
                arr[current_Size] = element;
                current_Size ++;
            }

        return 0;
        }

        int pop_back(){

            // arr[current_Size] =;
            current_Size--;


        }

        int size(){


        }

       

        ~Vector(){

        }

    };


#endif