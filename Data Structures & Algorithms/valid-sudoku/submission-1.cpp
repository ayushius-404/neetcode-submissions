class Solution {
public:
    bool row(vector<vector<char>>& board){
        int n = board.size();
        for(int i = 0; i < n; i++){
            unordered_set<char> s;
            for(int j = 0; j <n; j++){
                if(board[i][j] == '.')
                    continue;
                if(s.count(board[i][j]))
                    return false;
                
                s.insert(board[i][j]);
            }
        }

        return true;
    }

    bool col(vector<vector<char>>& board){
        int n = board.size();
        for(int i = 0; i < n; i++){
            unordered_set<char> s;
            for(int j = 0; j <n; j++){
                if(board[j][i] == '.')
                    continue;
                if(s.count(board[j][i]))
                    return false;
                
                s.insert(board[j][i]);
            }
        }

        return true;
    }

    bool square(vector<vector<char>>& board){

        for(int i = 0; i <= 6; i += 3){
            for(int j = 0; j <= 6; j += 3){
                unordered_set<char> s;
                for(int p = i; p < i+3; p++){
                    for(int q = j; q < j+3; q++){
                        if(board[p][q] == '.')
                            continue;
                        if(s.count(board[p][q]))
                            return false;

                        s.insert(board[p][q]);
                    }
                }
            }
        }
        return true;
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        return row(board) && col(board) && square(board);
    }
};
