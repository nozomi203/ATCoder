#include "util/common.h"

int main() {
    map<string, string> dict = {
        {"N","S"},
        {"E","W"},
        {"W","E"},
        {"S","N"},
        {"NE","SW"},
        {"NW","SE"},
        {"SE","NW"},
        {"SW","NE"},
    };

    string D;
    cin >> D;
    cout << dict[D] << endl;
}