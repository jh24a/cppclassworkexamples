#include <iostream> 
#include <iomanip>
#include <fstream>
using namespace std;

const int NMONTHS = 12 , TEMPS = 2;

ifstream input("weather.txt");
ofstream output("weather.out");

void data(int arr[][TEMPS], int row);
void display(int arr[][TEMPS], int row);
double avghigh(int arr[][TEMPS], int row);
double avglow(int arr[][TEMPS], int row);
int lowesttemp(int arr[][TEMPS], int row);
int highesttemp(int arr[][TEMPS], int row);


int main(){

  int arr[NMONTHS][TEMPS];

  data(arr, NMONTHS);

  display(arr, NMONTHS);


  return 0;
}
/***********************************/ //FILLS ARRAY
void data (int arr[][TEMPS], int row){
  for(int i= 0; i<row; i++){
    for(int j = 0; j<TEMPS; j++){
      input >> arr[i][j];
    } 
  }
}
/**********************************/ // DISPLAYS ARRAY
void display(int arr[][TEMPS], int row){

  string months[NMONTHS] = {"January",
                            "February",
                            "March",
                            "April",
                            "May",
                            "June",
                            "July",
                            "August",
                            "September",
                            "October",
                            "November",
                            "December"};

//monitor                           
  cout << left << setw(13) << "Month" << setw(7) << "High" << "Low" << endl;
  cout << "_______________________"<<endl;
  for(int i= 0; i<NMONTHS; i++){
    cout << left << setw(13)<< months[i]; //array for months
    for(int j = 0; j<TEMPS; j++){
      cout << setw(7) << arr[i][j];
    }
    cout << endl;
  }
  
  cout << endl;
  cout << "Average high temperature: " << avghigh(arr, NMONTHS) << endl;
  cout << "Average low temperature: " << avglow(arr, NMONTHS) << endl;
  cout << "Highest temperature: " << highesttemp(arr, NMONTHS) << endl;
  cout << "Lowest temperature: " << lowesttemp(arr, NMONTHS) << endl;

//file
  output << left << setw(13) << "Month" << setw(7) << "High" << "Low" << endl;
  output << "_______________________"<<endl;
  for(int i= 0; i<NMONTHS; i++){
    output << left << setw(13)<< months[i];
    for(int j = 0; j<TEMPS; j++){
      output << setw(7) << arr[i][j];
    }
    output << endl;
  }
 
  output << endl;
  output << "Average high temperature: " << avghigh(arr, NMONTHS) << endl;
  output << "Average low temperature: " << avglow(arr, NMONTHS) << endl;
  output << "Highest temperature: " << highesttemp(arr, NMONTHS) << endl;
  output << "Lowest temperature: " << lowesttemp(arr, NMONTHS) << endl;


}
/*********************************/ // AVERAGE HIGH TEMPERATURE
double avghigh(int arr[][TEMPS], int row){
  double avghigh, sum = 0;

  for (int i = 0; i<row; i++)
    sum = sum + arr[i][0];

  cout << fixed << showpoint << setprecision(2);
  output << fixed << showpoint << setprecision(2);
  avghigh = sum / NMONTHS;

  return avghigh;
}
/**********************************/ //AVERRAGE LOW TEMPERATURE
double avglow(int arr[][TEMPS], int row){
  double avglow, sum = 0;

  for (int i = 0; i< row; i++)
    sum = sum + arr[i][1];

  cout << fixed << showpoint << setprecision(2);
  output << fixed << showpoint << setprecision(2);
  avglow = sum / NMONTHS;

  return avglow;
}
/**********************************/ // LOWEST REMPERATURE
int lowesttemp(int arr[][TEMPS], int row){
  int lowesttemp = arr[0][1];
  
  for (int i = 0; i< row; i++){
    if(lowesttemp > arr[i][1]){
      lowesttemp = arr[i][1];
    
    }
  }

  return lowesttemp;
}
/**********************************/ //HIGHEST TEMPERATURE
int highesttemp(int arr[][TEMPS], int row){
  int highesttemp = arr[0][0];
  
  for (int i = 0; i< row; i++){
    if(highesttemp < arr[i][0]){
      highesttemp = arr[i][0];
      
    }
  }

  return highesttemp;
}
