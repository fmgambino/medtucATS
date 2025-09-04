-- phpMyAdmin SQL Dump
-- version 5.1.1
-- https://www.phpmyadmin.net/
--
-- Servidor: 127.0.0.1
-- Tiempo de generación: 22-05-2022 a las 01:54:24
-- Versión del servidor: 10.4.21-MariaDB
-- Versión de PHP: 7.3.31

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Base de datos: `antiderrame`
--

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `data`
--

CREATE TABLE `data` (
  `data_id` int(11) NOT NULL,
  `data_date` timestamp NOT NULL DEFAULT current_timestamp(),
  `data_co2` float NOT NULL,
  `data_tempamb` int(11) NOT NULL,
  `data_hum` int(11) NOT NULL,
  `data_ph` float(4,2) NOT NULL,
  `data_device_sn` varchar(10) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Volcado de datos para la tabla `data`
--

INSERT INTO `data` (`data_id`, `data_date`, `data_co2`, `data_tempamb`, `data_hum`, `data_ph`, `data_device_sn`) VALUES
(1, '2021-12-05 02:37:14', 4095, 27, 64, 0.00, '797171'),
(2, '2021-12-05 02:54:10', 2926, 27, 64, 7.03, '797171'),
(3, '2021-12-05 02:54:15', 2926, 27, 64, 7.03, '797171'),
(4, '2021-12-05 02:54:25', 2926, 27, 64, 7.03, '797171'),
(5, '2021-12-05 02:54:30', 2926, 27, 64, 7.03, '797171'),
(6, '2021-12-05 02:54:35', 2926, 27, 64, 7.03, '797171'),
(7, '2021-12-05 02:54:45', 2926, 27, 64, 7.03, '797171'),
(8, '2021-12-05 02:54:50', 2926, 27, 64, 7.03, '797171'),
(9, '2021-12-05 02:54:55', 2926, 27, 64, 7.03, '797171'),
(10, '2021-12-05 02:55:00', 2926, 27, 64, 7.03, '797171'),
(11, '2021-12-05 02:55:05', 2926, 27, 64, 7.03, '797171'),
(12, '2021-12-05 02:55:10', 2926, 27, 64, 7.03, '797171'),
(13, '2021-12-05 03:02:05', 2907, 27, 64, 7.03, '797171');

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
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Volcado de datos para la tabla `devices`
--

INSERT INTO `devices` (`device_id`, `device_user_id`, `device_date`, `device_alias`, `device_sn`, `device_topic`) VALUES
(11, 2, '2022-03-26 13:50:03', 'UTN', 797171, 'QJv7Lh96Q3'),
(18, 2, '2022-05-21 23:49:06', 'prueba', 123456, 'jwdHkQgR8k'),
(19, 2, '2022-05-21 23:49:27', 'prueba', 123897, 't684aSMNUv'),
(20, 2, '2022-05-21 23:49:39', 'prueba', 987213, 'zOrqDIrKAe');

-- --------------------------------------------------------

--
-- Estructura Stand-in para la vista `devices_full`
-- (Véase abajo para la vista actual)
--
CREATE TABLE `devices_full` (
`data_id` int(11)
,`data_date` timestamp
,`data_co2` float
,`data_tempamb` int(11)
,`data_hum` int(11)
,`data_ph` float(4,2)
,`data_device_sn` varchar(10)
,`device_id` int(7) unsigned
);

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
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Volcado de datos para la tabla `users`
--

INSERT INTO `users` (`user_id`, `fb_user`, `user_date`, `user_name`, `user_email`, `user_password`, `user_image`, `user_selected_device`) VALUES
(2, NULL, '2021-12-04 20:43:52', 'Fulanito', 'demo@demo.com', 'ea7addf05e61754962268a1f44d4f33079249326', 'https://hydrocrop.net/app/images/iconApp.png', 11);

-- --------------------------------------------------------

--
-- Estructura para la vista `devices_full`
--
DROP TABLE IF EXISTS `devices_full`;

CREATE ALGORITHM=UNDEFINED DEFINER=`root`@`localhost` SQL SECURITY DEFINER VIEW `devices_full`  AS SELECT `data`.`data_id` AS `data_id`, `data`.`data_date` AS `data_date`, `data`.`data_co2` AS `data_co2`, `data`.`data_tempamb` AS `data_tempamb`, `data`.`data_hum` AS `data_hum`, `data`.`data_ph` AS `data_ph`, `data`.`data_device_sn` AS `data_device_sn`, `devices`.`device_id` AS `device_id` FROM (`data` join `devices`) WHERE `devices`.`device_sn` = `data`.`data_device_sn` ;

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
  MODIFY `data_id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=14;

--
-- AUTO_INCREMENT de la tabla `devices`
--
ALTER TABLE `devices`
  MODIFY `device_id` int(7) UNSIGNED NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=21;

--
-- AUTO_INCREMENT de la tabla `users`
--
ALTER TABLE `users`
  MODIFY `user_id` int(7) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=3;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
