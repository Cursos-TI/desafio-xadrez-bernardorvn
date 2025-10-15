#include <stdio.h>

// ==================================================
// Função recursiva para mover a Torre
// ==================================================
void moverTorre(int casasRestantes, int casaAtual) {
    if (casasRestantes == 0) {
        return; // Caso base: nenhuma casa restante
    }

    printf("Casa %d: Direita\n", casaAtual);
    moverTorre(casasRestantes - 1, casaAtual + 1); // Chamada recursiva
}

// ==================================================
// Função recursiva para mover o Bispo (com loops aninhados)
// ==================================================
void moverBispo(int movimentoVertical, int movimentoHorizontal) {
    if (movimentoVertical == 0) {
        return; // Caso base: terminou o movimento
    }

    // Loop externo controla o movimento vertical ("Cima")
    for (int v = 1; v <= movimentoVertical; v++) {
        // Loop interno controla o movimento horizontal ("Direita")
        for (int h = 1; h <= movimentoHorizontal; h++) {
            printf("Casa (%d,%d): Cima, Direita\n", v, h);
        }
    }

    moverBispo(movimentoVertical - 1, movimentoHorizontal - 1); // Recursão
}

// ==================================================
// Função recursiva para mover a Rainha
// ==================================================
void moverRainha(int casasRestantes, int casaAtual) {
    if (casasRestantes == 0) {
        return; // Caso base: fim do movimento
    }

    printf("Casa %d: Esquerda\n", casaAtual);
    moverRainha(casasRestantes - 1, casaAtual + 1); // Chamada recursiva
}

// ==================================================
// Função para mover o Cavalo com loops aninhados
// ==================================================
void moverCavalo() {
    printf("=== Movimento do Cavalo ===\n");

    // O Cavalo se move em "L": 2 casas para cima e 1 para a direita
    // Vamos usar loops aninhados e controlar o fluxo com break/continue
    for (int cima = 1; cima <= 2; cima++) {  // Movimento vertical
        for (int direita = 1; direita <= 1; direita++) { // Movimento horizontal
            if (cima == 1 && direita == 1) {
                printf("Movimento inicial: Cima\n");
                continue; // Pula o restante e vai para a próxima iteração
            }

            if (cima == 2 && direita == 1) {
                printf("Movimento final: Cima, Cima, Direita\n");
                break; // Sai do loop interno após o último movimento
            }

            printf("Casa %d,%d: Cima, Direita\n", cima, direita);
        }
    }
}

// ==================================================
// Função principal
// ==================================================
int main() {
    // Número de casas para cada peça (definido no código)
    int casasTorre = 5;
    int casasRainha = 8;
    int movimentoBispo = 5;

    // ======= Torre =======
    printf("=== Movimento da Torre ===\n");
    moverTorre(casasTorre, 1);

    // ======= Bispo =======
    printf("\n=== Movimento do Bispo ===\n");
    moverBispo(movimentoBispo, movimentoBispo);

    // ======= Rainha =======
    printf("\n=== Movimento da Rainha ===\n");
    moverRainha(casasRainha, 1);

    // ======= Cavalo =======
    printf("\n");
    moverCavalo();

    printf("\nSimulação concluída!\n");
    return 0;
}
