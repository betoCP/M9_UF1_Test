#include <iostream>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    int x = 0;
    for (int i = 0; i < 2; ++i) {
        if (fork() == 0) {  // Proceso hijo
            x += i + 1;  // Modifica su copia de x
            std::cout << "Proceso hijo " << i << ": x = " << x << std::endl;
            return 0;
        }
    }
    // Proceso padre
    wait(NULL);  // Espera a los hijos
    wait(NULL);
    std::cout << "Proceso padre: x = " << x << std::endl;
    return 0;
}