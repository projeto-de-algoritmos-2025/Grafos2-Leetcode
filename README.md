# Juiz Virtual (LeetCode)

**Número da Lista**: 2<br>
**Conteúdo da Disciplina**: Grafos 2 <br>

## Alunos
|Matrícula | Aluno |
| -- | -- |
| 22/2006178 | Thales Henrique Euflauzino dos Santos  |
| 22/2021924 | Víctor Hugo Lima Schmidt               |

## Sobre 
Para explorar o conteúdo do tópico de Grafos 2, a dupla escolheu dois exercícios na plataforma online [LeetCode](https://leetcode.com/): dois de nível difícil e dois de nível médio, para igualar o trabalho de cada um dos membros.


## Screenshots

### [1489. Find Critical and Pseudo-Critical Edges in Minimum Spanning Tree (Díficil)](https://leetcode.com/problems/find-critical-and-pseudo-critical-edges-in-minimum-spanning-tree/description/)

Modelei o problema como um grafo não direcionado em que cada aresta $u,v,w$ tem peso w; calculo primeiro o peso da MST padrão com Kruskal+DSU, depois para cada aresta faço dois testes: (1) pulo-a e, se a MST ficar mais cara ou desconexa, é crítica; (2) a incluo forçadamente antes de rodar Kruskal e, se ainda atingir o mesmo peso mínimo, é pseudo-crítica.


<img src="./assets/resp1489.jpg" style="width: 700px;">

### [2642. Design Graph With Shortest Path Calculator (Difícil)](https://leetcode.com/problems/design-graph-with-shortest-path-calculator/description/)

![Resp2642](./assets/resp2642.png)

Modelei o problema como um grafo dirigido onde cada aresta possui um custo. Usei Dijkstra com uma fila de prioridade para encontrar o caminho de menor custo entre dois nós, atualizando as distâncias apenas quando um caminho mais barato era encontrado. Essa abordagem é eficiente para grafos com pesos positivos e permite lidar com adições dinâmicas de arestas.

### [1631. Path With Minimum Effort (Média)](https://leetcode.com/problems/path-with-minimum-effort/description/)

![Resp1631](./assets/resp1631.png)

Modelei o problema como um grafo onde cada célula é um nó e arestas conectam células adjacentes com peso igual à diferença de altura. Usei Dijkstra com uma fila de prioridade para minimizar o maior peso (esforço) no caminho do topo esquerdo até o canto inferior direito, atualizando apenas se o novo esforço for menor que o registrado.

### Vídeo-Apresentação (Questões 2642 e 1631)
https://github.com/user-attachments/assets/c53ac5db-a792-4f41-bdbd-35c06535c70a

### Vídeo-Apresentação (Questão 1489)
https://github.com/user-attachments/assets/fa5943df-2a3f-4f18-b151-dfb33c388572



## Instalação 
**Linguagens**: C++<br>

## Uso 
Explique como usar seu projeto caso haja algum passo a passo após o comando de execução.

