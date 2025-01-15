SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = '+08:00';


--
-- Database: `healthcare`
--

CREATE TABLE `users` (
    `user_id` INT AUTO_INCREMENT,
    `name` VARCHAR(250) NOT NULL,
    `email` VARCHAR(250) NOT NULL,
    `password` VARCHAR(250) NOT NULL,
    `gender` VARCHAR(50) NOT NULL,
    `contact_info` VARCHAR(50) NOT NULL,
    `role` VARCHAR(50) NOT NULL,
    PRIMARY KEY (`user_id`)
);

CREATE TABLE `appoitments` (
    `appoiment_id` INT AUTO_INCREMENT,
    `datetime` DATETIME,
    `user_id` INT NOT NULL,
    `fees` INT NOT NULL
    `doctor_id` INT NOT NULL,
    PRIMARY KEY (`appoiment_id`),
    FOREIGN KEY (`user_id`) REFERENCES `users` (`user_id`)
);

CREATE TABLE `treatments` (
    `treatment_id` INT AUTO_INCREMENT, 
    `user_id` INT NOT NULL,
    `diagnose` VARCHAR(250) NOT NULL,
    PRIMARY KEY (`treatment_id`),
    FOREIGN KEY (`user_id`) REFERENCES `users` (`user_id`)
);

CREATE TABLE `medicine` (
    `medicine_id` INT AUTO_INCREMENT,
    `diagnose` VARCHAR(250) NOT NULL, 
    `medicines` VARCHAR(250) NOT NULL, 
    `description` VARCHAR(250) NOT NULL,
    PRIMARY KEY (`medicine_id`)
);

