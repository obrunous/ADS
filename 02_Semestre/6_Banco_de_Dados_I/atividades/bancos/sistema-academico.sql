-- MySQL dump 10.13  Distrib 8.0.36, for macos14 (x86_64)
--
-- Host: 127.0.0.1    Database: sistema_academico
-- ------------------------------------------------------
-- Server version	8.0.36

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!50503 SET NAMES utf8 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `CURSA`
--

DROP TABLE IF EXISTS `CURSA`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `CURSA` (
  `COD` int unsigned NOT NULL AUTO_INCREMENT,
  `COD_DISCENTE` int unsigned NOT NULL,
  `COD_DISCIPLINA` int unsigned NOT NULL,
  `ANO` year NOT NULL,
  PRIMARY KEY (`COD`),
  UNIQUE KEY `uq_cursa_discente_disciplina_ano` (`COD_DISCENTE`,`COD_DISCIPLINA`,`ANO`),
  KEY `fk_cursa_disciplina` (`COD_DISCIPLINA`),
  CONSTRAINT `fk_cursa_discente` FOREIGN KEY (`COD_DISCENTE`) REFERENCES `DISCENTE` (`COD`),
  CONSTRAINT `fk_cursa_disciplina` FOREIGN KEY (`COD_DISCIPLINA`) REFERENCES `DISCIPLINA` (`COD`)
) ENGINE=InnoDB AUTO_INCREMENT=6 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `CURSA`
--

LOCK TABLES `CURSA` WRITE;
/*!40000 ALTER TABLE `CURSA` DISABLE KEYS */;
INSERT INTO `CURSA` VALUES (1,1,1,2026),(2,2,2,2026),(3,3,3,2026),(4,4,4,2026),(5,5,5,2026);
/*!40000 ALTER TABLE `CURSA` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `DISCENTE`
--

DROP TABLE IF EXISTS `DISCENTE`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `DISCENTE` (
  `COD` int unsigned NOT NULL AUTO_INCREMENT,
  `MATRICULA` varchar(20) NOT NULL,
  `NOME` varchar(100) NOT NULL,
  `CPF` varchar(14) NOT NULL,
  `ENDERECO` varchar(200) DEFAULT NULL,
  `TELEFONE` varchar(20) DEFAULT NULL,
  `EMAIL` varchar(150) DEFAULT NULL,
  PRIMARY KEY (`COD`),
  UNIQUE KEY `MATRICULA` (`MATRICULA`)
) ENGINE=InnoDB AUTO_INCREMENT=6 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `DISCENTE`
--

LOCK TABLES `DISCENTE` WRITE;
/*!40000 ALTER TABLE `DISCENTE` DISABLE KEYS */;
INSERT INTO `DISCENTE` VALUES (1,'ESTUDO0701','Ana Exemplo','000.000.000-01','Rua Ficticia, 10','(00) 00000-0001','ana@example.com'),(2,'ESTUDO0702','Fabio Exemplo','000.000.000-02','Rua Ficticia, 20','(00) 00000-0002','fabio@example.com'),(3,'ESTUDO0703','Carla Exemplo','000.000.000-03','Rua Ficticia, 30','(00) 00000-0003','carla@example.com'),(4,'ESTUDO0704','Diego Exemplo','000.000.000-04','Rua Ficticia, 40','(00) 00000-0004','diego@example.com'),(5,'ESTUDO0705','Elisa Exemplo','000.000.000-05','Rua Ficticia, 50','(00) 00000-0005','elisa@example.com');
/*!40000 ALTER TABLE `DISCENTE` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `DISCIPLINA`
--

DROP TABLE IF EXISTS `DISCIPLINA`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `DISCIPLINA` (
  `COD` int unsigned NOT NULL AUTO_INCREMENT,
  `NOME` varchar(100) NOT NULL,
  `CH` smallint unsigned NOT NULL,
  `OBRIGATORIA` tinyint(1) NOT NULL,
  `VAGAS` smallint unsigned NOT NULL,
  PRIMARY KEY (`COD`)
) ENGINE=InnoDB AUTO_INCREMENT=6 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `DISCIPLINA`
--

LOCK TABLES `DISCIPLINA` WRITE;
/*!40000 ALTER TABLE `DISCIPLINA` DISABLE KEYS */;
INSERT INTO `DISCIPLINA` VALUES (1,'Banco de Dados I',60,1,40),(2,'Programacao I',80,1,40),(3,'Engenharia de Software',60,1,35),(4,'Redes de Computadores',60,1,35),(5,'Topicos em Tecnologia',40,0,25);
/*!40000 ALTER TABLE `DISCIPLINA` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2026-10-18 18:59:31
