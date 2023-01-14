#include "stack.h"
#include "string"

void createStack(Stack &S){
    S.Top = -1;
}

bool isEmpty(Stack S){
    if(S.Top == -1){
        return true;
    }else{
        return false;
    }
}

bool isFull(Stack S){
    if(S.Top == nMax){
        return true;
    }else{
        return false;
    }
}

void push(Stack &S, infotype x){
    if(!isFull(S)){
        S.Top = S.Top + 1;
        S.info[S.Top] = x;
    }
}

infotype pop(Stack &S){
    infotype x;

    x = S.info[S.Top];
    S.Top = S.Top - 1;
    return x;
}

void show(Stack S){
    for(int i = S.Top; i >= 0; i--){
        cout<<S.info[i]<<" ";
    }
    cout<<endl;
}

bool isOperand(char c){
    if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')){
        return true;
    }else{
        return false;
    }
}
infotype postfixToInfix(infotype postfix, Stack &S){
    int len = postfix.length(); //mengukur isi string
    int i; //deklarasi i
    for (i = 0; i < len; i++) {
        if(isOperand(postfix[i])){ //memanggil isoperand untuk mengecek isi dari postfix[i]
            push(S, infotype(1, postfix[i])); //push nilai S dan infotype yg bernilai (1, postfix[i]) kedalam stack
        }else{
            infotype op1, op2, x; //buat op1,op2 dan x untung menampung nilai

            //op1 dan op2 mengambil data dari top stack
            op1 = S.info[S.Top];
            pop(S); //op1 di pop
            cout << "op1                   : " << op1 << endl;
            cout << "operator              : " << postfix[i] << endl;
            op2 = S.info[S.Top];
            pop(S); //op2 di pop
            cout << "op2                   : " << op2 << endl;
            x = "(" + op2 + postfix[i]+ op1 + ")"; //x merupakan hasil gabungan dari nilai op2 lalu postfix[i] lalu op1
            push(S, x); //setelah itu nilai x akan dipush
        }
    }
    return S.info[S.Top]; //hasil gabungan (postfix to infix)
}

bool Validasi(infotype Teks){
    Stack SValidasi;
    infotype karakter;
    createStack(SValidasi);
    int n = Teks.length();
    int i;
    bool cek = false;

    for(i = 0; i < n; i++){
        infotype Karakter = infotype(1, Teks[i]);
        if(Karakter == "(" || Karakter == "{" || Karakter == "[") //mengecek kurung buka 1 per satu
        {
            cek = true; //cek apakah kurung yg pertama kali dibaca adalah kurung buka atau tutup
            push(SValidasi, Karakter); //jika kurung buka maka kurung tersebut akan di push kedalam stack
        }else if(Karakter == ")"){ //mengecek kurung tutup )
            if(isEmpty(SValidasi) || SValidasi.info[SValidasi.Top] != "(") //mengecek kurung buka (
            {
                return false; //jika nilainya false || false maka false
            }
            karakter = pop(SValidasi); //jika nilainya false || true maka true,sehingga kurung () akan di pop
        }else if(Karakter == "}"){ //mengecek kurung tutup }
            if(isEmpty(SValidasi) || SValidasi.info[SValidasi.Top] != "{") //mengecek kurung buka {
            {
                return false; //jika nilainya false || false maka false
            }
            karakter = pop(SValidasi); //jika nilainya false || true maka true,sehingga kurung {} akan di pop
        }else if(Karakter == "]"){ //mengecek kurung tutup ]
            if(isEmpty(SValidasi) || SValidasi.info[SValidasi.Top] != "[") //mengecek kurung buka [
            {
                return false; //jika nilainya false || false maka false
            }
            karakter = pop(SValidasi); //jika nilainya false || true maka true,sehingga kurung [] akan di pop
        }
    }
    return isEmpty(SValidasi) && cek; //jika nilainya true && true maka true,artinya stack bernilai true
                                     //dan jika true maka nilai ekspresi kurung benar semua
                                     //dari segi tempat,arah,dan jumlah
};
