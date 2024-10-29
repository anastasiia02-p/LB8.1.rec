#include <iostream>
#include <cstring>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;

// ������� ��������� ������� ������� � ����� "BASIC"
int CountBASICChars(const char* str, int i, int* count) {
    if (str[i] == '\0')  // ����� �����
        return 0;

    char symbols[] = "BASIC";
    for (int j = 0; j < strlen(symbols); j++) {
        if (str[i] == symbols[j]) {
            count[j]++;
            break;
        }
    }
    return CountBASICChars(str, i + 1, count);
}

// ������� ��� ����� "BASIC" �� "Delphi"
char* ReplaceBASIC(char* dest, const char* str, char* t, int i) {
    if (str[i] == '\0')  // ����� �����
        return dest;

    if (strncmp(&str[i], "BASIC", 5) == 0) {  // ���� �������� "BASIC"
        strcat(t, "Delphi");
        return ReplaceBASIC(dest, str, t + strlen("Delphi"), i + 5);
    }
    else {
        *t++ = str[i++];
        *t = '\0';
        return ReplaceBASIC(dest, str, t, i);
    }
}

int main() {
    char str[101];
    cout << "Enter string:" << endl;
    cin.getline(str, 100);

    // �������� 1: ϳ�������� ������� ������� � "BASIC"
    int count[5] = { 0 };  // ��� B, A, S, I, C
    CountBASICChars(str, 0, count);

    cout << "Symbol counts from 'BASIC':" << endl;
    cout << "B: " << count[0] << endl;
    cout << "A: " << count[1] << endl;
    cout << "S: " << count[2] << endl;
    cout << "I: " << count[3] << endl;
    cout << "C: " << count[4] << endl;

    // �������� 2: ����� "BASIC" �� "Delphi"
    char* dest = new char[151];
    dest[0] = '\0';
    char* modifiedStr = ReplaceBASIC(dest, str, dest, 0);

    cout << "Modified string: " << modifiedStr << endl;

    delete[] dest;
    return 0;
}
