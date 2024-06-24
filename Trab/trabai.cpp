#include <cstring>
#include <fstream>
#include <iostream>

using namespace std;
const int MAX = 200; // quantidade m�xima de caracteres
const int N = 50;    // quantidade m�xima de personagens. Tamanho do vetor.

struct Anime {
    char nome[MAX], genero[MAX];
    float nota;
    int ano_lancamento;
};

void substring(char buff[MAX], char aux[MAX], int &i, char delim) {
  int k = 0;
  while (buff[i] != delim) {
    aux[k] = buff[i];
    i++;
    k++;
  }
  aux[k] = '\0';
  i++;
}

void carrega_registro(char buff[MAX], Anime &h) {
  char aux[MAX];
  int i = 0;

  substring(buff, aux, i, ',');
  strcpy(h.nome, aux);

  substring(buff, aux, i, ',');
  h.ano_lancamento = atoi(aux);

  substring(buff, aux, i, ',');
  strcpy(h.genero, aux);

  substring(buff, aux, i, '\0');
  h.nota = atof(aux);
}

void imprime_personagens(Anime p[], int tam) {
  for (int i = 0; i < tam; i++) {
    cout << i + 1 << " - " << p[i].nome << endl;
    cout << "Lançamento: " << p[i].ano_lancamento << endl;
    cout << "Gêneros: " << p[i].genero << endl;
    cout << "Nota: " << p[i].nota << endl;


  }
}
//aqui começa as funçoes do meniu;


void opcao1() {
    cout << "Você escolheu a opcao 1.\n";//pascoa, coloca o nome das opições.
    // Código específico da opção 1
}

void opcao2() {
    cout << "Você escolheu a opcao 2.\n";
    // Código específico da opção 2
}

void opcao3() {
    cout << "Você escolheu a opcao 3.\n";
    // Código específico da opção 3
}

void mostrarMenu() {
    cout << "Menu:\n";
    cout << "1. Opcao 1\n";
    cout << "2. Opcao 2\n";
    cout << "3. Opcao 3\n";
    cout << "4. Sair\n";
    cout << "Escolha uma opcao: ";
}

int main() {

    int escolha;
    bool continuar = true;


    while (continuar) {
        mostrarMenu();
        cin >> escolha;

        if (escolha == 1) {
            opcao1();
        } else if (escolha == 2) {
            opcao2();
        } else if (escolha == 3) {
            opcao3();
        } else if (escolha == 4) {
            continuar = false;
            cout << "Saindo.\n";
        } else {
            cout << "Opção inválida. Tente novamente.\n";
        }
    }

  Anime p[N];

  setlocale(LC_ALL, "Portuguese");

  ifstream fin("Animes.csv");
  if (fin.is_open()) {
    int j = 0;
    char buff[MAX];

    fin.getline(buff, MAX); // ignora a primeira linha do arquivo (cabe�alho)
    while (fin.getline(buff, MAX)) {
      carrega_registro(buff, p[j]);
      j++;
    }

    imprime_personagens(p, j);

  } else
    cout << "Não conseguiu abrir o arquivo de entrada!";

  return 0;
}
