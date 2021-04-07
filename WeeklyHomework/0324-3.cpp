#include <iostream>
#include <string>
using namespace std;

void Hamiltoniancyclecheck(int n); //檢查是否存在"漢米爾頓迴路"
bool conn[1001][1001] = {{0}};     //一個連接狀態表：1代表兩點有連接；0則沒有(從1開始)
int numberofconn = 0;              //numberofconn此圖中有幾個節點

bool check[1001] = {0};    //將已經檢查的點標記(從1開始)
int havecheck[1001] = {0}; //將已經檢查的點且在迴路中的話，加入陣列中(從0開始)

bool checkpoint = 0; //最後回傳是否存在"漢米爾頓迴路"

bool reslut[1001] = {0};

int main()
{
    int N; //N表幾大組測資
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int num; //num表幾組連接狀態
        cin >> num;
        numberofconn = 0; //清空最大節點數
        for (int j = 0; j < 1001; j++)
        {
            for (int k = 0; k < 1001; k++)
            {
                conn[j][k] = 0;
            }
        } //清空連結狀態表
        for (int j = 0; j < num; j++)
        {
            string temp; //當下的輸入
            cin >> temp;
            string temp1; //前面的數字
            string temp2; //後面的數字
            int l = 0;    //確認現在在前還是後
            for (int k = 0; k < temp.length(); k++)
            {
                if (temp[k] <= '9' && temp[k] >= '0' && (l == 0))
                {
                    temp1 += temp[k];
                }
                else if (temp[k] == ',' && (l == 0))
                {
                    l = 1;
                }
                else if (temp[k] <= '9' && temp[k] >= '0' && (l == 1))
                {
                    temp2 += temp[k];
                }
            }                                     //將前面的數字與後面的數字從當下的輸入分離出來
            int a = stoi(temp1), b = stoi(temp2); //將前面的數字與後面的數字轉成int
            conn[a][b] = 1;
            conn[b][a] = 1; //建立狀態表
            if (numberofconn < b)
            {
                numberofconn = b;
            }
            else if (numberofconn < a)
            {
                numberofconn = a;
            } //求出點的數量
        }
        for (int k = 1; k <= numberofconn; k++)
        {
            for (int m = 0; m < 1001; m++)
            {
                check[m] = 0;
                havecheck[m] = 0;
            } //清空判斷的陣列
            check[k] = 1;
            havecheck[0] = k;
            checkpoint = 0;           //設定開頭與起使狀態
            Hamiltoniancyclecheck(1); //從第二個點開始確認
            if (checkpoint)
            {
                reslut[i] = checkpoint;
                break;
            }
        }
    }
    for (int i = 0; i < N; i++)
    {
        if (reslut[i])
        {
            cout << "True" << endl;
        }
        else
        {
            cout << "False" << endl;
        }
    }
    //system("pause");
}

void Hamiltoniancyclecheck(int n)
{
    if (checkpoint)
    {
        return;
    }
    else if (n == numberofconn)
    {
        int b = havecheck[0];
        int a = havecheck[n - 1];
        if (conn[a][b])
        {
            checkpoint = 1;
        }
        return;
    } //若判斷到最後一條線，確認是否相連，並返回
    int a = havecheck[n - 1];
    for (int b = 1; b <= numberofconn; b++)
    {
        if (conn[a][b] && !check[b] && !checkpoint) //確認是否相連且是否已經走過
        {
            check[b] = 1;
            havecheck[n] = b;             //設定走過
            Hamiltoniancyclecheck(n + 1); //檢查後面的點
            check[b] = 0;                 //錯誤返回
        }
    }
}