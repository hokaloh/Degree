SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = '+08:00';


--
-- Database: `lab_5b`
--

CREATE TABLE users (
    matric VARCHAR (10) PRIMARY KEY,
    name VARCHAR (100) NOT NULL,
    password VARCHAR (255) NOT NULL,
    role VARCHAR (10) NOT NULL
);