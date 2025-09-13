#include <iostream>
#include <filesystem>
#include <cstdlib> // Para system()

namespace fs = std::filesystem;

int main() {
    std::cout << "=== Configurando o aplicativo Yoka ===\n";

    // Criar pastas do projeto
    fs::path projectDir = "C:\\Yoka\\Projects";
    fs::path tempDir = "C:\\Yoka\\Temp";

    try {
        if (!fs::exists(projectDir)) {
            fs::create_directories(projectDir);
            std::cout << "Pasta de projetos criada: " << projectDir << "\n";
        }
        if (!fs::exists(tempDir)) {
            fs::create_directories(tempDir);
            std::cout << "Pasta temporária criada: " << tempDir << "\n";
        }
    } catch (fs::filesystem_error& e) {
        std::cerr << "Erro ao criar pastas: " << e.what() << "\n";
        return 1;
    }

    // Definir variável de ambiente
    _putenv("YOKA_HOME=C:\\Yoka");
    std::cout << "Variável de ambiente YOKA_HOME definida.\n";

    // Executar o aplicativo principal
    std::cout << "Abrindo o Yoka App...\n";
    system("start C:\\Yoka\\YokaApp.exe");

    std::cout << "Configuração concluída!\n";
    return 0;
}
