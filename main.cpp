#include <iostream>
using namespace std;

#define MAX_TEXT_SIZE 100

void rot_13_encrypt(char* plaintext, char* ciphertext)
{
    unsigned char c;
    for (int i = 0; i < strlen(plaintext); i++)
    {
        c = plaintext[i] + 13;
        
        if (c > 126)
        {
            // c = 32 + ((plaintext[i] + 13) % 126);
            c = 32 + (c % 126);
        }

        ciphertext[i] = c;
    }
}

void rot_13_decrypt(char* plaintext, char* ciphertext)
{
    unsigned char p;

    for (int i = 0; i < strlen(ciphertext); i++)
    {
        p = ciphertext[i] - 13;

        if (p < 33)
        {
            p = 126 - (32 - p);
        }

        plaintext[i] = p;
    }
}

void rot_n_encrypt(int n, char* plaintext, char* ciphertext)
{
    unsigned char c;
    for (int i = 0; i < strlen(plaintext); i++)
    {
        c = plaintext[i] + n;
        
        if (c > 126)
        {
            // c = 32 + ((plaintext[i] + n) % 126);
            c = 32 + (c % 126);
        }

        ciphertext[i] = c;
    }
}

void rot_n_decrypt(int n, char* plaintext, char* ciphertext)
{
   unsigned char p;

    for (int i = 0; i < strlen(ciphertext); i++)
    {
        p = ciphertext[i] - n;

        if (p < 33)
        {
            p = 126 - (32 - p);
        }

        plaintext[i] = p;
    }
}

void fisherYatesShuffling(int *arr, int n);

int indexOf(int* arr, int size, int c)
{
    for (int i = 0; i < size; i++)
    {
        if (c == arr[i])
        {
            return i;
        }
    }

    return -1;
}

void randomCipherEncrypt(int* map, char* plaintext, char* ciphertext)
{
    for (int i = 0; i < strlen(plaintext); i++)
    {
        char c = map[plaintext[i] - 33];
        //cout << "Replaced " << plaintext[i] << " with " << c << "\n";
        ciphertext[i] = c;
    }
}

void randomCipherDecrypt(int* map, char* plaintext, char* ciphertext)
{
    for (int i = 0; i < strlen(ciphertext); i++)
    {
        char p = indexOf(map, 94, ciphertext[i]);
        plaintext[i] = p + 33;
    }
}

int main(int argc, char** argv)
{
    // srand(15183);

    char plaintext[MAX_TEXT_SIZE] = "Text_without_space!#+,-./{|}~opqrstuv\0";
    //char plaintext[MAX_TEXT_SIZE] = "!\"#$%&'()*+,-.\0";
    char ciphertext[MAX_TEXT_SIZE];
    ciphertext[strlen(plaintext)] = '\0';

    // rot_13_encrypt(plaintext, ciphertext);
    // cout << ciphertext << "\n";
    // // rot13(ciphertext, plaintext, MAX_TEXT_SIZE);
    // rot_13_decrypt(plaintext, ciphertext);
    // cout << plaintext << "\n";

    // rot_n_encrypt(13, plaintext, ciphertext);
    // cout << ciphertext << "\n";
    // // rot13(ciphertext, plaintext, MAX_TEXT_SIZE);
    // rot_n_decrypt(13, plaintext, ciphertext);
    // cout << plaintext << "\n";

    int map[94];
    for (int i = 0; i < 94; i++)
    {
        map[i] = i + 33;
        // cout << map[i] << "\n";
    }

    fisherYatesShuffling(map, 94);

    int pam[94];
    for (int i = 0; i < 94; i++)
    {
        pam[i] = indexOf(map, 94, i + 33) + 33;
    }

    for (int i = 0; i < 94; i++)
    {
        //map[i] = 93 - i + 33;
         cout << char(map[i]) << " ";
    }
    cout << "\n";

    for (int i = 0; i < 94; i++)
    {
        //map[i] = 93 - i + 33;
         cout << char(pam[i]) << " ";
    }
    cout << "\n";

    cout << "PT: " << plaintext << "\n";
    randomCipherEncrypt(map, plaintext, ciphertext);
    cout << "CT: " << ciphertext << "\n";
    randomCipherDecrypt(map, plaintext, ciphertext);
    cout << "PT: " << plaintext << "\n";
    randomCipherEncrypt(map, plaintext, ciphertext);
    cout << "CT: " << ciphertext << "\n";
    randomCipherEncrypt(pam, ciphertext, plaintext);
    cout << "PT: " << plaintext << "\n";

    return 0;
}

void fisherYatesShuffling(int *arr, int n)
{
//Copy pasted with thnaks from https://www.sanfoundry.com/cpp-program-implement-fisher-yates-algorithm-array-shuffling/
    int a[n];
    int ind[n];
    for (int i = 0; i < n; i++)
    ind[i] = 0;
    int index;

    for (int i = 0; i < n; i++)
    {
        do
        {
            index = rand() % n;
        }
        while (ind[index] != 0);

        ind[index] = 1;
        a[i] = *(arr + index);
    }
    for (int i = 0; i < n; i++)
    {
        arr[i] = a[i];
        // cout << a[i] << " ";
    }
}
