#include <iostream>
#include <string>
using namespace std;

struct word
{
    char table;
    int counter = 0;
    int sumcounter = 0;
    string huffman = "";
    int sortnum = 0;
};
word inputword[11];

void switchword(int i, int j);
void sortword(int wordnum);
void createhuffuman(int firnum, int secnum, int wordnum);
void huffmanchange(int i);

int main()
{
    string tmp;
    cin >> tmp;
    int wordnum = 0;
    for (int i = 0;; i++)
    {
        if (tmp[i] == '\0')
        {
            break;
        }
        else
        {
            bool create = 0;
            for (int j = 0; j < wordnum; j++)
            {
                if (tmp[i] == inputword[j].table)
                {
                    inputword[j].counter += 1;
                    inputword[j].sumcounter = inputword[j].counter;
                    create = 1;
                    break;
                }
            }
            if (!create)
            {
                inputword[wordnum].table = tmp[i];
                inputword[wordnum].counter += 1;
                inputword[wordnum].sumcounter = inputword[wordnum].counter;
                wordnum += 1;
            }
        }
    }
    for (int i = 0; i < wordnum; i++)
    {
        for (int j = i; j < wordnum; j++)
        {
            if (inputword[i].counter > inputword[j].counter)
            {
                switchword(i, j);
            }
        }
    }
    for (int i = 0; i < wordnum; i++)
    {
        sortword(wordnum);
        int firnum = inputword[0].sumcounter, secnum = 0;
        for (int j = 1; j < wordnum; j++)
        {
            if (inputword[j].sumcounter > firnum)
            {
                secnum = inputword[j].sumcounter;
                break;
            }
        }
        if (secnum != 0)
        {
            createhuffuman(firnum, secnum, wordnum);
        }
    }
    for (int i = wordnum - 1; i >= 0; i--)
    {
        huffmanchange(i);
    }
    for (int i = 0; i < wordnum; i++)
    {
        for (int j = i; j < wordnum; j++)
        {
            if (inputword[i].sortnum > inputword[j].sortnum)
            {
                switchword(i, j);
            }
        }
    }
    for (int i = 0; i < wordnum; i++)
    {
        cout << inputword[i].table << ":" << inputword[i].sortnum << endl;
    }
}

void switchword(int i, int j)
{
    word newinputword = inputword[i];
    inputword[i] = inputword[j];
    inputword[j] = newinputword;
}

void sortword(int wordnum)
{
    for (int i = 0; i < wordnum; i++)
    {
        for (int j = i; j < wordnum; j++)
        {
            if (inputword[i].sumcounter > inputword[j].sumcounter)
            {
                switchword(i, j);
            }
        }
    }
}

void createhuffuman(int firnum, int secnum, int wordnum)
{
    for (int i = 0; i < wordnum; i++)
    {
        if (inputword[i].sumcounter == firnum)
        {
            inputword[i].sumcounter = firnum + secnum;
            inputword[i].huffman += '0';
        }
        else if (inputword[i].sumcounter == secnum)
        {
            inputword[i].sumcounter = firnum + secnum;
            inputword[i].huffman += '1';
        }
    }
}

void huffmanchange(int i)
{
    string tmp = "";
    for (int j = inputword[i].huffman.length() - 1; j >= 0; j--)
    {
        tmp += inputword[i].huffman[j];
    }
    inputword[i].sortnum = stoi(tmp);
}