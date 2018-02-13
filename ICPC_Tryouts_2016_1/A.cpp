#include <regex>
#include <string>
#include <iostream>
using namespace std;

int main()
{

    string s("there is a subsequence in the string\n");
    try{
    regex e("there");
    string p("sub");
    string result =  std::regex_replace(s,e,p);
    const char *c = result.c_str();
    cout << result << endl;
    }
    catch(regex_error& err)
    {
        cout << err.code() << endl;;
        cout << regex_constants::error_collate << endl;
        cout << regex_constants::error_ctype << endl;
        cout << regex_constants::error_escape << endl;
        cout << regex_constants::error_backref << endl;
        cout << regex_constants::error_brack << endl;
        cout << regex_constants::error_paren << endl;
        cout << regex_constants::error_brace << endl;
        cout << regex_constants::error_badbrace << endl;
        cout << regex_constants::error_range << endl;
        cout << regex_constants::error_brace << endl;
        cout << regex_constants::error_brace << endl;
    }

}
