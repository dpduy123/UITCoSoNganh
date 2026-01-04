-- MySQL dump 10.13  Distrib 5.7.24, for osx10.9 (x86_64)
--
-- Host: localhost    Database: banhang
-- ------------------------------------------------------
-- Server version	9.0.1

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `hanghoa`
--

DROP TABLE IF EXISTS `hanghoa`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `hanghoa` (
  `mahh` char(8) NOT NULL,
  `tenhh` varchar(50) NOT NULL,
  `hangsx` varchar(10) DEFAULT NULL,
  `TGBH` char(10) DEFAULT NULL,
  PRIMARY KEY (`mahh`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb3;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `hanghoa`
--

LOCK TABLES `hanghoa` WRITE;
/*!40000 ALTER TABLE `hanghoa` DISABLE KEYS */;
INSERT INTO `hanghoa` VALUES ('HH001','Mouse Quang','Logitech','1 nam'),('HH002','Removable Disk 256MB','Transcend','1 nam'),('HH003','HDD 80GB Baracuda','Seagate','2 nam'),('HH004','Camera SL_36','SlimPre.','3 nam'),('HH005','Ban phim ViewStar','Logitech','1 nam');
/*!40000 ALTER TABLE `hanghoa` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `hoadon`
--

DROP TABLE IF EXISTS `hoadon`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `hoadon` (
  `sohd` char(8) NOT NULL,
  `makh` char(8) NOT NULL,
  `ngayhd` datetime DEFAULT NULL,
  `mahh` char(8) NOT NULL,
  `sl` int NOT NULL,
  `dg` decimal(10,2) NOT NULL,
  `thanhtien` decimal(10,2) DEFAULT NULL,
  PRIMARY KEY (`sohd`,`mahh`),
  KEY `makh` (`makh`),
  KEY `mahh` (`mahh`),
  CONSTRAINT `hoadon_ibfk_1` FOREIGN KEY (`makh`) REFERENCES `khach` (`makh`),
  CONSTRAINT `hoadon_ibfk_2` FOREIGN KEY (`mahh`) REFERENCES `hanghoa` (`mahh`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb3;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `hoadon`
--

LOCK TABLES `hoadon` WRITE;
/*!40000 ALTER TABLE `hoadon` DISABLE KEYS */;
INSERT INTO `hoadon` VALUES ('HD005','KH003','2008-05-14 00:00:00','HH001',5,50000.00,100000.00),('HD006','KH001','2008-05-15 00:00:00','HH001',1,55000.00,55000.00),('HD006','KH001','2008-05-15 00:00:00','HH003',2,900000.00,180000.00),('HD007','KH003','2008-05-16 00:00:00','HH005',3,75000.00,225000.00);
/*!40000 ALTER TABLE `hoadon` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `khach`
--

DROP TABLE IF EXISTS `khach`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `khach` (
  `makh` char(8) NOT NULL,
  `tenkh` varchar(30) NOT NULL,
  `dchi` varchar(50) DEFAULT NULL,
  PRIMARY KEY (`makh`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb3;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `khach`
--

LOCK TABLES `khach` WRITE;
/*!40000 ALTER TABLE `khach` DISABLE KEYS */;
INSERT INTO `khach` VALUES ('KH001','Nam','123 Nguyen Dinh Chieu, Q.3, TpHCM'),('KH002','Nga',NULL),('KH003','Duy','50 Nguyen Tri Phuong Q.10 TpHCM');
/*!40000 ALTER TABLE `khach` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2024-10-08 21:39:56
