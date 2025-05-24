# S.O. 2025.1 - Atividade 03 - Compilação de código dentro de docker fedora

## Informações gerais

- **Objetivo do repositório**: Repositório para atividade avaliativa dos alunos
- **Assunto**: Implementação de tarefas (processos)
- **Público alvo**: alunos da disciplina de SO (Sistemas Operacionais) do curso de TADS (Superior em Tecnologia em Análise e Desenvolvimento de Sistemas) no CNAT-IFRN (Instituto Federal de Educação, Ciência e Tecnologia do Rio Grande do Norte - Campus Natal-Central).
- disciplina: **SO** [Sistemas Operacionais](https://github.com/sistemas-operacionais/)
- professor: [Leonardo A. Minora](https://github.com/leonardo-minora)
- aluno: FIXME

## Sumário

1. Tutorial introdutório de Dockerfile
2. Prática

---

## Parte 1. Tutotirla introdutório de Dockerfile

**Tutorial Introdutório a Dockerfile** by [deepseek](https://chat.deepseek.com/).

Neste tutorial, você aprenderá os conceitos básicos de **Dockerfile**, como criar uma imagem personalizada e executar um container com mapeamento de volumes.  

---

### 1.1. O que é um Dockerfile?
Um **Dockerfile** é um arquivo de texto que contém instruções para construir uma imagem Docker. Essas instruções definem:  
- A **imagem base** (ex: `fedora`, `ubuntu`, `python`).  
- **Comandos** a serem executados (instalação de pacotes, configurações).  
- **Diretórios de trabalho** e **variáveis de ambiente**.  
- **Mapeamento de portas** e **volumes**.  

---

### 1.2. Criando Nosso Primeiro Dockerfile

#### 1.2.1. Crie um arquivo `Dockerfile`
Abra um editor de texto (VS Code, Notepad++, etc.) e cole o seguinte conteúdo:  

```dockerfile
# Define a imagem base (Fedora)
FROM fedora:latest

# Atualiza os pacotes e instala utilitários básicos
RUN dnf -y update && \
    dnf -y install findutils && \
    dnf -y install fish && \
    dnf clean all

# Cria um diretório para a aplicação
RUN mkdir -p /app

# Define o diretório de trabalho padrão
WORKDIR /app

# Comando padrão ao iniciar o container
CMD ["fish"]
```

#### 1.2.2: Entendendo as Instruções
- **`FROM`**: Define a imagem base (aqui, usamos Fedora).  
- **`RUN`**: Executa comandos dentro do container (atualizar pacotes, instalar programas).  
- **`WORKDIR`**: Define o diretório padrão onde comandos serão executados.  
- **`CMD`**: Define o comando padrão ao iniciar o container (`bash` abre um terminal interativo).  

---

### 1.3. Construindo a Imagem Docker

No terminal (PowerShell ou CMD), navegue até a pasta onde está o `Dockerfile` e execute:  

```bash
docker build -t minha-imagem-fedora .
```
- **`-t minha-imagem-fedora`**: Define um nome para a imagem.  
- **`.`**: Indica que o Dockerfile está no diretório atual.  

---

### 1.4. Executando o Container com Mapeamento de Volume

Para mapear uma pasta do Windows para dentro do container, use:  

#### 1.4.1. No PowerShell
```bash
docker run -it --rm -v ${PWD}:/app minha-imagem-fedora
```

#### 1.4.2. No CMD (Prompt de Comando)
```bash
docker run -it --rm -v %cd%:/app minha-imagem-fedora
```

#### 1.4.3. Explicação do Comando
- **`-it`**: Modo interativo (permite digitar comandos no terminal do container).  
- **`--rm`**: Remove o container automaticamente após sair.  
- **`-v ${PWD}:/app`**: Mapeia o diretório atual do Windows (`${PWD}` ou `%cd%`) para `/app` no container.  

---

### 1.5. Verificando o Funcionamento

Dentro do container, execute:  
```bash
ls
```
Você verá os arquivos do seu diretório Windows mapeados em `/app`.  

Para sair do container, digite:
```bash
exit
```

---

### 1.6. Próximos Passos
Agora que você já sabe criar um Dockerfile básico, pode:  
✅ **Instalar outras dependências** (ex: `RUN dnf install gcc`)  
✅ **Expor portas** (ex: `EXPOSE 80`) para aplicações web  
✅ **Copiar arquivos** (ex: `COPY . /app`)  
✅ **Definir variáveis de ambiente** (ex: `ENV VAR=valor`)  

---

### 1.7. Conclusão
Você aprendeu:  
✔ Como criar um **Dockerfile**  
✔ Como **construir uma imagem** Docker  
✔ Como **mapear pastas** do Windows para o container  
✔ Como **executar e interagir** com o container  



### 🔗 1.8. Recursos Úteis
- [Documentação Oficial do Dockerfile](https://docs.docker.com/engine/reference/builder/)  
- [Tutoriais Docker para Iniciantes](https://docker-curriculum.com)  


---


## Parte 2. Prática

### 2.1. Introdução
Nesta prática, você aprenderá a usar um **Dockerfile** para criar um ambiente isolado capaz de **compilar e executar código em C**. O objetivo é:  
- Criar uma imagem Docker com as ferramentas necessárias (`gcc`).  
- Mapear um diretório do host (Windows/Linux) para o container.  
- Compilar e executar um programa em C diretamente no container.  

**Pré-requisitos:**  
✔ Docker instalado ([Download Docker Desktop](https://www.docker.com/products/docker-desktop))  
✔ Editor de texto (VS Code, Sublime, etc.)  
✔ Conhecimento básico de C  

---

### 2.2. Desenvolvimento das Atividades

#### 2.2.1. Fork e indentificação do aluno

1. Fork desse repositório para seu pessoal (de estudo).
2. Modifique o README procurando por FIXME na linha 10 por seu nome (coloque link para sua conta github).
3. Realize as atividades abaixo.

#### 2.2.2. Preparando o Ambiente
1. Crie uma pasta no seu sistema (ex: `docker-c-practice`).  
2. Dentro dela, crie dois arquivos:  
   - `Dockerfile` (instruções para a imagem Docker).  
   - copie corretamente os códigos-fonte do [capítulo de implementação de tarefa do livro texto da disciplina](https://wiki.inf.ufpr.br/maziero/lib/exe/fetch.php?media=socm:socm-05.pdf)

#### 2.2.3. Conteúdo do `Dockerfile`

Veja tutorial acima e crie seu Dockerfile no mesmo diretório dos códigos-fonte

#### 2.2.4. Construindo a Imagem Docker

Veja tutorial acima e construa a sua imagem docker.

#### 2.2.5. Executando o Container

Veja tutorial acima e execute o tutorial.

Lembre:
1. instalar o `gcc`.
2. você esta no terminal `fish`, ele tentará te ajudar.
3. você esta no diretório `app` do conteiner que é uma referência para o diretório que está o Dockerfile e os códigos-fonte em c do Windows.

Para **compilar e executar** seus códigos-fontes.  
```bash
gcc nome_arquivo.c -o nome_executavel
```

---

### 2.3. Relatório da Prática (Template para Entregar)

**Lembre** que o relatório:
- deve estar no mesmo repositório, 
- deve ser em markdown, 
- deve conter imagens da tela capturada,
- apesar da atividade ser coletiva, relatório deve ser individual.

**Nome:** [Seu Nome]  
**Data:** [Data]  

### **1. Objetivo**  
[Descreva brevemente o objetivo da prática.]  

### **2. Passos Executados**  
- [Liste os comandos usados e suas funções.]  
- [Inclua prints (opcional).]  

### **3. Resultados Obtidos**  
- [Saída do programa em C.]  
- [Problemas enfrentados e soluções.]  

### **4. Conclusão**  
[Comente sobre a experiência e possíveis aplicações.]  
