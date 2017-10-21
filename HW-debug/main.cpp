#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

//function protocols
void initialize_array(int origArray[], int sz);
int* sort_array(int origArray[], int sz);
void print_array(int[], int);
int* splitUpArray(int [], int size, int split_point);;
int* calc_sum_array(int *, int, int *, int,int &);

//start main
int main(void){
    srand(time(NULL));
    int sz;
    cout<<"What is the size of your array? ";
    cin>>sz;
    sz=sz-1;//keep from having 1 more than user amt requested
     int *origArray = new int [sz];//set size of array
    initialize_array(origArray,sz);//fill array with rand nums
    //cout<<"Initial Array/t"; //Identify Initial Array
    print_array(origArray, sz);//print original array
    //int newArray[sz];
    //*sort_array(origArray, sz);
    int *newArray = sort_array(origArray, sz);
    int split_point=rand()%(sz+1);
    int *splitArray = splitUpArray(newArray, sz, split_point);
    //cout<<"Sorted Array/t"; //Identify Initial Array
    print_array(splitArray, split_point);//print original array

//    int* newArray=sort_array(origArray, sz);//create new array object in heap
}

void initialize_array(int origArray[], int sz){
    for(int i=0; i<=sz; i++){
        origArray[i]=rand()%100;
    }
}

int * sort_array(int origArray[], int sz){
    int *sorted = new int[sz];
    for (int i = 0; i < sz; i ++){
        *(sorted + i) = *(origArray + i);
    }

    //bubble sort
    for(int i=0;i<sz-1;i++){
        for(int j=0;j<sz-i;j++){
            if(sorted[j]>sorted[j+1]){
                int temp=sorted[j];
                sorted[j]=sorted[j+1];
                sorted[j+1]=temp;
            }
        }
    }
    return sorted;
}

/*int sort_array(int *&origArray, int sz) {
    int *sorted = new int[sz];
    //bubble sort
    for(int i=0;i<=sz;i++){
        for(int j=0;j<=sz-i;j++){
            if(origArray[j]>origArray[j+1]){
                int temp=origArray[j];
                origArray[j]=origArray[j+1];
                origArray[j+1]=temp;
            }
        }
        sorted[i] = origArray[i];
    }
    delete [] origArray;
    origArray = sorted;
    cout<<sorted;
}
*/

void print_array(int numsList[], int sz){
    for(int i=0; i<=sz; i++){
        cout<<numsList[i]<<" ";
    }
    cout<<endl;
}

int* splitUpArray(int origArray[], int sz, int split_point){


    int *splitArr = new int[sz];
    for (int i = 0; i <=split_point; i ++){
        *(splitArr + i) = *(origArray + i);
    }
    return splitArr;
}

int* calc_sum_array(int *, int, int *, int,int &){

}
