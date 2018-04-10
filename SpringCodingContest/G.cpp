#include <iostream>
#include <vector>
#include <string>

int ToIndex( char c )
{
    return (int)(c - 'a');
}

class TreeNode
{
public:
    bool isWord;
    TreeNode* children[26];
    TreeNode()
    {
        isWord = false;
        for( int i = 0; i < 26; ++i )
        {
            children[i] = nullptr;
        }
    }
    void add( std::string word )
    {
        if( word.length() == 0 )
        {
            isWord = true;
            return;
        }
        TreeNode* child = get( word[0] );
        if( !child )
        {
            child = new TreeNode();
            children[ToIndex( word[0] )] = child;
        }
        child->add( word.substr( 1 ) );
    }
    TreeNode* get( char c )
    {
        return children[ToIndex( c )];
    }
};

int main()
{
    using namespace std;
    std::string S;
    std::vector<std::string> keywords;
    cin >> S;
    int numKeywords;
    cin >> numKeywords;
    for( int i = 0; i < numKeywords; ++i )
    {
        std::string keyword;
        cin >> keyword;
        keywords.push_back( keyword );
    }

    TreeNode* root = new TreeNode();

    for( auto i = keywords.begin(); i != keywords.end(); ++i )
    {
        root->add( *i );
    }

    int output = 0;

    int parseStart = 0;
    int index = 0;
    int longestEncountered = 0;
    TreeNode* curr = root;
    while( index < S.length() )
    {
        curr = curr->get( S[index] );
        index++;
        if( !curr )
        {
            index = parseStart + longestEncountered;
            if( !longestEncountered )
            {
                index++;
            }

            output += longestEncountered;
            curr = root;
            longestEncountered = 0;
            parseStart = index;
        }
        else
        {
            if( curr->isWord )
            {
                longestEncountered = index - parseStart;
            }
        }
    }
    output += longestEncountered;

    cout << output << "\n";

    return 0;
}
