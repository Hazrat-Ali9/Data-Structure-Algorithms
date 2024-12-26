class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        vector<vector<int>> memo(books.size(), vector<int>(shelfWidth + 1, 0));
        return dpHelper(books, shelfWidth, memo, 0, shelfWidth, 0);
    }

private:
    int dpHelper(vector<vector<int>>& books, int shelfWidth,
                 vector<vector<int>>& memo, int i, int remainingShelfWidth,
                 int maxHeight) {
        vector<int> currentBook = books[i];
        int maxHeightUpdated = max(maxHeight, currentBook[1]);
        if (i == books.size() - 1) {
            if (remainingShelfWidth >= currentBook[0]) return maxHeightUpdated;
            return maxHeight + currentBook[1];
        }
        if (memo[i][remainingShelfWidth] != 0) {
            return memo[i][remainingShelfWidth];
        } else {
            int option1Height =
                maxHeight + dpHelper(books, shelfWidth, memo, i + 1,
                                     shelfWidth - currentBook[0],
                                     currentBook[1]);
            if (remainingShelfWidth >= currentBook[0]) {
                int option2Height = dpHelper(
                    books, shelfWidth, memo, i + 1,
                    remainingShelfWidth - currentBook[0], maxHeightUpdated);
                memo[i][remainingShelfWidth] =
                    min(option1Height, option2Height);
                return memo[i][remainingShelfWidth];
            }
            memo[i][remainingShelfWidth] = option1Height;
            return memo[i][remainingShelfWidth];
        }
    }
};