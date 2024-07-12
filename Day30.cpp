//Q1 . Count of number of given string in 2D character array
//TC-O(m*n)
//SC-O(1)

class Solution {
public:
   
    int countConsistentStrings(string allowed, vector<string>& words) {
       set<char>stt;
       for(char c: allowed) stt.insert(c);
    int ans =0;
       for(string it : words){
        bool temp = true;
        for(char str : it){
             if(stt.find(str) == stt.end()) {
                temp = false;
            }
           
        }
         if(temp) ans++;
       }

       return ans;

    }
};

//Q2 . Search a word in a 2D Grid of Characters
//TC-O(R*C*(3*W.length))
//SC-O(Word.length())
class Solution {
    private :
    bool DFS(vector<vector<char>>& board, string word, int r, int c, int wi){
        //base case

        if (wi == word.length()) return true;
        //termination cases
        int rows = board.size();
        int cols = board[0].size();

        if(r<0 || r>=rows || c<0 || c>=cols ) return false;
        // Invalid cases

        if(board[r][c] == ' ' || board[r][c] != word[wi]) return false;


        //solution

       //step1 : mark as visited
       char ch = board[r][c];
        board[r][c] = ' ';
        //step2: DFS calls
      
        if(DFS(board,word,r,c+1,wi+1) || DFS(board,word,r-1,c,wi+1) || DFS(board,word,r+1,c,wi+1) || DFS(board,word,r,c-1,wi+1)){
            return true;
        }
        board[r][c]=ch;
        return false;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m= board.size();
        int n = board[0].size();
        int wi =0;
        bool ans = false;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j] == word[wi]){
                   ans = DFS(board, word,i,j,wi);
                   if(ans == true ) return true;
                }
            }
        }
        return false;
    }
};