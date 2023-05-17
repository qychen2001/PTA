#include <bits/stdc++.h>
using namespace std;

char input_matrix[5][7][26];

int main()
{
    char temp[5];
    for (int i = 0; i < 26; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            scanf("%s", &temp);
            for (int k = 0; k < 5; k++)
            {
                input_matrix[k][j][i] = temp[k];
            }
        }
    }
    string s;
    // cin >> s; // 读入句子
    cin.ignore();// 非常重要！
    getline(cin, s);
    cout << s;
    vector<string> w;
    int num_w = 0;
    bool flag = false;
    int current_w = 0;
    string temp_s = "";
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] >= 'A' and s[i] <= 'Z')
            temp_s = temp_s + s[i];
        else if (temp_s.size() > 0)
        {
            w.push_back(temp_s);
            // cout << temp_s << endl;
            temp_s = "";
        }
        if (i == s.size() - 1 and s[i] >= 'A' and s[i] <= 'Z')
        {
            w.push_back(temp_s);
        }
    }

    // 接下来要输出
    for (int n_word = 0; n_word < w.size(); n_word++)
    {
        // 对每个词输出
        for (int line = 0; line < 7; line++)
        // 对每行输出
        {
            for (int n_c = 0; n_c < w[n_word].size(); n_c++)
            {
                // 对每个字母输出
                int current_c = w[n_word][n_c] - 'A';
                for (int i = 0; i < 5; i++)
                {
                    printf("%c", input_matrix[i][line][current_c]);
                }
                if (n_c < w[n_word].size() - 1)
                    printf(" ");
            }
            printf("\n");
        }
        if (n_word < w.size() - 1)
            printf("\n");
    }

    system("pause");
    return 0;
}