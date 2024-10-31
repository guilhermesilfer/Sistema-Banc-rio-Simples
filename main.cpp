#include <iostream>
#include <string>
using namespace std;

class Cliente {
  private:
    string nome;
    string cpf;
  public:
    // construtor padrão para inicializar nome e cpf
    Cliente() {
      this->nome = "";
      this->cpf = "";
    }

    // construtor para inicializar nome e cpf
    Cliente(string nome, string cpf) {
      this->nome = nome;
      this->cpf = cpf;
    }

    // getter para coletar o nome
    string getNome() {
      return this->nome;
    }

    // getter para coletar o cpf
    string getCpf() {
      return this->cpf;
    }
};

class ContaBancaria {
  private:
    int numero;
    double saldo;
    Cliente titular;
  public:
    // construtor para inicializar numero, titular e saldo como 0 por padrão
    ContaBancaria(int numero, Cliente titular) {
      this->numero = numero;
      this->titular = titular;
      this->saldo = 0.0;
    }

    // construtor para incializar numero, titular e opcionalmente o saldo
    ContaBancaria(int numero, Cliente titular, double saldo) {
      this->numero = numero;
      this->titular = titular;
      this->saldo = saldo;
    }

    // método para depositar um valor na conta
    void depositar(double valor) {
      this->saldo = saldo + valor;
    }

    // método para sacar um valor da conta
    void sacar(double valor) {
      if (this->saldo >= valor)
        this->saldo -= valor;
    }

    // método para transferir dinheiro para outra conta
    void transferir(double valor, ContaBancaria &destino) {
      if (this->saldo >= valor)
        this->saldo -= valor;
        destino.saldo += valor;
        cout << "Transferido: R$ " << valor << " da conta " << this->numero << " para a conta " << destino.numero << endl;
    }

    // método para transferir dinheiro igualmente entre duas contas
    void transferir(double valor, ContaBancaria &destino1, ContaBancaria &destino2) {
      if (this->saldo >= valor)
        this->saldo -= valor;
        int valor_metade = valor/2.0;
        destino1.saldo += valor_metade;
        destino2.saldo += valor_metade;
        cout << "Transferido: R$ " << valor_metade << " para cada conta (" << destino1.numero << " e " << destino2.numero << ") da conta " << this->numero << endl;
    }

    // exibe o saldo da conta
    void exibirSaldo() {
      cout << "Saldo atual da conta " << this->numero << " : R$ " << this->saldo << endl;
    }

    // exibe as informações do titular
    void exibirInformacoes() {
      cout << "Titular: " << titular.getNome() << ", CPF: " << titular.getCpf() << endl;
      cout << "Número da Conta: " << this->numero << ", Saldo: R$ " << this->saldo << endl;
    }
};

int main() {
  // Criação dos clientes
  Cliente cliente1("Ana", "111.111.111-11");
  Cliente cliente2("Bruno", "222.222.222-22");
  Cliente cliente3("Carla", "333.333.333-33");

  // Criação das contas bancárias com saldos iniciais
  ContaBancaria conta1(1001, cliente1, 1000.0);
  ContaBancaria conta2(1002, cliente2);
  ContaBancaria conta3(1003, cliente3);

  // Exibe o saldo inicial da conta de Ana
  conta1.exibirSaldo();

  // Ana transfere R$200 para Bruno
  conta1.transferir(200.0, conta2);

  // Ana transfere R$300 divididos entre Bruno e Carla
  conta1.transferir(300.0, conta2, conta3);

  // Exibição dos saldos finais
  cout << endl;
  conta1.exibirInformacoes();
  conta2.exibirInformacoes();
  conta3.exibirInformacoes();

  return 0;
}

