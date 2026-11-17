# Lista 09 de Estrutura de Dados I

Seis exercícios em C++ sobre filas FIFO (*First In, First Out*), com implementações baseadas em vetor, encadeamento e pilhas.

## Estrutura do projeto

```text
ed1-queue-list09-cpp/
├── include/
│   ├── Queue.h
│   ├── ArrayQueue.h
│   ├── LinkedQueue.h
│   ├── Stack.h
│   ├── ArrayStack.h
│   └── LinkedStack.h
├── src/
│   ├── Exer01_ImmediateShiftQueue.cpp
│   ├── Exer02_StackBasedQueue.cpp
│   ├── Exer03_OutputRestrictedDeque.cpp
│   ├── Exer04_PreservedCountQueue.cpp
│   ├── Exer05_MergeSortedQueues.cpp
│   └── Exer06_SplitEvenOddQueue.cpp
├── CMakeLists.txt
├── main.cpp
└── README.md
```

## Como compilar e executar

O projeto requer CMake 3.12 ou superior e um compilador com suporte a C++14.

### Pelo CLion

1. Abra a pasta `ed1-queue-list09-cpp` como projeto CMake.
2. Em **Run → Edit Configurations**, selecione `queue_list09` e informe o número da questão (de `1` a `6`) em **Program arguments**.
3. Execute o programa e digite a entrada no console, pressionando Enter após cada linha, inclusive as vazias.

### Pelo terminal

Na pasta do projeto, rode os comandos abaixo no PowerShell. O último comando executa a questão 1.

```powershell
cmake -S . -B build
cmake --build build --config Debug
.\build\queue_list09.exe 1
```

Se o gerador criar uma subpasta por configuração, como no Visual Studio, use `.\build\Debug\queue_list09.exe 1`. Em Linux ou macOS, com um gerador de configuração única, use `./build/queue_list09 1`.

## Questões e exemplos

### 1. Fila estática com deslocamento imediato

A primeira linha contém os valores da fila. A segunda contém a quantidade de remoções. A saída mostra os valores removidos e, na linha seguinte, os que sobraram.

**Entrada**

```text
10 20 30 40 50
2
```

**Saída**

```text
10 20
30 40 50
```

### 2. Fila com duas pilhas

Em uma linha, valores positivos inserem elementos, `-1` remove o primeiro e `-2` consulta o primeiro. A saída contém os resultados das remoções e consultas.

**Entrada**

```text
1 2 -2 -1 3 -2
```

**Saída**

```text
1 1 2
```

### 3. Fila com remoção nas duas extremidades

A primeira linha contém os valores da fila. Na segunda, `F` remove do início e `B` remove do fim. A saída segue a ordem das remoções.

**Entrada**

```text
10 20 30 40 50
F B F
```

**Saída**

```text
10 50 20
```

### 4. Contagem com preservação da fila

A primeira linha contém os valores da fila. A segunda contém o valor procurado. O programa imprime a contagem após restaurar a ordem original da fila.

**Entrada**

```text
1 3 2 3 5 3 7
3
```

**Saída**

```text
3
```

### 5. Intercalação de filas ordenadas

Informe uma fila por linha, em ordem não decrescente. As linhas podem estar vazias. O programa transfere os nós das duas filas para uma fila ordenada e imprime o resultado.

**Entrada**

```text
1 3 5 7
2 4 6 8
```

**Saída**

```text
1 2 3 4 5 6 7 8
```

### 6. Separação estável entre pares e ímpares

Informe todos os valores em uma linha. A saída contém os pares na primeira linha e os ímpares na segunda, na ordem original de cada grupo. Um grupo vazio gera uma linha em branco.

**Entrada**

```text
12 7 9 14 2 5 8
```

**Saída**

```text
12 14 2 8
7 9 5
```
