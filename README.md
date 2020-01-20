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

2. Agora a biblioteca já é usável. Para importá-la, crie um programa `.py` na pasta principal e adicione ao início do programa 

```python3
from source import quadtree
```

3. Agora você tem acesso as funções `build()` e `view()`. A primeira recebe como argumento o **nome do arquivo a ser lido** e retorna na pasta *output/* os arquivos **distances.dat** com as distâncias entre os pontos de cada folha da quadtree e o **rects.dat**, com as coordenadas dos retângulos para visualização com o `view()`, que não recebe argumentos.

4. Os arquivos de entrada devem contar com duas colunas, a primeira sendo a coordenada em **x** e a segunda em **y** de cada ponto.  

O arquivo `exemplo.py` pode ser usado de referência. os arquivos *rede1* e *table.dat* são modelos de entrada. Experimente executá-lo com

```
python3 exemplo.py
```

# Licença

Este trabalho está licenciado sob a Licença Atribuição-NãoComercial-CompartilhaIgual 4.0 Internacional (BY-NC-SA 4.0 internacional) Creative Commons. Para visualizar uma cópia desta licença, visite http://creativecommons.org/licenses/by-nc-sa/4.0/.