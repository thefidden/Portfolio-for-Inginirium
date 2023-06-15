#include "Functions.h"
using namespace std;

string input (string message) {
    string result;
    cout << message;
    getline(cin, result);
    return result;
};
