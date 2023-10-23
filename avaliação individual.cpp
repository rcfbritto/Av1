#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Paciente {
public:
    string cpf;
    string nome;
    string dataNascimento;

    Paciente(const string& cpf, const string& nome, const string& dataNascimento) 
        : cpf(cpf), nome(nome), dataNascimento(dataNascimento) {}
};

class Medico {
public:
    string crm;
    string nome;
    string especialidade;

    Medico(const string& crm, const string& nome, const string& especialidade)
        : crm(crm), nome(nome), especialidade(especialidade) {}
};

vector<Paciente> pacientes;
vector<Medico> medicos;

void incluirPaciente() {
    string cpf, nome, dataNascimento;
    cout << "CPF: ";
    cin >> cpf;
    cout << "Nome: ";
    cin.ignore();
    getline(cin, nome);
    cout << "Data de Nascimento: ";
    getline(cin, dataNascimento);
    Paciente novoPaciente(cpf, nome, dataNascimento);
    pacientes.push_back(novoPaciente);
    cout << "Paciente incluído com sucesso!" << endl;
}

void excluirPaciente() {
    string cpf;
    cout << "Informe o CPF do paciente a ser excluído: ";
    cin >> cpf;
    for (auto it = pacientes.begin(); it != pacientes.end(); ++it) {
        if (it->cpf == cpf) {
            pacientes.erase(it);
            cout << "Paciente excluído com sucesso!" << endl;
            return;
        }
    }
    cout << "Paciente não encontrado." << endl;
}

void alterarPaciente() {
    string cpf;
    cout << "Informe o CPF do paciente a ser alterado: ";
    cin >> cpf;
    for (auto &paciente : pacientes) {
        if (paciente.cpf == cpf) {
            cout << "Dados atuais do paciente:" << endl;
            cout << "Nome: " << paciente.nome << endl;
            cout << "Data de Nascimento: " << paciente.dataNascimento << endl;

            string opcao;
            cout << "Deseja alterar o nome? (S/N): ";
            cin >> opcao;
            if (opcao == "S" || opcao == "s") {
                cout << "Novo nome: ";
                cin.ignore();
                getline(cin, paciente.nome);
            }

            cout << "Deseja alterar a data de nascimento? (S/N): ";
            cin >> opcao;
            if (opcao == "S" || opcao == "s") {
                cout << "Nova data de Nascimento: ";
                cin.ignore();
                getline(cin, paciente.dataNascimento);
            }

            cout << "Dados do paciente alterados com sucesso!" << endl;
            return;
        }
    }
    cout << "Paciente não encontrado." << endl;
}

void listarPacientes() {
    cout << "Lista de Pacientes:" << endl;
    for (const Paciente &paciente : pacientes) {
        cout << "CPF: " << paciente.cpf << " - Nome: " << paciente.nome << " - Data de Nascimento: " << paciente.dataNascimento << endl;
    }
}

void localizarPaciente() {
    string cpf;
    cout << "Informe o CPF do paciente a ser localizado: ";
    cin >> cpf;
    for (const Paciente &paciente : pacientes) {
        if (paciente.cpf == cpf) {
            cout << "Paciente encontrado:" << endl;
            cout << "CPF: " << paciente.cpf << " - Nome: " << paciente.nome << " - Data de Nascimento: " << paciente.dataNascimento << endl;
            return;
        }
    }
    cout << "Paciente não encontrado." << endl;
}

void incluirMedico() {
    string crm, nome, especialidade;
    cout << "CRM: ";
    cin >> crm;
    cout << "Nome: ";
    cin.ignore();
    getline(cin, nome);
    cout << "Especialidade: ";
    getline(cin, especialidade);
    Medico novoMedico(crm, nome, especialidade);
    medicos.push_back(novoMedico);
    cout << "Médico incluído com sucesso!" << endl;
}

void excluirMedico() {
    string crm;
    cout << "Informe o CRM do médico a ser excluído: ";
    cin >> crm;
    for (auto it = medicos.begin(); it != medicos.end(); ++it) {
        if (it->crm == crm) {
            medicos.erase(it);
            cout << "Médico excluído com sucesso!" << endl;
            return;
        }
    }
    cout << "Médico não encontrado." << endl;
}

void alterarMedico() {
    string crm;
    cout << "Informe o CRM do médico a ser alterado: ";
    cin >> crm;
    for (auto &medico : medicos) {
        if (medico.crm == crm) {
            cout << "Dados atuais do médico:" << endl;
            cout << "Nome: " << medico.nome << endl;
            cout << "Especialidade: " << medico.especialidade << endl;

            string opcao;
            cout << "Deseja alterar o nome? (S/N): ";
            cin >> opcao;
            if (opcao == "S" || opcao == "s") {
                cout << "Novo nome: ";
                cin.ignore();
                getline(cin, medico.nome);
            }

            cout << "Deseja alterar a especialidade? (S/N): ";
            cin >> opcao;
            if (opcao == "S" || opcao == "s") {
                cout << "Nova especialidade: ";
                cin.ignore();
                getline(cin, medico.especialidade);
            }

            cout << "Dados do médico alterados com sucesso!" << endl;
            return;
        }
    }
    cout << "Médico não encontrado." << endl;
}

void listarMedicos() {
    cout << "Lista de Médicos:" << endl;
    for (const Medico &medico : medicos) {
        cout << "CRM: " << medico.crm << " - Nome: " << medico.nome << " - Especialidade: " << medico.especialidade << endl;
    }
}

void localizarMedico() {
    string crm;
    cout << "Informe o CRM do médico a ser localizado: ";
    cin >> crm;
    for (const Medico &medico : medicos) {
        if (medico.crm == crm) {
            cout << "Médico encontrado:" << endl;
            cout << "CRM: " << medico.crm << " - Nome: " << medico.nome << " - Especialidade: " << medico.especialidade << endl;
            return;
        }
    }
    cout << "Médico não encontrado." << endl;
}

int main() {
    int opcao;

    do {
        cout << "MENU PRINCIPAL" << endl;
        cout << "1. Gestão de Pacientes" << endl;
        cout << "2. Gestão de Médicos" << endl;
        cout << "0. Sair" << endl;
        cout << "Escolha uma opção: ";
        cin >> opcao;

        switch (opcao) {
            case 1:
                int opcaoPaciente;
                do {
                    cout << "MENU DE GESTÃO DE PACIENTES" << endl;
                    cout << "1. Incluir Paciente" << endl;
                    cout << "2. Excluir Paciente" << endl;
                    cout << "3. Alterar Paciente" << endl;
                    cout << "4. Listar Pacientes" << endl;
                    cout << "5. Localizar Paciente" << endl;
                    cout << "0. Voltar" << endl;
                    cout << "Escolha uma opção: ";
                    cin >> opcaoPaciente;

                    switch (opcaoPaciente) {
                        case 1:
                            incluirPaciente();
                            break;
                        case 2:
                            excluirPaciente();
                            break;
                        case 3:
                            alterarPaciente();
                            break;
                        case 4:
                            listarPacientes();
                            break;
                        case 5:
                            localizarPaciente();
                            break;
                        case 0:
                            break;
                        default:
                            cout << "Opção inválida." << endl;
                    }
                } while (opcaoPaciente != 0);
                break;

            case 2:
                int opcaoMedico;
                do {
                    cout << "MENU DE GESTÃO DE MÉDICOS" << endl;
                    cout << "1. Incluir Médico" << endl;
                    cout << "2. Excluir Médico" << endl;
                    cout << "3. Alterar Médico" << endl;
                    cout << "4. Listar Médicos" << endl;
                    cout << "5. Localizar Médico" << endl;
                    cout << "0. Voltar" << endl;
                    cout << "Escolha uma opção: ";
                    cin >> opcaoMedico;

                    switch (opcaoMedico) {
                        case 1:
                            incluirMedico();
                            break;
                        case 2:
                            excluirMedico();
                            break;
                        case 3:
                            alterarMedico();
                            break;
                        case 4:
                            listarMedicos();
                            break;
                        case 5:
                            localizarMedico();
                            break;
                        case 0:
                            break;
                        default:
                            cout << "Opção inválida." << endl;
                    }
                } while (opcaoMedico != 0);
                break;

            case 0:
                cout << "Encerrando o programa." << endl;
                break;

            default:
                cout << "Opção inválida." << endl;
        }
    } while (opcao != 0);

    return 0;
}
