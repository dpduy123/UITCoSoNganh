-- MySQL dump 10.13  Distrib 5.7.24, for osx10.9 (x86_64)
--
-- Host: localhost    Database: congty
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
-- Table structure for table `dean`
--

DROP TABLE IF EXISTS `dean`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `dean` (
  `TENDA` varchar(50) NOT NULL,
  `MADA` tinyint NOT NULL,
  `DIADIEM_DA` varchar(50) DEFAULT NULL,
  `PHONG` tinyint DEFAULT NULL,
  PRIMARY KEY (`MADA`),
  KEY `DEAN-PHG_idx` (`PHONG`),
  CONSTRAINT `DEAN-PHG` FOREIGN KEY (`PHONG`) REFERENCES `phongban` (`MAPHG`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb3;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `dean`
--

LOCK TABLES `dean` WRITE;
/*!40000 ALTER TABLE `dean` DISABLE KEYS */;
INSERT INTO `dean` VALUES ('San pham X',1,'Vung Tau',5),('San pham Y',2,'Nha Trang',5),('San pham Z',3,'TPHCM',5),('Tin hoc hoa',10,'Ha noi',4),('Cap quang',20,'TPHCM',1),('Dao tao',30,'Ha noi',4);
/*!40000 ALTER TABLE `dean` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `diadiem_phg`
--

DROP TABLE IF EXISTS `diadiem_phg`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `diadiem_phg` (
  `MAPHG` tinyint NOT NULL,
  `DIADIEM` varchar(45) NOT NULL,
  PRIMARY KEY (`MAPHG`,`DIADIEM`),
  CONSTRAINT `DIADIEM_PHG` FOREIGN KEY (`MAPHG`) REFERENCES `phongban` (`MAPHG`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb3;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `diadiem_phg`
--

LOCK TABLES `diadiem_phg` WRITE;
/*!40000 ALTER TABLE `diadiem_phg` DISABLE KEYS */;
INSERT INTO `diadiem_phg` VALUES (1,'TPHCM'),(4,'Ha noi'),(5,'Ha noi'),(5,'TPHCM'),(5,'Vung Tau');
/*!40000 ALTER TABLE `diadiem_phg` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `nhanvien`
--

DROP TABLE IF EXISTS `nhanvien`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `nhanvien` (
  `HONV` char(9) NOT NULL,
  `TENLOT` varchar(30) DEFAULT NULL,
  `TENNV` varchar(30) NOT NULL,
  `MANV` char(9) NOT NULL,
  `NGAYSINH` date DEFAULT NULL,
  `DCHI` varchar(60) DEFAULT NULL,
  `PHAI` char(3) DEFAULT NULL,
  `LUONG` decimal(7,2) DEFAULT NULL,
  `MA_NQL` char(9) DEFAULT NULL,
  `PHG` tinyint DEFAULT NULL,
  PRIMARY KEY (`MANV`),
  KEY `NV-PHG_idx` (`PHG`),
  KEY `NV-NV_idx` (`MA_NQL`),
  CONSTRAINT `NV-NV` FOREIGN KEY (`MA_NQL`) REFERENCES `nhanvien` (`MANV`),
  CONSTRAINT `NV-PHG` FOREIGN KEY (`PHG`) REFERENCES `phongban` (`MAPHG`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb3;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `nhanvien`
--

LOCK TABLES `nhanvien` WRITE;
/*!40000 ALTER TABLE `nhanvien` DISABLE KEYS */;
INSERT INTO `nhanvien` VALUES ('Dinh','Ba','Thu','123456789','1980-04-17','731 Tran Hung Dao, Q1,TPHCM','Nam',30000.00,'333445555',5),('Nguyen','Thanh','Trung','333445555','1981-04-20','638 Nguyen Van Cu, Q5,TPHCM','Nam',40000.00,'888665555',5),('Tran','Thanh','Tam','453453453','1984-08-27','543 Mai Thi Luu, Q1,TPHCM','Nam',25000.00,'333445555',5),('Nguyen','Manh','Hung','666884444','1982-09-15','975 Ba Ria, Vung Tau','Nam',38000.00,'333445555',5),('Vuong','Ngoc','Quyen','888665555','1986-10-10','450 Trung Vuong, Ha Noi','Nu',55000.00,NULL,1),('Le','Thi','Hoang','987654321','1979-06-20','291 Ho Van Hue, QPN, TPHCM','Nu',43000.00,'888665555',4),('Tran','Hong','Quang','987987987','1985-04-29','980 Le Hong Phong, Q10, TPHCM','Nam',25000.00,'987654321',4),('Bui','Thuy','Vu','999887777','1980-07-19','332 Nguyen Thai Hoc, Q1,TPHCM','Nu',25000.00,'987654321',4);
/*!40000 ALTER TABLE `nhanvien` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `phancong`
--

DROP TABLE IF EXISTS `phancong`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `phancong` (
  `MA_NVIEN` char(9) NOT NULL,
  `SODA` tinyint NOT NULL,
  `THOIGIAN` float(4,2) NOT NULL,
  PRIMARY KEY (`MA_NVIEN`,`SODA`),
  KEY `PHANCONG_DEAN_idx` (`SODA`),
  CONSTRAINT `PHANCONG_DEAN` FOREIGN KEY (`SODA`) REFERENCES `dean` (`MADA`),
  CONSTRAINT `PHANCONG_NVIEN` FOREIGN KEY (`MA_NVIEN`) REFERENCES `nhanvien` (`MANV`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb3;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `phancong`
--

LOCK TABLES `phancong` WRITE;
/*!40000 ALTER TABLE `phancong` DISABLE KEYS */;
INSERT INTO `phancong` VALUES ('123456789',1,32.50),('123456789',2,7.50),('333445555',3,10.00),('333445555',10,10.00),('333445555',20,10.00),('453453453',1,20.00),('453453453',2,20.00),('666884444',3,40.00),('888665555',20,10.00),('987654321',20,15.00),('987654321',30,20.00),('987987987',10,35.00),('987987987',30,5.00),('999887777',10,10.00),('999887777',30,30.00);
/*!40000 ALTER TABLE `phancong` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `phongban`
--

DROP TABLE IF EXISTS `phongban`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `phongban` (
  `TENPHG` varchar(30) NOT NULL,
  `MAPHG` tinyint NOT NULL,
  `TRPHG` char(9) DEFAULT NULL,
  `NGAY_NHAN_CHUC` date DEFAULT NULL,
  PRIMARY KEY (`MAPHG`),
  KEY `PHG-NV_idx` (`TRPHG`),
  CONSTRAINT `PHG-NV` FOREIGN KEY (`TRPHG`) REFERENCES `nhanvien` (`MANV`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb3;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `phongban`
--

LOCK TABLES `phongban` WRITE;
/*!40000 ALTER TABLE `phongban` DISABLE KEYS */;
INSERT INTO `phongban` VALUES ('Quan ly',1,'888665555','2012-07-19'),('Dieu hanh',4,'987987987','2015-02-19'),('Nghien cuu',5,'333445555','2016-06-18');
/*!40000 ALTER TABLE `phongban` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `thannhan`
--

DROP TABLE IF EXISTS `thannhan`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `thannhan` (
  `MA_NVIEN` char(9) NOT NULL,
  `TENTN` varchar(30) NOT NULL,
  `PHAI` char(3) NOT NULL,
  `NGAYSINH` date DEFAULT NULL,
  `QUANHE` varchar(30) DEFAULT NULL,
  PRIMARY KEY (`TENTN`,`MA_NVIEN`),
  KEY `THANNHAN-MANV_idx` (`MA_NVIEN`),
  CONSTRAINT `THANNHAN-MANV` FOREIGN KEY (`MA_NVIEN`) REFERENCES `nhanvien` (`MANV`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb3;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `thannhan`
--

LOCK TABLES `thannhan` WRITE;
/*!40000 ALTER TABLE `thannhan` DISABLE KEYS */;
INSERT INTO `thannhan` VALUES ('123456789','Chau','Nu','2009-07-13','Con gai'),('987654321','Dang','Nam','1979-08-21','Chong'),('333445555','Duong','Nu','1980-04-29','Vo'),('123456789','Duy','Nam','2008-08-21','Con trai'),('333445555','Khang','Nam','2005-05-28','Con trai'),('123456789','Phuong','Nu','1983-06-28','Vo'),('333445555','Thanh','Nu','2002-04-17','Con gai');
/*!40000 ALTER TABLE `thannhan` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2024-10-09  9:23:46
