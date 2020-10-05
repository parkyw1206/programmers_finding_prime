/************************************************************
 *  name : Youngwoo Park
 *  date : 10-05-2020
 *  level: l3
 *  problem source: programmers
 *  lang: C++
 *  skill:  brute force
 * *********************************************************/
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
bool checkPrime(int num){
    if(num < 2) return false;
    for(int i  = 2 ; i < num; i++){
        if(num % i == 0)
            return false;
    }
    return true;
}
int solution(string numbers) {
    int answer = 0, N = numbers.size();
    bool select[numbers.size()];
    vector<int> number;
    vector<int> found;
    string temp;
    
    for(int i = 0 ; i < numbers.size() ; i++)
        number.push_back((int)numbers[i]-48);
    
    for(int j  = 0 ; j < numbers.size() ; j++){
        for(int k = 0 ; k < j ; k++){
            select[k] = 0;
        }
        for(int k = j; k < numbers.size() ; k++){
            select[k] = 1;
        }
        do{
            sort(number.begin(), number.end());
            do{
                temp = "";
                for(int i = 0 ; i < numbers.size() ; i++){
                    if(select[i]){
                        //cout << select[i] << " : " << number[i] << endl;
                        temp += to_string(number[i]);
                    }
                }
                //cout << stoi(temp) << endl;
                if(find(found.begin(), found.end(), stoi(temp)) == found.end())
                {
                    found.push_back(stoi(temp));
                    if(checkPrime(stoi(temp)))
                    {
                        //cout << "-----> Prime" << endl;
                        answer++;
                    }                                    
                }

            }while(next_permutation(number.begin(), number.end()));
        }while(next_permutation(select, select + numbers.size()));        
    }

    return answer;
}