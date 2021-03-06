//Jorge Avila
//Calculates the final grade of Computer Architecture
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <iterator>
#include <map>
#include <algorithm>
#include <typeinfo>

using namespace std;

//prototypes
bool sortByVal(const pair<string, int> &a, 
               const pair<string, int> &b) 
{ 
    return (a.second < b.second); 
} 

int main ()
{
  cout << "Welcome to The Computer Architecture Grade Calculator" << endl;

  //create a quiz map
  map < string, float >quizMap;

  //populate the quiz with your solidified quiz grades
  quizMap.insert (make_pair ("Q1", (11.0 / 12.0) * 100.0));
  quizMap.insert (make_pair ("Q2", (11.5 / 14.0) * 100.0));
  quizMap.insert (make_pair ("Q3", (17.0 / 27.0) * 100.0));
  quizMap.insert (make_pair ("Q4", (24.0 / 24.0) * 100.0));

  //print the map
  cout << "Quiz Grades as following: " << endl;
  
for (auto i:quizMap)
    cout << i.first << " : " << i.second << endl;


  //drop the lowest two from the quiz
	vector<pair<string, float> > vec;

  // copy key-value pairs from the map to the vector
  map<string, float> :: iterator it2;
  for (it2=quizMap.begin(); it2!=quizMap.end(); it2++) 
  {
    vec.push_back(make_pair(it2->first, it2->second));
  }

   sort(vec.begin(), vec.end(), sortByVal); 

	// print the vector
	cout << "The map, sorted by value is: " << endl;
	for (int i = 0; i < vec.size(); i++)
	{
		cout << vec[i].first << ": " << vec[i].second << endl;
	}

    //now drop the lowest two
    vec.erase(vec.begin());
    vec.erase(vec.begin());
    float averageQuiz = 0.0;
    float N = (float)vec.size();
    
    cout << "Updated Quizzes are: " << endl;
	for (int i = 0; i < vec.size(); i++)
	{
		cout << vec[i].first << ": " << vec[i].second << endl;
        averageQuiz = averageQuiz + vec[i].second;
        //cout << typeid(vec[i].second).name() << endl;
	}
    //find the average of Quizzes
    
    cout << "The Quiz Average with the two lowest dropped is: " << endl;
    cout << averageQuiz/N << endl;
    
    //Exam 1
    
    float exam1 = 82.0;
    //Exam 2
    float exam2 = 0.0;
    //total grade:
    float totalGrade = (averageQuiz*(0.4))/N + exam1*(0.3) + exam2*(.3);
    cout << "Your total grade is :" << totalGrade/0.7 << endl;
  return 0;
}


