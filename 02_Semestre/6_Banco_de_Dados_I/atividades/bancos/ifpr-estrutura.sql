-- Banco de origem: IFPR
-- Estrutura obtida com SHOW CREATE TABLE IFPR.alunos em 18/10/2026.
-- Este arquivo contém somente a estrutura; não inclui os registros.

CREATE TABLE `alunos` (
  `id_aluno` int NOT NULL AUTO_INCREMENT,
  `nome` varchar(100) NOT NULL,
  `data_nascimento` date NOT NULL,
  `cidade` varchar(60) NOT NULL,
  `estado` char(2) NOT NULL,
  `curso` varchar(100) NOT NULL,
  `periodo` tinyint unsigned NOT NULL,
  `nota` decimal(4,2) NOT NULL,
  `matriculado` tinyint(1) NOT NULL,
  `data_matricula` date NOT NULL,
  PRIMARY KEY (`id_aluno`)
) ENGINE=InnoDB AUTO_INCREMENT=16 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
