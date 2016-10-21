ECA419 - Laboratório de Robótica <img src="https://www.unifei.edu.br/files/LogoEFEI_small.jpg" align="right" alt="unifei">
===========

Engenharia de Controle e Automação
----------------------------------

Por: [Adriano Henrique Rossette Leite](http://lattes.cnpq.br/0344999175185128), Bs.;
     [Audeliano Wolian Li](http://lattes.cnpq.br/0868980336504303), Ms.;
     [Guilherme Sousa Bastos](http://lattes.cnpq.br/1508015681115848), Dr.

Este repositório contém o material necessário para a realização do laboratório de Robótica (ECA419) oferecido no curso de graduação de Engenharia de Controle e Automação (ECA) da Universidade Federal de Itajubá (UNIFEI).

O principal objetivo desta disciplina é introduzir o *framework* ROS aos alunos matriculados.

***


### Sumário
[Introdução](#introduction) &nbsp;
[Instruções](#instructions) &nbsp;
[Aulas](#classes) : [(1) Introdução ao ROS](#class-01), [(2) Introdução ao QtCreator](#class-02), [(3) Pacotes e Nós no ROS](#class-03), [(4) Mensagens, Tópicos e Serviços no ROS](#class-04), [(5) Nós Publicadores e Nós Assinantes](#class-05), [(6) ROS e Lógica Fuzzy](#class-05) &nbsp;
[Exercícios](#exercicies) : [(1) Relembrando POO em C++](#exercicie-01), [(2) Modelando sistemas baseados em ROS](#exercicie-02) &nbsp;
[Trabalhos](#homeworks) : [(1)](#homework-01), [(2)](#homework-02) &nbsp;


### <a name="introduction">Introdução</a>

***

### <a name="instructions">Instruções</a>

***

### <a name="classes">Aulas</a>

### <a name="class-01">Introdução ao ROS</a>
### <a name="class-02">Introdução ao QtCreator</a>
### <a name="class-03">Pacotes e Nós no ROS</a>
### <a name="class-04">Mensagens, Tópicos e Serviços no ROS</a>
### <a name="class-05">Nós Publicadores e Nós Assinantes no ROS</a>
### <a name="class-06">ROS e lógica Fuzzy</a>
Instalar e construir a biblioteca [fuzzylite](https://github.com/fuzzylite/fuzzylite) no diretório pessoal da Máquina Virtual (ou seja, @ /home/viki).

Instalar o simulador MobileSim na Máquina Virtual através do arquivo que foi disponibilizado neste repositório.

***

### <a name="exercicies">Exercícios</a>

### <a name="exercicie-01">Relembrando de POO em C++</a>
### <a name="exercicie-02">Modelando sistemas baseados em ROS</a>

***

### <a name="homeworks">Trabalhos</a>

### <a name="homework-01">--------</a>
### <a name="homework-02">--------</a>
1ª Tarefa: Fazer uma pesquisa de como converter sensor_msgs/PointCloud em sensor_msgs/Range

rostopic info /RosAria/pose
	Type: nav_msgs/Odometry

2ª Tarefa: Converter o nav_msgs/Odometry em geometry_msgs/Pose2D

3ª Tarefa: Criar um nó CONVERSOR que subscreva de /RosAria/sonar e /RosAria/pose, faça as devidas conversões e publique nos tópicos /RosAria/sonar_range e /RosAria/pose2D

4ª Tarefa: Criar um nó CONTROLADOR_DE_DESLOCAMENTO que faça o controle do movimento do robô conforme a presença de um obstáculo à frente do robô. Para tal deverá ser utilizado técnicas de controle (PID, etc) ou de inteligência artificial (Fuzzy, etc) ou outros. Fica a cargo do grupo decidir qual implementar.

5ª Tarefa: O robô ao atingir a distância mínima, deverá virar para o lado em que há obstáculos mais distantes.

6ª Tarefa: Criar duas mensagens customizadas deslocamento.msg e distancia.msg com campos:
	DESLOCAMENTO.MSG
	float64 x
	float64 y
	
	DISTANCIA.MSG
	float64 distancia_euclidiana
	deslocamento deslocamento_acumulado

7ª Tarefa: Publicar no tópico /RosAria/distancia_deslocamento a distância Euclidiana do pose inicial até o pose atual e o deslocamento acumulado no eixo x e y durante a execução da aplicação.

8ª Tarefa: A aplicação deverá rodar durante 3 min e após este tempo, deverá ser encerrada. OBS: criar como variável global para setar o tempo com maior facilidade.

***
