/**
 * @file: myset.h
 * @author: Hannah Culver
 * @date: September 18, 2022
 * @brief: header file for the myset class
 */

#ifndef MYSET
#define MYSET

#include <set>
using namespace std;

class MySet{
   public:
    MySet(){myset.clear();} //default constructor (initializes a set to the empty set)

    friend bool operator ^ (const int element, const MySet &s); //set membership (returns true if an element is in the set)
    
    MySet operator + (const int element); //adds an element to the set (returns the original set with the new element added)
    MySet operator - (const int element); //removes an element from the set (returns the original set with the new element removed)
    
    MySet operator + (const MySet &s); //union of two sets (returns a new set that contains all the elements of the both sets)
    MySet operator * (const MySet &s); //intersection of two sets (returns a new set that contains all the elements that are in both sets)
    MySet operator - (const MySet &s); //set difference (returns a new set that contains all the elements that are in the first set but not in the second)
    
    friend bool operator <= (const MySet &s1, const MySet &s2); //subset (returns true if all the elements of the first set are in the second)
    friend bool operator >= (const MySet &s1, const MySet &s2); //superset (returns true if all the elements of the second set are in the first)
    friend bool operator == (const MySet &s1, const MySet &s2); //set equality (returns true if both sets contain the same elements (in any order))

    string toString(); //returns a set string in the format "{1,2,3,4}" with the elements sorted

    int size(); //returns the number of elements in the set
    void clear(); //clears the set by removing all the elements

   private:
    set<int> myset;
};

#endif

string MySet::toString(){
    string set_string = "{"; //only for if the set has more than one element
    if(myset.size() == 0){
        return "{}"; //if the set is empty simply return "{}"
    }
    else if(myset.size() == 1){
        return "{" + to_string(*myset.begin()) + "}"; //if the set only has one element return the single element surrounded by brackets
    }
    else{
        for(auto it = myset.begin(); it != myset.end(); it++){
            set_string += to_string(*it) + ", "; //add each element followed by ", "
        }
        set_string.erase(set_string.length() - 2); //remove the extra comma and space before adding the closing bracket
    }
    return set_string += "}"; //again, only for if the set has more than one element
}

int MySet::size(){ //size function (already in the set library)
    return myset.size();
}

void MySet::clear(){ //clear function (already in the set library)
    myset.clear();
}

bool operator ^ (const int element, const MySet &s){ //implement the set membership
    if(s.myset.find(element) != s.myset.end()){
        return true; //element is somewhere in the set
    }
    return false;
};

MySet MySet::operator + (const int element){ //add an element to the set
    myset.insert(element); //insert function from set library
    return *this;
};

MySet MySet::operator - (const int element){ //remove an element from the set
    myset.erase(element); //erase function from set library
    return *this;
};

MySet MySet::operator + (const MySet &s){ //implement the union of two sets
    for(auto it = s.myset.begin(); it != s.myset.end(); it++){
        myset.insert(*it); //add every element from s to myset (duplicates will automatically be removed)
    }
    return *this;
};

MySet MySet::operator * (const MySet &s){ //implement the intersection of two sets
    MySet tmp; //create temporary set (initialized to be empty)
    for(auto it1 = myset.begin(); it1 != myset.end(); it1++){
        for(auto it2 = s.myset.begin(); it2 != s.myset.end(); it2++){
            if(*it1 == *it2){
                tmp.myset.insert(*it1); //insert matching elements
            }
        }
    }
    return tmp; //return temporary set
}

MySet MySet::operator - (const MySet &s){ //implement the set difference
    MySet tmp = *this; //create temporary set equal to myset
    for(auto it = s.myset.begin(); it != s.myset.end(); it++){
        tmp = tmp - *it; //remove all elements in s from tmp
    }
    return tmp; //return temporary set
}

bool operator <= (const MySet &s1, const MySet &s2){ //implement the subset
    if(s1.myset.size() > s2.myset.size()){
        return false; //if s1 is bigger than s2 immediately return false
    }
    set<int> match; //create a set called match
    for(auto it1 = s1.myset.begin(); it1 != s1.myset.end(); it1++){
        for(auto it2 = s2.myset.begin(); it2 != s2.myset.end(); it2++){
            if(*it1 == *it2){
                match.insert(*it1); //insert any and all matching elements
            }
        }
    }
    if(match.size() == s1.myset.size()){
        return true; //if match and s1 are the same size then return true
    }
    return false;
}

bool operator >= (const MySet &s1, const MySet &s2){ //implement the superset
    if(s1.myset.size() < s2.myset.size()){
        return false; //if s1 is smaller than s2 immediately return false
    }
    set<int> match; //create a set called match
    for(auto it1 = s1.myset.begin(); it1 != s1.myset.end(); it1++){
        for(auto it2 = s2.myset.begin(); it2 != s2.myset.end(); it2++){
            if(*it1 == *it2){
                match.insert(*it1); //insert any and all matching elements
            }
        }
    }
    if(match.size() == s2.myset.size()){
        return true; //if match and s2 are the same size then return true
    }
    return false;
}

bool operator == (const MySet &s1, const MySet &s2){ //implement the set equality
    return s1.myset.size() == s2.myset.size(); //return true if the sets are equal in size
};

//eof