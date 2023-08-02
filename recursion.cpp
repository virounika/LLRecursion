// recursion.cpp

#include <iostream>
// #include <cassert>
#include <string>
using namespace std;

// Returns the product of two non-negative integers, m and n,
// using only repeated addition.
//
 int productOfTheSystem(unsigned int m, unsigned int n)
 {
     // Base case: If either m or n is zero, the product is zero
     if (m == 0 || n == 0) {
         return 0;
     }
     int product = m + productOfTheSystem(m, n - 1);
     return product;
 }

// Returns the number of occurrences of digit in the decimal
// representation of num. digit is an int between 0 and 9
// inclusive.
//
// Pseudocode Example:
// accountForADigit(18838, 8) => 3
// accountForADigit(55555, 3) => 0
// accountForADigit(0, 0) => 0 or 1 (either if fine)
//
int accountForADigit(int num, int digit)
{
    // Base case: If num is 0, there are no more digits to check
    if (num == 0) {
        // If digit is 0 and the number itself is 0, return 1, otherwise return 0
        if (digit == 0) {
            return 1;
        } else {
            return 0;
        }
    }
    // Recursive case:
    // Find the last digit of num
    int lastDigit = num % 10;

    // Calculate the remaining number after removing the last digit
    int remainingNum = num / 10; // will be set to 0 when 1 digit remains
    
    int count = 0;
    // Check if the lastDigit matches the digit we are looking for
    if (lastDigit == digit) {
        count = 1;
    }

    // Recursively call the function with the remainingNum and add to the count
    count = count + accountForADigit(remainingNum, digit);
    return count;
}

 // Returns a string where the same characters next each other in
 // string n are separated by "88" (you can assume the input
 // string will not have 8’s)
 //
 // Pseudocode Example:
 // eightClap("goodbye") => "go88odbye"
 // eightClap("yyuu") => "y88yu88u"
 // eightClap("aaaa") => "a88a88a88a"
 //
string eightClap(string n)
{
    // Base case: If the input string is empty or has a single character, return string itself
    if (n.length() <= 1) {
        return n;
    }
    // Recursive case:
    if (n[0] == n[1]) {
        return n.substr(0, 1) + "88" + eightClap(n.substr(1));
    } else {
        return n.substr(0, 1) + eightClap(n.substr(1));
    }
}

 // str contains a single pair of the less than and greater than
 // signs, return a new string made of only the less than and
 // greater than sign and whatever is contained in between
 //
 // Pseudocode Example:
 // coneHeads("abc<ghj>789") => "<ghj>"
 // coneHeads("<x>7") => "<x>"
 // coneHeads("4agh<y>") => "<y>"
 // coneHeads("4agh<>") => "<>"
 //

string coneHeads(string str) {
    if (str[0] == '<') {
        if (str[str.length() - 1] == '>') {
            return str; // Base case: If the string starts and ends with < and >, return
        } else {
            return coneHeads(str.substr(0, str.length() - 1)); // Recursion without the last char
        }
        // Still looking for <
    } else {
            return coneHeads(str.substr(1)); // Recursion without the first char
    }
}

 // Return true if the total of any combination of elements in
 // the array a equals the value of the target.
 //
 // Pseudocode Example:
 // conglomerateOfNumbers({2, 4, 8}, 3, 10) => true
 // conglomerateOfNumbers({2, 4, 8}, 3, 6) => true
 // conglomerateOfNumbers({2, 4, 8}, 3, 11) => false
 // conglomerateOfNumbers({2, 4, 8}, 3, 0) => true
 // conglomerateOfNumbers({}, 0, 0) => true
 //
bool conglomerateOfNumbers(const int a[], int size, int target) {
    if (target == 0) {
        return true; // Base case: If the target is 0, then the subset with no elements sums to 0
    }
    if (size == 0) {
        return false;
    }

    // If the last element is greater than the target, ignore it and check the rest of the array
    if (a[size - 1] > target) {
        return conglomerateOfNumbers(a, size - 1, target);
    } else {
        // Check two cases: including the last element or excluding it
        return conglomerateOfNumbers(a, size - 1, target) ||
               conglomerateOfNumbers(a, size - 1, target - a[size - 1]);
    }
}

// maze function
bool findAWay(string maze[], int nRows, int nCols, int sr, int sc, int er, int ec)
{
    // Base case: If the start location is equal to the ending location, we've solved the maze
    if (sr == er && sc == ec) {
        return true;
    }

    // Mark the current location as visited - drop a crumb
    maze[sr][sc] = '#';

    // Recursively check each of the 4 directions
    if (maze[sr - 1][sc] == '.') {
        if (findAWay(maze, nRows, nCols, sr - 1, sc, er, ec)) {
            return true;
        }
    }
    if (maze[sr][sc + 1] == '.') {
        if (findAWay(maze, nRows, nCols, sr, sc + 1, er, ec)) {
            return true;
        }
    }
    if (maze[sr + 1][sc] == '.') {
        if (findAWay(maze, nRows, nCols, sr + 1, sc, er, ec)) {
            return true;
        }
    }
    if (maze[sr][sc - 1] == '.') {
        if (findAWay(maze, nRows, nCols, sr, sc - 1, er, ec)) {
            return true;
        }
    }

    return false;
}



int main () {
    /*
   cout << eightClap("goodoobyeeee");
    int a = 1000000;
    int b = 0;
   cout << accountForADigit(a,b);

    cout << coneHeads("4agh<jkfgjlkjio>gh");
    int array[] = {2, 4, 8};
    int arrayb[] = {3, 3, 1, 9, 32};
    assert(conglomerateOfNumbers(array, 3, 8) == true);
    assert(conglomerateOfNumbers(arrayb, 5, 10) == true);
 
     string maze[10] = {
     "XXXXXXXXXX",
     "X.......@X",
     "XX@X@@.XXX",
     "X..X.X...X",
     "X..X...@.X",
     "X....XXX.X",
     "X@X....XXX",
     "X..XX.XX.X",
     "X...X....X",
     "XXXXXXXXXX"
        };
     if (findAWay (maze, 10, 10, 6, 2, 5, 2))
         cout << "Solvable!" << endl;
     else
         cout << "Out of luck!" << endl;

    string maze2[5] = {
          "XXXXX",
          "X@..X",
          "X.X.X",
          "X..@X",
          "XXXXX"
      };

      if (findAWay(maze2, 5, 5, 1, 1, 1, 2)) // should be solvable
          cout << "Maze 2: Solvable!" << endl;
      else
          cout << "Maze 2: Out of luck!" << endl;
    
    cout << endl;
      string maze3[7] = {
          "XXXXXXX",
          "X.....X",
          "X.X.X.X",
          "X.X.X.X",
          "X.X.X.X",
          "X.X.X.X",
          "XXXXXXX"
      };

      if (findAWay(maze3, 7, 7, 1, 1, 3, 3))
          cout << "Maze 3: Solvable!" << endl;
      else
          cout << "Maze 3: Out of luck!" << endl;
    */
    cout << accountForADigit(10300, 0);
     // return 0;
  }
   
