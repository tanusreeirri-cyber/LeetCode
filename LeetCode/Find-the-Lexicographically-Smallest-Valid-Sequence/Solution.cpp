 if (word1[i] == word2[j] ||
                (skip == 0 && (j == m - 1 || i < last[j + 1])))
        skip += (word1[i] != word2[j] ? 1 : 0); // what a lousy way of setting whether we skipped or not!