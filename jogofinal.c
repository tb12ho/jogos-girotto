#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <locale.h>


//   PROTOTIPOS - avisa ao compilador que essas funcoes existem

int lerNumero();
void jogoPerguntas();
void jogoCobraCaixa();
void exibirEstado(int furia[], int ativa[]);
void verificarDestruicao(int furia[], int ativa[]);
int verificarFimDeJogo(int ativa[]);
void atacar(int furia[], int ativa[], int jogador);
void dividir(int furia[], int ativa[], int jogador);
void jogoGousmasWar();


//   MENU PRINCIPAL

int main() {
    setlocale(LC_ALL, "Portuguese");
    srand(time(NULL));

    int opcao;

    do {
        printf("  +--------------------------------------+\n");
        printf("  |          MENU DE MINIJOGOS           |\n");
        printf("  +--------------------------------------+\n\n");
        printf("  1 - Perguntas e Respostas\n");
        printf("  2 - Cobra na Caixa\n");
        printf("  3 - Gousmas War\n");
        printf("  4 - Sair\n\n");
        printf("  Escolha uma op��o: ");

        // repete ate receber uma opcao valida
        while (1) {
            if (scanf("%d", &opcao) != 1) {
                while (getchar() != '\n');
                printf("  Digite apenas numeros! Escolha de 1 a 4: ");
                continue;
            }
            if (opcao >= 1 && opcao <= 4)
                break;
            printf("  Opcao invalida! Escolha de 1 a 4: ");
        }

        system("cls");

        if (opcao == 1) jogoPerguntas();
        else if (opcao == 2) jogoCobraCaixa();
        else if (opcao == 3) jogoGousmasWar();
        else if (opcao == 4) printf("\n  Ate logo!\n\n");

        if (opcao != 4) system("cls");

    } while (opcao != 4);

    return 0;
}


//   FUNCAO AUXILIAR - le um numero e impede digitar letras

int lerNumero() {
    int num;
    while (1) {
        if (scanf("%d", &num) != 1) {
            printf("Entrada invalida! Digite apenas numeros.\n");
            while (getchar() != '\n');
        } else {
            while (getchar() != '\n');
            return num;
        }
    }
}


//   JOGO 1 - PERGUNTAS E RESPOSTAS

void jogoPerguntas() {
    int resposta, dnv;
    char continuar;

    do {
        printf("  +--------------------------------------+\n");
        printf("  |         PERGUNTAS E RESPOSTAS        |\n");
        printf("  +--------------------------------------+\n\n");
        printf("  === DESCRICAO ===\n");
        printf("  Serao apresentadas 5 perguntas com 4 alternativas cada.\n");
        printf("  Digite o numero da alternativa correta!\n\n");
        printf("  Pressione Enter para continuar\n");
        scanf("%c", &continuar);
        system("cls");

        // pergunta 1
        printf("  +--------------------------------------+\n");
        printf("  |           PRIMEIRA PERGUNTA          |\n");
        printf("  +--------------------------------------+\n\n");
        printf("  Em Star Wars, qual e o nome da estacao espacial capaz de destruir planetas?\n");
        printf("  1 - Star Forge\n  2 - Eclipse\n  3 - Estrela da Morte\n  4 - Base Starkiller\n");
        printf("\n  Digite o numero da sua resposta: ");
        scanf("%d", &resposta);
        if (resposta == 3)
            printf("\n  RESPOSTA CORRETA! Pelo visto alguem assistiu Star Wars.\n\n");
        else if (resposta < 1 || resposta > 4)
            printf("\n  RESPOSTA INVALIDA! Resposta certa: Estrela da Morte\n\n");
        else
            printf("\n  RESPOSTA INCORRETA! Resposta certa: Estrela da Morte\n\n");
        printf("  Pressione qualquer letra para continuar: ");
        scanf(" %c", &continuar);
        system("cls");

        // pergunta 2
        printf("  +--------------------------------------+\n");
        printf("  |            SEGUNDA PERGUNTA          |\n");
        printf("  +--------------------------------------+\n\n");
        printf("  Segundo a creepypasta original, quem seria o Herobrine?\n");
        printf("  1 - O Notch\n  2 - Um NPC secreto da Mojang\n  3 - Um bug do servidor\n  4 - O suposto irmao falecido de Notch\n");
        printf("\n  Digite o numero da sua resposta: ");
        scanf("%d", &resposta);
        if (resposta == 4)
            printf("\n  RESPOSTA CORRETA! Epoca boa ne?\n\n");
        else if (resposta < 1 || resposta > 4)
            printf("\n  RESPOSTA INVALIDA! Resposta certa: O suposto irmao falecido de Notch\n\n");
        else
            printf("\n  RESPOSTA INCORRETA! Resposta certa: O suposto irmao falecido de Notch\n\n");
        printf("  Pressione qualquer letra para continuar: ");
        scanf(" %c", &continuar);
        system("cls");

        // pergunta 3
        printf("  +--------------------------------------+\n");
        printf("  |           TERCEIRA PERGUNTA          |\n");
        printf("  +--------------------------------------+\n\n");
        printf("  Sobre a serie Sandman, qual e o verdadeiro nome do personagem conhecido como Sonho?\n");
        printf("  1 - Somnium\n  2 - Morfeus\n  3 - Dream\n  4 - Azazel\n");
        printf("\n  Digite o numero da sua resposta: ");
        scanf("%d", &resposta);
        if (resposta == 2)
            printf("\n  RESPOSTA CORRETA! Serie muito boa!\n\n");
        else if (resposta < 1 || resposta > 4)
            printf("\n  RESPOSTA INVALIDA! Resposta certa: Morfeus\n\n");
        else
            printf("\n  RESPOSTA INCORRETA! Resposta certa: Morfeus\n\n");
        printf("  Pressione qualquer letra para continuar: ");
        scanf(" %c", &continuar);
        system("cls");

        // pergunta 4
        printf("  +--------------------------------------+\n");
        printf("  |           QUARTA PERGUNTA            |\n");
        printf("  +--------------------------------------+\n\n");
        printf("  Comendo determinado numero de bananas voce morre por radiacao, que numero e esse?\n");
        printf("  1 - 100000000\n  2 - 80000000\n  3 - meio bananao grosso\n  4 - 18000\n");
        printf("\n  Digite o numero da sua resposta: ");
        scanf("%d", &resposta);
        if (resposta == 2)
            printf("\n  RESPOSTA CORRETA! Temos um especialista em bananas aqui!\n\n");
        else if (resposta < 1 || resposta > 4)
            printf("\n  RESPOSTA INVALIDA! Resposta certa: 80000000\n\n");
        else
            printf("\n  RESPOSTA INCORRETA! Resposta certa: 80000000\n\n");
        printf("  Pressione qualquer letra para continuar: ");
        scanf(" %c", &continuar);
        system("cls");

        // pergunta 5
        printf("  +--------------------------------------+\n");
        printf("  |           QUINTA PERGUNTA            |\n");
        printf("  +--------------------------------------+\n\n");
        printf("  Qual personagem dos quadrinhos escolheu seu proprio ator nos cinemas?\n");
        printf("  1 - Homem Aranha\n  2 - Batman\n  3 - Nick Fury\n  4 - Superman\n");
        printf("\n  Digite o numero da sua resposta: ");
        scanf("%d", &resposta);
        if (resposta == 3)
            printf("\n  RESPOSTA CORRETA! Muito bem!!\n\n");
        else if (resposta < 1 || resposta > 4)
            printf("\n  RESPOSTA INVALIDA! Resposta certa: Nick Fury\n\n");
        else
            printf("\n  RESPOSTA INCORRETA! Resposta certa: Nick Fury\n\n");
        printf("  Pressione qualquer letra para continuar: ");
        scanf(" %c", &continuar);
        system("cls");

        printf("\n ** DESEJA JOGAR NOVAMENTE? **\n");
        printf("\n      1- SIM         2- NAO      \n");
        printf("Escolha: ");
        dnv = lerNumero();
        if (dnv != 2) system("cls");

    } while (dnv != 2);
}


//   JOGO 2 - COBRA NA CAIXA

void jogoCobraCaixa() {
    int escolha1, escolha2, jogadorAtual, caixa, cobra, botao, dnv;
    char nome1[50], nome2[50];

    do {
        int caixas[5] = {0};

        printf("Escolha um nome:\n");
        printf("1 - robertinho do grau\n2 - geremias\n3 - steave\n");
        printf("4 - olavo de carvalho\n5 - jalin rabei\n6 - ronaldinho gaucho\n7 - 20comer 70correr\n");

        // jogador 1 escolhe o nome
        while (1) {
            printf("\nJogador 1 escolha um numero: ");
            int v1 = lerNumero();
            if (v1 >= 1 && v1 <= 7) { escolha1 = v1; break; }
            else printf("Valor invalido!\n");
        }

        // jogador 2 escolhe o nome
        while (1) {
            printf("\nJogador 2 escolha um numero: ");
            int v2 = lerNumero();
            if (v2 >= 1 && v2 <= 7) { escolha2 = v2; break; }
            else printf("Valor invalido!\n");
        }

        // atribui o nome ao jogador 1
        switch (escolha1) {
            case 1: strcpy(nome1, "robertinho do grau"); break;
            case 2: strcpy(nome1, "geremias"); break;
            case 3: strcpy(nome1, "steave"); break;
            case 4: strcpy(nome1, "olavo de carvalho"); break;
            case 5: strcpy(nome1, "jalin rabei"); break;
            case 6: strcpy(nome1, "ronaldinho gaucho"); break;
            case 7: strcpy(nome1, "20comer 70correr"); break;
        }

        // atribui o nome ao jogador 2
        switch (escolha2) {
            case 1: strcpy(nome2, "robertinho do grau"); break;
            case 2: strcpy(nome2, "geremias"); break;
            case 3: strcpy(nome2, "steave"); break;
            case 4: strcpy(nome2, "olavo de carvalho"); break;
            case 5: strcpy(nome2, "jalin rabei"); break;
            case 6: strcpy(nome2, "ronaldinho gaucho"); break;
            case 7: strcpy(nome2, "20comer 70correr"); break;
        }

        printf("\nJogador 1 sera: %s\n", nome1);
        printf("Jogador 2 sera: %s\n", nome2);

        // sorteia quem comeca
        jogadorAtual = rand() % 2 + 1;
        printf("\n%s comeca!\n", (jogadorAtual == 1) ? nome1 : nome2);

        // sorteia posicao da cobra e do botao garantindo que sejam diferentes
        cobra = rand() % 5;
        botao = rand() % 5;
        while (botao == cobra) botao = rand() % 5;

        // loop principal do jogo
        while (1) {
            printf("\n%s escolha uma caixa (1-5): ", (jogadorAtual == 1) ? nome1 : nome2);
            caixa = lerNumero();

            if (caixa < 1 || caixa > 5) {
                printf("Escolha invalida!\n");
                continue;
            }

            int pos = caixa - 1;

            if (caixas[pos] == 1) {
                printf("Essa caixa ja foi escolhida!\n");
                continue;
            }

            caixas[pos] = 1;

            if (pos == cobra) {
                printf("Voce encontrou a COBRA!\n");
                printf("%s perdeu!\n", (jogadorAtual == 1) ? nome1 : nome2);
                break;
            } else if (pos == botao) {
                printf("Voce encontrou o BOTAO!\n");
                printf("%s venceu!\n", (jogadorAtual == 1) ? nome1 : nome2);
                break;
            } else {
                printf("Caixa vazia!\n");
            }

            // passa o turno para o outro jogador
            jogadorAtual = (jogadorAtual == 1) ? 2 : 1;
        }

        printf("\n\n ** DESEJA JOGAR NOVAMENTE? **\n");
        printf("1- SIM   2- NAO\n");
        dnv = lerNumero();
        if (dnv != 2) system("cls");

    } while (dnv != 2);
}


//   JOGO 3 - GOUSMAS WAR


// mostra na tela a furia e o estado de todas as gousmas
void exibirEstado(int furia[], int ativa[]) {
    printf("\n  +======================+\n");
    printf("  |   ESTADO DO JOGO     |\n");
    printf("  +======================+\n");

    if (ativa[0] == 1)
        printf("  Jogador 1 - Gousma 1: furia %d\n", furia[0]);
    else
        printf("  Jogador 1 - Gousma 1: DESTRUIDA\n");

    if (ativa[1] == 1)
        printf("  Jogador 1 - Gousma 2: furia %d\n", furia[1]);
    else
        printf("  Jogador 1 - Gousma 2: DESTRUIDA\n");

    printf("  ----------------------\n");

    if (ativa[2] == 1)
        printf("  Jogador 2 - Gousma 1: furia %d\n", furia[2]);
    else
        printf("  Jogador 2 - Gousma 1: DESTRUIDA\n");

    if (ativa[3] == 1)
        printf("  Jogador 2 - Gousma 2: furia %d\n", furia[3]);
    else
        printf("  Jogador 2 - Gousma 2: DESTRUIDA\n");

    printf("  +======================+\n\n");
}

// checa se alguma gousma passou de furia 5 e a marca como destruida
void verificarDestruicao(int furia[], int ativa[]) {
    if (furia[0] > 5 && ativa[0] == 1) {
        ativa[0] = 0;
        printf("  Gousma 1 do Jogador 1 foi DESTRUIDA!\n");
    }
    if (furia[1] > 5 && ativa[1] == 1) {
        ativa[1] = 0;
        printf("  Gousma 2 do Jogador 1 foi DESTRUIDA!\n");
    }
    if (furia[2] > 5 && ativa[2] == 1) {
        ativa[2] = 0;
        printf("  Gousma 1 do Jogador 2 foi DESTRUIDA!\n");
    }
    if (furia[3] > 5 && ativa[3] == 1) {
        ativa[3] = 0;
        printf("  Gousma 2 do Jogador 2 foi DESTRUIDA!\n");
    }
}

// verifica se algum jogador ficou sem gousmas
// retorna 1 se jogador 1 venceu, 2 se jogador 2 venceu, 0 se continua
int verificarFimDeJogo(int ativa[]) {
    if (ativa[0] == 0 && ativa[1] == 0) return 2;
    if (ativa[2] == 0 && ativa[3] == 0) return 1;
    return 0;
}

// jogador escolhe uma gousma sua para atacar uma gousma inimiga
int ataca(int furia[], int ativa[], int jogador) {
    int atacante, alvo;

    int minha_base, base_inimiga;
    if (jogador == 1) { minha_base = 0; base_inimiga = 2; }
    else              { minha_base = 2; base_inimiga = 0; }

    printf("  Escolha sua Gousma para atacar (1 ou 2): ");
    while (1) {
        atacante = lerNumero();

        if (atacante == 1 || atacante == 2) {
            if (ativa[minha_base + atacante - 1] == 1) break;
            else printf("  Essa Gousma esta destruida! Escolha outra: ");
        } else {
            printf("  Opcao invalida! Escolha 1 ou 2: ");
        }
    }

    printf("  Escolha a Gousma do adversario para atacar (1 ou 2): ");
    while (1) {
        alvo = lerNumero();

        if (alvo == 1 || alvo == 2) {
            if (ativa[base_inimiga + alvo - 1] == 1) break;
            else printf("  Essa Gousma esta destruida! Escolha outra: ");
        } else {
            printf("  Opcao invalida! Escolha 1 ou 2: ");
        }
    }

    int iA = minha_base + atacante - 1;
    int iAlvo = base_inimiga + alvo - 1;

    int antes = furia[iAlvo];
    furia[iAlvo] += furia[iA];

    printf("  Gousma %d atacou!\n", atacante);
    printf("  Furia: %d -> %d\n", antes, furia[iAlvo]);

    verificarDestruicao(furia, ativa);

    return 1; // jogada válida
} 

// jogador transfere parte da furia de uma gousma para a outra
int dividi(int furia[], int ativa[], int jogador) {
    int doadora, quantidade;

    int minha_base = (jogador == 1) ? 0 : 2;

    int podeDividir = 0;
    for(int i = 0; i < 2; i++){
        if(ativa[minha_base + i] == 1 && furia[minha_base + i] > 1){
            podeDividir = 1;
        }
    }

    if(!podeDividir){
        printf("  Nenhuma Gousma pode dividir!\n");
        return 0; // NÃO troca turno
    }

    printf("  Escolha a Gousma que vai transferir (1 ou 2): ");
    doadora = lerNumero();

    if(doadora != 1 && doadora != 2){
        printf("  Invalido!\n");
        return 0;
    }

    int iD = minha_base + doadora - 1;
    int iR = (doadora == 1) ? minha_base + 1 : minha_base;

    if(!ativa[iD] || furia[iD] <= 1){
        printf("  Nao pode usar essa!\n");
        return 0;
    }

    int max = furia[iD] - 1;

    printf("  Transferir (1-%d): ", max);
    quantidade = lerNumero();

    if(quantidade < 1 || quantidade > max){
        printf("  Valor invalido!\n");
        return 0;
    }

    if(!ativa[iR]){
        ativa[iR] = 1;
        printf("  Gousma reviveu!\n");
    }

    furia[iD] -= quantidade;
    furia[iR] += quantidade;

    verificarDestruicao(furia, ativa);

    return 1;
} 
// funcao principal do gousmas war, controla os turnos
void jogoGousmasWar() {
    int dnv;

    do {
        int furia[4] = {1, 1, 1, 1};
        int ativa[4] = {1, 1, 1, 1};
        int jogadorAtual = 1;
        int acao, limpar;

        // tela inicial
        do {
            printf("  +--------------------------------------+\n");
            printf("  |           GOUSMAS WAR                |\n");
            printf("  +--------------------------------------+\n\n");
            printf("  = PRESSIONE 1 PARA CONTINUAR = \n");

            limpar = lerNumero();

        } while (limpar != 1);

        system("cls");

        // loop principal
        while (1) {
    exibirEstado(furia, ativa);

    printf("  --- Turno do Jogador %d ---\n", jogadorAtual);
    printf("  1 - Atacar\n");
    printf("  2 - Dividir\n");
    printf("  Escolha: ");

    acao = lerNumero();

    int fezJogada = 0;

    if (acao == 1) {
        fezJogada = ataca(furia, ativa, jogadorAtual);
    }
    else if (acao == 2) {
        fezJogada = dividi(furia, ativa, jogadorAtual);
    }
    else {
        printf("  Opcao invalida!\n");
        continue;
    }

    int resultado = verificarFimDeJogo(ativa);
    if (resultado != 0) {
        exibirEstado(furia, ativa);
        printf("  *** JOGADOR %d VENCEU! ***\n\n", resultado);
        break;
    }

    //SÓ TROCA SE FOR VALIDO
    if (fezJogada)
        jogadorAtual = (jogadorAtual == 1) ? 2 : 1;
} 

        printf("\n ** DESEJA JOGAR NOVAMENTE? **\n");
        printf("\n      1- SIM         2- NAO      \n");
        printf("Escolha: ");

        while (1) {
            dnv = lerNumero();
            if (dnv == 1 || dnv == 2) break;
            printf("  Escolha 1 ou 2: ");
        }

        if (dnv != 2) system("cls");

    } while (dnv != 2);
} 

//teste