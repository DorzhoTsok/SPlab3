//Напишите  программу, в  которой  создается  двумерный  числовой  массив  и  для этого массива вычисляется сумма квадратов его элементов.

#include <iostream>

using namespace std;

int main()
{
    int n;
    cout << "Vvedite razmer:";
    cin >> n;
    int** array = new int* [n];
    for (size_t i = 0; i < n; i++)
    {
        array[i] = new int[n];
        for (size_t j = 0; j < n; j++)
        {
            array[i][j] = i + j;
            cout << array[i][j] << ' ';
        }
        cout << endl;
    }

    int sum = 0;
    _asm {
        mov esi, array
        mov edi, 0

        mov eax, 0
        po_strokam:
            mov ebx, 0
            po_stolbcam:
                poluchaem_element:
                mov ecx, [esi + eax * 4]
                mov ecx, [ecx + ebx * 4]
                vozvodim_v_kvadrat:
                imul ecx, ecx
                add edi, ecx
        
            add ebx, 1
            cmp ebx, n
            jne po_stolbcam
        add eax, 1
        cmp eax, n
        jne po_strokam

        sohranyaem_summy:
        mov sum, edi
    };

    cout << "summa kvadratov: " << sum << endl;
}
