# Quadtree
Quadtree genérica para uso geral feita em C++

## Requisitos
- Compilador de C++ GCC
- Bibliotecas Numpy e Matplotlib

## Modo de usar
1. Para compilar o código, entre na pasta *source*, abra o terminal e digite 

```
make
```

2. Agora a biblioteca já é usável. Para importá-la, crie um arquivo `.py` na pasta principal e adicione ao início do programa 

```python3
from source import quadtree
```

3. Agora você tem acesso as funções `build()` e `view()`. A primeira recebe como argumento o **nome do arquivo a ser lido** e retorna na pasta *output/* os arquivos **distances.dat** com as distâncias entre os pontos de cada folha da quadtree e o **rects.dat**, com as coordenadas dos retângulos para visualização com o `view()`, que não recebe argumentos.

4. Os arquivos de entrada devem contar com duas colunas, a primeira sendo a coordenada em **x** e a segunda em **y** de cada ponto.  

O arquivo `exemplo.py` pode ser usado de referência. Os arquivos *rede1* e *table.dat* são modelos de entrada. Experimente executá-lo com

```
python3 exemplo.py
```

### Arquivos de entrada

Os arquivos de entrada devem possuir um dos seguintes formato:

**(a)**  Duas colunas delimitadas por `espaço` ou `TAB` (`\t`)

![](./source/img/not_labeled.png)

**(b)** Três colunas delimitadas por `espaço` ou `TAB` (`\t`). As duas primeiras referentes às coordenadas **x** e **y** e a terceira ao "rótulo" do ponto (caso tenham dois ou mais grupos distintos).

![](./source/img/labeled.png)

### Funções

```python3
quadtree.build(file, labels=0)
```

Recebe como primeiro parâmetro obrigatório o nome do arquivo de entrada (descrito acima) e opcional o parâmetro `labels`, indicando se o arquivo de entrada possui (`labels=1`) ou não (`labels=0`) rótulos. Se deixado em branco assume `labels=0`.

```python3
quadtree.view()
```

É uma função para leitura do arquivo gerado **rects.dat** e visualização da Quadtree. Pode ser alterado de acordo com as preferências e necessidades sem nenhum prejuízo no processo principal.

### Arquivos de saída

**(a) distances.dat** é a saída príncipal. Conta com as coordenandas de cada ponto a distância entre eles, dois a dois, dentro das folhas da Quardtree. Pode ou não também contar com os rótulos dos pontos, dependendo do arquivo de entrada.

![](./source/img/dists.png)

**(b) rects.dat** é um arquivo gerado com os vértices superior-esquerdo e inferior-direito de cada quadrante da quadtree.

# Licença

Este trabalho está licenciado sob a Licença Atribuição-NãoComercial-CompartilhaIgual 4.0 Internacional (BY-NC-SA 4.0 internacional) Creative Commons. Para visualizar uma cópia desta licença, visite http://creativecommons.org/licenses/by-nc-sa/4.0/.