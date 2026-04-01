#include <iostream>
#include <string>
#include <vector>

using namespace std;

string word;
void drawNumber(vector<string> &finalProduct, string frameChar, char character) {
    if (finalProduct[0]!="") {

        char before = finalProduct[2].back();

        if (frameChar=="*") before='*';

        for (int i = 0; i < 5; i++) finalProduct[i].pop_back();
        finalProduct[0] += (".."+frameChar+"..");
        finalProduct[1] += ("."+frameChar+"."+frameChar+".");
        finalProduct[2] += (string(1,before)+"."+string(1,character)+"."+frameChar);
        finalProduct[3] += ("."+frameChar+"."+frameChar+".");
        finalProduct[4] += (".."+frameChar+"..");
    }
    else {
        finalProduct[0] += (".."+frameChar+"..");
        finalProduct[1] += ("."+frameChar+"."+frameChar+".");
        finalProduct[2] += (frameChar+"."+string(1,character)+"."+frameChar);
        finalProduct[3] += ("."+frameChar+"."+frameChar+".");
        finalProduct[4] += (".."+frameChar+"..");
    }

}

vector<string> finalProduct(5);

int main() {

    cin >> word;

    string frameChar;

    for (int i = 1; i <= word.size(); i++) {

        if (i%3==0) frameChar = "*";
        else frameChar = "#";

        drawNumber(finalProduct, frameChar, word[i-1]);
    }

    for (string line : finalProduct)
        cout << line << endl;

    return 0;
    
}
