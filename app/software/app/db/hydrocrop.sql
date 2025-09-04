-- phpMyAdmin SQL Dump
-- version 4.9.5
-- https://www.phpmyadmin.net/
--
-- Host: 127.0.0.1:3306
-- Generation Time: Oct 03, 2021 at 11:44 PM
-- Server version: 10.4.21-MariaDB-cll-lve
-- PHP Version: 7.2.34

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET AUTOCOMMIT = 0;
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `u959710636_hycrocrop`
--

-- --------------------------------------------------------

--
-- Table structure for table `data`
--

CREATE TABLE `data` (
  `data_id` int(11) NOT NULL,
  `data_date` timestamp NOT NULL DEFAULT current_timestamp(),
  `data_temp` float(4,2) NOT NULL,
  `data_hum` int(3) NOT NULL,
  `data_device_sn` varchar(10) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Dumping data for table `data`
--

INSERT INTO `data` (`data_id`, `data_date`, `data_temp`, `data_hum`, `data_device_sn`) VALUES
(1, '2021-09-27 21:47:35', 2.00, 98, '191010'),
(2, '2021-09-27 21:47:55', 1.00, 59, '191010'),
(3, '2021-09-27 21:49:45', 2.00, 38, '191010'),
(4, '2021-09-29 00:09:37', 0.00, 90, '191010');

-- --------------------------------------------------------

--
-- Table structure for table `devices`
--

CREATE TABLE `devices` (
  `device_id` int(7) UNSIGNED NOT NULL,
  `device_user_id` int(7) DEFAULT NULL,
  `device_date` timestamp NULL DEFAULT current_timestamp(),
  `device_alias` varchar(50) DEFAULT '',
  `device_sn` int(7) DEFAULT NULL,
  `device_topic` varchar(50) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Dumping data for table `devices`
--

INSERT INTO `devices` (`device_id`, `device_user_id`, `device_date`, `device_alias`, `device_sn`, `device_topic`) VALUES
(1, 1, '2021-03-03 16:35:45', 'Pecera A', 191007, '3xK4hWptRC'),
(9, 5, '2021-05-20 17:32:49', 'LABs', 191009, 'KCS9DGHeGH'),
(13, 2, '2021-09-03 01:28:44', 'Casa', 191010, 'nyxrGLy9Sr'),
(14, 6, '2021-09-03 02:08:59', 'Test', 111, 'WZT3JwbCHB'),
(15, 2, '2021-09-08 00:51:19', 'Mollar', 191011, 'mkAYCDThjB');

-- --------------------------------------------------------

--
-- Stand-in structure for view `devices_full`
-- (See below for the actual view)
--
CREATE TABLE `devices_full` (
`data_id` int(11)
,`data_date` timestamp
,`data_temp` float(4,2)
,`data_hum` int(3)
,`data_device_sn` varchar(10)
,`device_id` int(7) unsigned
);

-- --------------------------------------------------------

--
-- Table structure for table `users`
--

CREATE TABLE `users` (
  `user_id` int(7) NOT NULL,
  `fb_user` varchar(100) DEFAULT NULL,
  `user_date` timestamp NOT NULL DEFAULT current_timestamp(),
  `user_name` varchar(50) NOT NULL,
  `user_email` varchar(50) NOT NULL,
  `user_password` varchar(60) NOT NULL,
  `user_image` varchar(200) NOT NULL DEFAULT 'https://cdn1.iconfinder.com/data/icons/avatars-vol-2/140/_robocop-512.png',
  `user_selected_device` int(7) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Dumping data for table `users`
--

INSERT INTO `users` (`user_id`, `fb_user`, `user_date`, `user_name`, `user_email`, `user_password`, `user_image`, `user_selected_device`) VALUES
(1, NULL, '2021-03-03 16:24:57', 'Martin Frith', 'overlemonsoft@gmail.com', 'b99d456223d9a1c2ff7d023caded23fda384c5cd', 'https://cdn1.iconfinder.com/data/icons/avatars-vol-2/140/_robocop-512.png', NULL),
(2, NULL, '2021-03-03 16:32:30', 'Fulanito', 'demo@demo.com', 'ea7addf05e61754962268a1f44d4f33079249326', 'https://hydrocrop.net/app/images/Cosme.png', 13),
(4, NULL, '2021-04-25 00:14:47', 'Alfredo Rodolfo Fernandez', 'alfred34894@gmail.com', 'a90b5c30b4a02099676d1d49a08b7788c2125faf', 'https://cdn1.iconfinder.com/data/icons/avatars-vol-2/140/_robocop-512.png', NULL),
(5, NULL, '2021-05-20 17:06:05', 'FMG', 'fernando.m.gambino@gmail.com', 'a9f9cc0b46b69c9e60bbd6e25423d46a0af42837', 'https://hydrocrop.net/app/images/RUSTY-S19-HOR-OP3-1024x724-1.jpg', 9),
(6, NULL, '2021-09-03 02:07:26', 'Test', 'test@test', '7c222fb2927d828af22f592134e8932480637c0d', 'https://cdn1.iconfinder.com/data/icons/avatars-vol-2/140/_robocop-512.png', 14),
(7, NULL, '2021-09-03 02:18:13', 'CostaRica', 'admin@iotcostarica.ml', '8b45bb7616f8239acaf1e31c585f141d251fba0b', 'https://cdn1.iconfinder.com/data/icons/avatars-vol-2/140/_robocop-512.png', NULL);

-- --------------------------------------------------------

--
-- Structure for view `devices_full`
--
DROP TABLE IF EXISTS `devices_full`;

CREATE ALGORITHM=UNDEFINED DEFINER=`mysqlhostapi2`@`localhost` SQL SECURITY DEFINER VIEW `devices_full`  AS  select `data`.`data_id` AS `data_id`,`data`.`data_date` AS `data_date`,`data`.`data_temp` AS `data_temp`,`data`.`data_hum` AS `data_hum`,`data`.`data_device_sn` AS `data_device_sn`,`devices`.`device_id` AS `device_id` from (`data` join `devices`) where `devices`.`device_sn` = `data`.`data_device_sn` ;

--
-- Indexes for dumped tables
--

--
-- Indexes for table `data`
--
ALTER TABLE `data`
  ADD PRIMARY KEY (`data_id`);

--
-- Indexes for table `devices`
--
ALTER TABLE `devices`
  ADD PRIMARY KEY (`device_id`);

--
-- Indexes for table `users`
--
ALTER TABLE `users`
  ADD PRIMARY KEY (`user_id`);

--
-- AUTO_INCREMENT for dumped tables
--

--
-- AUTO_INCREMENT for table `data`
--
ALTER TABLE `data`
  MODIFY `data_id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=5;

--
-- AUTO_INCREMENT for table `devices`
--
ALTER TABLE `devices`
  MODIFY `device_id` int(7) UNSIGNED NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=16;

--
-- AUTO_INCREMENT for table `users`
--
ALTER TABLE `users`
  MODIFY `user_id` int(7) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=8;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
