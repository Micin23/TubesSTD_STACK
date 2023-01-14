#include "stack.h"

int main()
{
    Stack S;
    infotype x, postfix, hasil, infix;
    createStack(S);
    int n;

    cout << "------------------------" << endl;
    cout << "Masukan jumlah data: ";
    cin >> n;
    for(int i = 0; i < n; i++){
        cout << "------------------------" << endl;
        cout << "Masukkan Nilai Postfix: ";
        cin >> postfix;
        hasil = postfixToInfix(postfix, S);
        cout << "Nilai Postfix to Infix: " << hasil <<endl;
        cout << "------------------------" << endl;
        cout << "Masukan Nilai Infix   : ";
        cin >> infix;
        cout << "Nilai Infix memiliki ()/[]/{} yang valid?" << endl;
        cout << "True(1)|False(0)      : " << Validasi(infix) << endl;
    }
    return 0;
}
