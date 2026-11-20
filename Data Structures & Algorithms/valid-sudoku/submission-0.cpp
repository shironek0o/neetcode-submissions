class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            std::array<int, 10> row {}, col {};
            for (int j = 0; j < 9; j++) {
                if (std::isdigit(board[i][j])) {
                    row[board[i][j] - '0']++;
                }
                if (std::isdigit(board[j][i])) {
                    col[board[j][i] - '0']++;
                }
            }
            if (ranges::max(row) > 1 or
                ranges::max(col) > 1) {
                return false;
            }
        }
        for (int i = 0; i < 9; i++) {
            int x = (i % 3) * 3, y = (i / 3) * 3;
            std::array<int, 10> square {}; 
            for (int j = 0; j < 3; j++) {
                for (int k = 0; k < 3; k++) {
                    if (std::isdigit(board[x + j][y + k])) {
                        square[board[x + j][y + k] - '0']++;
                    }
                }
            }
            if (ranges::max(square) > 1) {
                return false;
            }
        }
        return true;
    }
};
