#include "Functions.h"
using namespace std;

string input (string message) {
    string result;
    cout << message;
    getline(cin, result);
    return result;
};

string join(vector <int> arr, string separator) {
    string result = "";

    for(auto item: arr)
        result += to_string(item) + separator;

    return result.substr(0, result.size() - 1);
}
