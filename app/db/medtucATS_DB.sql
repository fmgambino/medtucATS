-- phpMyAdmin SQL Dump
-- version 5.1.1
-- https://www.phpmyadmin.net/
--
-- Servidor: 127.0.0.1:3306
-- Tiempo de generación: 15-04-2024 a las 18:15:51
-- Versión del servidor: 10.11.7-MariaDB-cll-lve
-- Versión de PHP: 7.2.34

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Base de datos: `u133581750_DbDev`
--

DELIMITER $$
--
-- Procedimientos
--
CREATE DEFINER=`u133581750_dev`@`127.0.0.1` PROCEDURE `get_data` (IN `user_id` VARCHAR(255), IN `device_id` VARCHAR(255))  BEGIN
    SELECT 
        u133581750_DbDev.data.data_id AS data_id,
        u133581750_DbDev.data.data_date AS data_date,
        u133581750_DbDev.data.data_1 AS data_1,
        u133581750_DbDev.data.data_2 AS data_2,
        u133581750_DbDev.data.data_3 AS data_3,
        u133581750_DbDev.data.data_4 AS data_4,
        u133581750_DbDev.data.data_5 AS data_5,
        u133581750_DbDev.data.data_6 AS data_6,
        u133581750_DbDev.data.data_7 AS data_7,
        u133581750_DbDev.data.data_8 AS data_8,
        u133581750_DbDev.data.data_9 AS data_9,
        u133581750_DbDev.data.data_10 AS data_10,
        u133581750_DbDev.data.data_device_sn AS data_device_sn,
        u133581750_DbDev.devices.device_id AS device_id
    FROM
        u133581750_DbDev.data
    JOIN
        u133581750_DbDev.devices
    ON
        u133581750_DbDev.devices.device_sn = u133581750_DbDev.data.data_device_sn
    WHERE
        
        u133581750_DbDev.devices.device_id = device_id;
END$$

DELIMITER ;

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `data`
--

CREATE TABLE `data` (
  `data_id` int(11) NOT NULL,
  `data_date` timestamp NOT NULL DEFAULT current_timestamp(),
  `data_1` float NOT NULL,
  `data_2` int(11) NOT NULL,
  `data_3` int(11) NOT NULL,
  `data_4` float(4,2) NOT NULL,
  `data_5` float NOT NULL,
  `data_6` float NOT NULL,
  `data_7` float NOT NULL,
  `data_8` float NOT NULL,
  `data_9` float NOT NULL,
  `data_10` float NOT NULL,
  `data_device_sn` varchar(10) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb3 COLLATE=utf8mb3_general_ci;

--
-- Volcado de datos para la tabla `data`
--

INSERT INTO `data` (`data_id`, `data_date`, `data_1`, `data_2`, `data_3`, `data_4`, `data_5`, `data_6`, `data_7`, `data_8`, `data_9`, `data_10`, `data_device_sn`) VALUES
(1, '2021-12-05 02:37:14', 4095, 27, 64, 0.00, 60, 80, 95, 0, 0, 0, '797171'),
(2, '2021-12-05 02:54:10', 2926, 27, 64, 7.03, 0, 0, 0, 0, 0, 0, '797171'),
(3, '2021-12-05 02:54:15', 2926, 27, 64, 7.03, 0, 0, 0, 0, 0, 0, '797171'),
(4, '2021-12-05 02:54:25', 2926, 27, 64, 7.03, 0, 0, 0, 0, 0, 0, '797171'),
(5, '2021-12-05 02:54:30', 2926, 27, 64, 7.03, 0, 0, 0, 0, 0, 0, '797171'),
(6, '2021-12-05 02:54:35', 2926, 27, 64, 7.03, 0, 0, 0, 0, 0, 0, '797171'),
(7, '2021-12-05 02:54:45', 2926, 27, 64, 7.03, 0, 0, 0, 0, 0, 0, '797171'),
(8, '2021-12-05 02:54:50', 2926, 27, 64, 7.03, 0, 0, 0, 0, 0, 0, '797171'),
(9, '2021-12-05 02:54:55', 2926, 27, 40, 5.03, 0, 0, 0, 0, 0, 0, '797171'),
(10, '2021-12-05 02:55:00', 2926, 34, 64, 7.03, 0, 0, 0, 0, 0, 0, '797171'),
(11, '2021-12-05 02:55:05', 2926, 27, 64, 7.03, 0, 0, 0, 0, 0, 0, '797171'),
(12, '2021-12-05 02:55:10', 2926, 27, 64, 7.03, 0, 0, 0, 0, 0, 0, '797171'),
(13, '2021-12-05 03:02:05', 2907, 27, 80, 7.03, 50, 0, 0, 0, 0, 0, '797171'),
(14, '2024-04-14 20:41:05', 100, 100, 100, 99.99, 100, 100, 100, 100, 100, 100, '797171');

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `devices`
--

CREATE TABLE `devices` (
  `device_id` int(7) UNSIGNED NOT NULL,
  `device_user_id` int(7) DEFAULT NULL,
  `device_date` timestamp NULL DEFAULT current_timestamp(),
  `device_alias` varchar(50) DEFAULT '',
  `device_sn` int(7) DEFAULT NULL,
  `device_topic` varchar(50) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb3 COLLATE=utf8mb3_general_ci;

--
-- Volcado de datos para la tabla `devices`
--

INSERT INTO `devices` (`device_id`, `device_user_id`, `device_date`, `device_alias`, `device_sn`, `device_topic`) VALUES
(11, 2, '2022-03-26 13:50:03', 'UTN', 797171, 'QJv7Lh96Q3'),
(12, 2, '2024-04-13 16:42:00', 'TUC', 797179, 'R897ejVxvx');

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `users`
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
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb3 COLLATE=utf8mb3_general_ci;

--
-- Volcado de datos para la tabla `users`
--

INSERT INTO `users` (`user_id`, `fb_user`, `user_date`, `user_name`, `user_email`, `user_password`, `user_image`, `user_selected_device`) VALUES
(2, NULL, '2021-12-04 20:43:52', 'Fulanito', 'demo@demo.com', 'ea7addf05e61754962268a1f44d4f33079249326', 'https://medtucats.fmgambino.info/app/images/iconApp.png', 11);

--
-- Índices para tablas volcadas
--

--
-- Indices de la tabla `data`
--
ALTER TABLE `data`
  ADD PRIMARY KEY (`data_id`);

--
-- Indices de la tabla `devices`
--
ALTER TABLE `devices`
  ADD PRIMARY KEY (`device_id`);

--
-- Indices de la tabla `users`
--
ALTER TABLE `users`
  ADD PRIMARY KEY (`user_id`);

--
-- AUTO_INCREMENT de las tablas volcadas
--

--
-- AUTO_INCREMENT de la tabla `data`
--
ALTER TABLE `data`
  MODIFY `data_id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=15;

--
-- AUTO_INCREMENT de la tabla `devices`
--
ALTER TABLE `devices`
  MODIFY `device_id` int(7) UNSIGNED NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=13;

--
-- AUTO_INCREMENT de la tabla `users`
--
ALTER TABLE `users`
  MODIFY `user_id` int(7) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=3;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
