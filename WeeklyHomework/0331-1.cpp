#include <iostream>

int main()
{
    int num;
    std::cin >> num;
    for (int i = 0; i < num; i++)
    {
        int score[21] = {0};
        for (int j = 0; j < 20; j++)
        {
            std::cin >> score[j];
        }
        for (int a = 0; a < 20; a++)
        {
            for (int b = a; b < 20; b++)
            {
                if (score[b] > score[a])
                {
                    int temp = score[b];
                    score[b] = score[a];
                    score[a] = temp;
                }
            }
        }
        int th;
        std::cin >> th;
        std::cout << score[20 - th] << std::endl;
    }
}