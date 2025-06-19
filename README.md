# Mini Terminal HTTP

Este é um mini terminal em C++ que permite fazer requisições HTTP interativas diretamente pelo console, utilizando a biblioteca `libcurl`. É um projeto simples e didático para praticar consumo de APIs, entrada de dados e uso de bibliotecas externas com `vcpkg`.

---

## 🚀 Funcionalidades

* Leitura de URLs digitadas pelo usuário.
* Requisições HTTP GET usando `libcurl`.
* Exibição da resposta diretamente no terminal.
* Loop contínuo de entrada até o comando `sair`.

---

## 🛠️ Tecnologias utilizadas

* **C++ (C++20)**
* **libcurl** (via `vcpkg`)
* **vcpkg** como gerenciador de pacotes
* **CLion** (ou qualquer IDE/terminal com CMake)

---

## Como instalar e rodar

### 1. Clone o repositório

```bash
git clone https://github.com/pk-hue/mini-terminal-http.git
cd mini-terminal-http
```

### 2. Instale o `vcpkg` (se ainda não tiver)

```bash
git clone https://github.com/microsoft/vcpkg.git
cd vcpkg
./bootstrap-vcpkg.bat  # no Windows
```

Adicione o caminho do `vcpkg.cmake` na sua configuração do CMake.

### 3. Instale a libcurl

```bash
./vcpkg install curl
```

### 4. Compile o projeto

Se estiver usando CMake direto:

```bash
cmake -B build -DCMAKE_TOOLCHAIN_FILE=path/to/vcpkg/scripts/buildsystems/vcpkg.cmake
cmake --build build
```

> Substitua `path/to` pelo caminho real onde está seu `vcpkg`.

Se estiver usando CLion, adicione no `CMakeLists.txt`:

```cmake
find_package(CURL REQUIRED)
target_link_libraries(seu_projeto PRIVATE CURL::libcurl)
```

---

## Como usar

1. Execute o binário gerado.
2. Digite uma URL completa (ex: `https://jsonplaceholder.typicode.com/posts/1`).
3. Veja a resposta JSON ou HTML no terminal.
4. Digite `sair` para encerrar o programa.

---

## 📝 Exemplo de uso

```bash
====== Mini Terminal HTTP ======

URL > https://jsonplaceholder.typicode.com/posts/1
{
  "userId": 1,
  "id": 1,
  "title": "sunt aut facere repellat provident occaecati excepturi optio reprehenderit",
  "body": "quia et suscipit..."
}

URL > sair
```

---

## 📁 Estrutura básica do projeto

```
mini-terminal-http/
├── main.cpp
├── CMakeLists.txt
├── README.md
└── vcpkg_installed/ (criado automaticamente)
```

---

## ✨ Autor

Pedro ([@pk-hue](https://github.com/pk-hue))
Projeto desenvolvido com fins didáticos e aprendizado de C++ moderno.
