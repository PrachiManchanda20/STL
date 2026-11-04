#ifndef  VECTOR_H
#define VECTOR_H
#include <vector>
#include <iostream>
#include <stdexcept>
using namespace std;

template<typename T>
class Vector{
    private:
    T* arr;
    int current_Size;
    int capacity;
    
    public:

        int .grow(){ // make the array dynamic

            capacity *=2;
            
            T* newArr = new T[capacity];

            for(int i=0; i< current_Size; i++){
                newArr[i] = arr[i];
            }

            delete[] arr; 
            arr = newArr;

            // delete(newArr);
            }

        Vector(T *arr1 , int capacity, int size){ // take the values from the user

            arr = new T[capacity];

            for(int i = 0; i< capacity ; i++){
                this->arr[i] = arr1[i];
            }
           
            this->current_Size = size;//indexes
            this->capacity = capacity; //total sizd of array 
        }

        void .push_back(int element){ //insert at back

            if(current_Size >= capacity){
                grow();
            }
            
                arr[current_Size] = element;
                current_Size ++;
       
        }

        int .pop_back(){ //delete from back

            if(current_Size == 0){
                cout<<"Can't delete elements  ";
                return -1;
            }
           return current_Size--;


        }

        T& .at(int index){ //returns the particular index


            if(index < 0 || index >= current_Size){
               
                throw out_of_range("Invalid index");
            }
            return arr[index];

        }
        
        int size(){ //returns no of elements in an array

            return current_Size;

        }

        bool .empty(){ //check the array is empty or not 

            return current_Size == 0;

        }

        int .insert(int index , int element){

            if(index < 0 || index > capacity){
                cout<<"Invalid Index"<<endl;
            }
            
            for(int i = 0; i < arr.size(); i++){

                    for(int j = arr.size(); j != index ; j--){
                        arr[j] = arr[j-1];
                    }

                    if(i == index){
                        int t = arr[i];
                    }
            }

        }

        int .Capacity(){
            return capacity;
        }

        int .clear(){ // changes the current size to 0

            current_Size = 0;

        }

        int .erase(int index){//remove the element from the position 

            if(index < 0 || index >= current_Size){
                cout<<"Can't access values beyond limit!"<<"\n";
            }
            for( int i = index ; i< current_Size - 1; i++){
                
                    arr[i] = arr[i+1];
                
            }
            current_Size--;
             return 0;
        }

        int .reserve(){
            
            

        }

        // int operator_overloading


       T& .front(){

        if(empty()){
            cout<<"Array is Empty !"<<"\n";
        }
        return arr[0];

       }

       T& .back(){

        if(empty()){
            cout<< "array is empty!"<<"\n";
        }
        return arr[current_Size - 1];

       }

        ~Vector(){

            cout<<"Vector Ended !"<<"\n";
            delete[] arr;
        }

    };


#endif