

class Solution {
public:
    std::vector<int> getRow(int rowIndex) {
        
        std::vector<int> row(rowIndex + 1, 1);
        
        for (int i = 1; i <= rowIndex; ++i) {
            
            for (int j = i - 1; j > 0; --j) {
                row[j] = row[j] + row[j - 1];
            }
        }
        
        return row;
    }
};