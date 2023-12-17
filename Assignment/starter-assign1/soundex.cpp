/*
 * TODO: remove and replace this file header comment
 * This is a .cpp file you will edit and turn in.
 * Remove starter comments and add your own
 * comments on each function and on complex code sections.
 */
#include <cctype>
#include <fstream>
#include <string>
#include "console.h"
#include "strlib.h"
#include "filelib.h"
#include "simpio.h"
#include "vector.h"
#include "SimpleTest.h"
#include "soundex.h"
using namespace std;

/* This function is intended to return a string which
 * includes only the letter characters from the original
 * (all non-letter characters are excluded)
 *
 * WARNING: The provided code is buggy!
 *
 * Add student test cases to identify which inputs to this function
 * are incorrectly handled. Then, remove this comment and
 * replace it with a description of the bug you fixed.
 */
string lettersOnly(string s) {
    string result = "";
    for (int i = 0; i < s.length(); i++) {
        if (isalpha(s[i])) {
            result += s[i];
        }
    }
    return result;
}

string encode(string s) {
    string res = "";
    for(int i = 0; i < s.length(); i++) {
        switch(toupper(s[i])) {
        case 'B': case 'F': case 'P': case 'V':
            res += '1';
            break;
        case 'C': case 'G': case 'J': case 'K': case 'Q': case 'S': case 'X': case 'Z':
            res += '2';
            break;
        case 'D': case 'T':
            res += '3';
            break;
        case 'L':
            res += '4';
            break;
        case 'M': case 'N':
            res += '5';
            break;
        case 'R':
            res += '6';
            break;
        default:
            res += '0';
            break;
        }
    }
    return res;
}
string coalesce(string s) {
    if(s.length() == 0){
        return s;
    }
    string res = "";
    res += s[0];
    for(int i = 1; i < s.length(); i++) {
        if(s[i] != s[i - 1]) {
            res += s[i];
        }
    }
    return res;
}
string firstReplace(string s, string original) {
    if(s.length() == 0 || original.length() == 0) {
        return s;
    }
    string res = s;
    res[0] = toupper(original[0]);
    return res;
}
/* TODO: Replace this comment with a descriptive function
 * header comment.
 */
string discardZero(string s) {
    string res = "";
    for(int i = 0; i < s.length(); i++) {
        if(s[i] != '0')
            res += s[i];
    }
    return res;
}

string toLengthFour(string s) {
    string res = s;
    for(int i = 0; i < int(4 - s.length()); i++) {
        res += '0';
    }
    return res.substr(0, 4);
}
string soundex(string s) {
    /* TODO: Fill in this function. */
    string letters = lettersOnly(s);
    string encoded = encode(letters);
    string coalesced = coalesce(encoded);
    string replaced = firstReplace(coalesced, s);
    string zeroDiscarded = discardZero(replaced);
    string res = toLengthFour(zeroDiscarded);
    return res;
}


/* TODO: Replace this comment with a descriptive function
 * header comment.
 */
void soundexSearch(string filepath) {
    // This provided code opens the specified file
    // and reads the lines into a vector of strings
    ifstream in(filepath);
    vector<string> allNames;
    if(in.fail()) {
        return;
    } else {
        cout << "file opened" << endl;
    }

    string line;
    while(getline(in, line)) {
        allNames.push_back(line);
    }
    cout << "Read file " << filepath << ", "
         << allNames.size() << " names found." << endl;


    // The names read from file are now stored in Vector allNames

    /* TODO: Fill in the remainder of this function. */
    while(true) {
        cout << "Enter 0 to quit: " << endl;
        string input;
        cin >> input;
        if(input == "0") {
            break;
        }

        vector<string> res;
        string code = soundex(input);
        cout << code << endl;
        for(string name : allNames) {
            if(code == soundex(name)) {
                res.push_back(name);
            }
        }
        sort(res.begin(), res.end());

        for(string name : res) {
            cout << name << " ";
        }
        cout << endl;
    }
}


/* * * * * * Test Cases * * * * * */

// TODO: add your STUDENT_TEST test cases here!


/* Please not add/modify/remove the PROVIDED_TEST entries below.
 * Place your student tests cases above the provided tests.
 */

PROVIDED_TEST("Test exclude of punctuation, digits, and spaces") {
    string s = "O'Hara";
    string result = lettersOnly(s);
    EXPECT_EQUAL(result, "OHara");
    s = "Planet9";
    result = lettersOnly(s);
    EXPECT_EQUAL(result, "Planet");
    s = "tl dr";
    result = lettersOnly(s);
    EXPECT_EQUAL(result, "tldr");
}

PROVIDED_TEST("Sample inputs from handout") {
    EXPECT_EQUAL(soundex("Curie"), "C600");
    EXPECT_EQUAL(soundex("O'Conner"), "O256");
}

PROVIDED_TEST("hanrahan is in lowercase") {
    EXPECT_EQUAL(soundex("hanrahan"), "H565");
}

PROVIDED_TEST("DRELL is in uppercase") {
    EXPECT_EQUAL(soundex("DRELL"), "D640");
}

PROVIDED_TEST("Liu has to be padded with zeros") {
    EXPECT_EQUAL(soundex("Liu"), "L000");
}

PROVIDED_TEST("Tessier-Lavigne has a hyphen") {
    EXPECT_EQUAL(soundex("Tessier-Lavigne"), "T264");
}

PROVIDED_TEST("Au consists of only vowels") {
    EXPECT_EQUAL(soundex("Au"), "A000");
}

PROVIDED_TEST("Egilsdottir is long and starts with a vowel") {
    EXPECT_EQUAL(soundex("Egilsdottir"), "E242");
}

PROVIDED_TEST("Jackson has three adjcaent duplicate codes") {
    EXPECT_EQUAL(soundex("Jackson"), "J250");
}

PROVIDED_TEST("Schwarz begins with a pair of duplicate codes") {
    EXPECT_EQUAL(soundex("Schwarz"), "S620");
}

PROVIDED_TEST("Van Niekerk has a space between repeated n's") {
    EXPECT_EQUAL(soundex("Van Niekerk"), "V526");
}

PROVIDED_TEST("Wharton begins with Wh") {
    EXPECT_EQUAL(soundex("Wharton"), "W635");
}

PROVIDED_TEST("Ashcraft is not a special case") {
    // Some versions of Soundex make special case for consecutive codes split by hw
    // We do not make this special case, just treat same as codes split by vowel
    EXPECT_EQUAL(soundex("Ashcraft"), "A226");
}

STUDENT_TEST("letters only 1") {
    EXPECT_EQUAL(lettersOnly("1323DDF"), "DDF");
}

STUDENT_TEST("encode") {
    EXPECT_EQUAL(encode("Curie"), "20600");
}

STUDENT_TEST("coales") {
    EXPECT_EQUAL(coalesce("222025"), "2025");
}

STUDENT_TEST("first") {
    // EXPECT_EQUAL(firstReplace(, "Curie"), "C0600");
}

STUDENT_TEST("zero") {
    EXPECT_EQUAL(discardZero("C0600"), "C6");
}
