#include <iostream>
#include <thread>

using namespace std;

void imprimirImpares() {
    for (int i = 1; i <= 10; i += 2) {
        cout << "Impar: " << i << endl;
    }
}

void imprimirPares() {
    for (int i = 2; i <= 10; i += 2) {
        cout << "Par: " << i << endl;
    }
}

int main() {
    thread hiloImpares(imprimirImpares);
    thread hiloPares(imprimirPares);

    hiloImpares.join();
    hiloPares.join();

    return 0;
}
