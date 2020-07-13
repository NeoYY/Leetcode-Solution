/*

Given an absolute path for a file (Unix-style), simplify it. Or in other words, convert it to the canonical path.

In a UNIX-style file system, a period . refers to the current directory. Furthermore, a double period .. moves the directory up a level.

Note that the returned canonical path must always begin with a slash /, and there must be only a single slash / between two directory names. The last directory name (if it exists) must not end with a trailing /. Also, the canonical path must be the shortest string representing the absolute path.



Example 1:

Input: "/home/"
Output: "/home"
Explanation: Note that there is no trailing slash after the last directory name.
Example 2:

Input: "/../"
Output: "/"
Explanation: Going one level up from the root directory is a no-op, as the root level is the highest level you can go.
Example 3:

Input: "/home//foo/"
Output: "/home/foo"
Explanation: In the canonical path, multiple consecutive slashes are replaced by a single one.
Example 4:

Input: "/a/./b/../../c/"
Output: "/c"
Example 5:

Input: "/a/../../b/../c//.//"
Output: "/c"
Example 6:

Input: "/a//b////c/d//././/.."
Output: "/a/b/c"


Solution using iterative
Can be done using strtok in C or stringstream in C++
*/


class Solution {
public:
    string simplifyPath(string path) {
        string res;
        int i = 0, n = path.size();
        vector<string> tp;
        while ( i < n )
        {
            while ( path[i] == '/' && i < n ) ++i;
            if ( i == n ) break;
            int start = i;
            while ( path[i] != '/' && i < n ) ++i;
            int end = i - 1;
            string temp = path.substr( start, end - start + 1 );
            if ( temp == ".." )
            {
                if ( !tp.empty() ) tp.pop_back();
            }
            else if ( temp != "." ) tp.push_back( temp );
        }
        if ( tp.empty() ) return "/";
        for ( auto &a: tp ) res += '/' + a;
        return res;
    }
};
