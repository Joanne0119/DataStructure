#include <iostream>
using namespace std;    

// Factorial

int Fac(int n){
    if(n == 0) return 0;
    else if(n == 1) return 1;
    else {
        n = n*Fac(n-1);
        return n;
    }
}

//Fibonacci Number

int Fib(int n ){ //Recurisive
    if(n == 0) return 0;
    else if(n == 1) return 1;
    else {
        n = Fib(n-1) + Fib(n-2);
        return n;
    }
}
int Fibarr(int n){ //Interactive
    int arrayFib[n];
    arrayFib[0] = 0;
    arrayFib[1] = 1;

    if (n == 0) return arrayFib[0];
    else if(n == 1) return arrayFib[1];
    else{
        for (int i = 2; i <= n; i++){
            arrayFib[i] = arrayFib[i - 1] + arrayFib[i - 2];
        }
        return arrayFib[n];
    }

}

//Binomail Coefficient
//C(n,m) = C(n-1, m) + C(n-1, m-1)
int Bin(int n, int m){ //Recursive
    if (m == n || m == 0) return 1;
    else {
        return Bin(n-1, m)+Bin(n-1, m-1);
    }
}


int Binarr(int n, int m){
    int arrBin[n + 1][m + 1];
    
    for (int  i = 0; i <= n; i++)
    {
        for(int j = 0; j <= min(i,m); j++){ 
            //取min(i,m)是因為超過m的部分不需要計算了，但如果放j <= i 的話也可以，只是他也把超過m的地方也算進去了
            if(i == j) arrBin[i][j] = 1;
            else if(j == 0) arrBin[i][j] = 1;
            else {
                arrBin[i][j] = arrBin[i-1][j] + arrBin[i-1][j-1];
                cout << "arr[" << i << "][" << j << "]" << arrBin[i][j] << " ";
            }
        }
    }
    return arrBin[n][m];
}

//Gretest Common Divisor
//A mod B
int GCD(int a, int b){ 
    if( a % b == 0) return b;
    else GCD(b, a % b);
}


void Hanoi(char from, char to, char aux, int n){
    int tem;
    if (n == 1){ //ending condition
        cout << "move disk 1 from " << from << " to " << to << endl;
    }
    else {
        Hanoi(from, aux, to, n-1);
        cout << "move disk " << n << " from " << from << " to " << to << endl;
        Hanoi(aux, to, from, n-1);
    }
}

//Permutations
//每個字元輪流當頭，再接剩下的data
void Per(char *list, int i, int n){                                                 //Per(['A', 'B', 'C'], 0, 2)        //Per(['A', 'B', 'C'], 1, 2)        //Per(['A', 'B', 'C'], 2, 2)                                                Per(['A', 'C', 'B'], 2, 2)
    //gen list[i] to list[n]
    int j, temp;
    if(i == n) {                                                                    //i = 0 != n = 2                    //i = 1 != n = 2                    //i = 2 == n = 2                                                            //i = 2 == n = 2
        cout << "myList ";
        for(j = 0; j <= n; j++){
            cout << list[j];                                                                                                                                //ABC                                                                       //ACB
        }
        cout << endl;
    }
    else { //i < n
        for(j = i; j <= n; j++){                                                    //j = 0, i = 0                      //j = 1, i = 1                                                           -->   //j = 2, i = 1
            temp= list[i]; list[i] = list[j]; list[j] = temp; //list[j]當頭（輪流當） //A swap A                          //B swap B                                                               |      //B swap C 
            cout << "change " << list[i] << " head to " << list[j] << endl;                                                                                                                  //  |      Per(['A', 'C', 'B'], 2, 2)
            Per(list, i + 1, n);                               //後接(i+1)到n的data  //Per(['A', 'B', 'C'], 1, 2)       //Per(['A', 'B', 'C'], 2, 2)                                              |     
            temp = list[i]; list[i] = list[j]; list[j] = temp;//還原成原本List內容                                                                                                                 |    
            cout << "reverse " << list[i] << " head to " << list[j] << endl;                                                               //|     //<--- B swap B (j = 1, i = 1)                |                                <--- C swap B
        }                                                                                                                                  //|                                                   |
    }                                                                                                                                      // ----------------------------------------------------
}


int main(){
    int n = 5;
    int m = 3;
    char from = 'A';
    char to = 'B';
    char aux = 'C';
    char arr[3] = {'A', 'B', 'C'};
    cout << "The Factorial of " << n << " is " << Fac(n) << endl;
    cout << "The Fibonacci number of " << n << " is " << Fib(n) << endl;
    cout << "The DP Fibonacci number of " << n << " is " << Fibarr(n) << endl;
    cout << "The Binomail Coefficient of " << n << " and " << m << " is " << Bin(n, m) << endl;
    cout << "The DP Binomail Coefficient of " << n << " and " << m << " is " << Binarr(n, m) << endl;
    cout << "The GCD of " << n << " and " << m << " is " << GCD(n, m) << endl;
    cout << "The " << m << " disks of Hanoi from " << from << " to " << aux << " are " <<endl; Hanoi(from, to, aux, m);
    cout << "The Permutations of "; for(int i = 0; i < m; i++)  cout << arr[i]; cout << " are " << endl; Per(arr, 0, 2);
    return 0;
}