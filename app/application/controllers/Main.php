<?php
defined('BASEPATH') or exit('No direct script access allowed');

class Main extends CI_Controller
{

	public function __construct()
	{
		parent::__construct();

		//si no estas logueado... FUERA!!!
		if (!isset($_SESSION['user_id'])) {
			redirect(base_url('login'), 'refresh');
		}

		//cargamos los modelos que vamos a usar...
		$this->load->model('Main_model');
		$this->load->model('Devices_model');
	}

	// public function index()
	// {
	// 	// Obtener el ID de usuario de la sesión
	// 	$user_id = $this->session->userdata('user_id');

	// 	// Obtener los dispositivos de este usuario
	// 	$data['devices'] = $this->Devices_model->get_devices($user_id);

	// 	// Obtener los datos del dispositivo seleccionado
	// 	$device_data = $this->Main_model->get_data($user_id, $_SESSION['selected_device']);

	// 	// Verificar si hay datos
	// 	if (!empty($device_data)) {
	// 		// Preparar los datos para la vista
	// 		$d1 = "";
	// 		$d2 = "";
	// 		$d3 = "";
	// 		$d4 = "";
	// 		$d5 = "";

	// 		foreach ($device_data as $d) {
	// 			$d1 .= $d['data_co2'] . ",";
	// 			$d2 .= $d['data_tempamb'] . ",";
	// 			$d3 .= $d['data_hum'] . ",";
	// 			$d4 .= $d['data_ph'] . ",";
	// 			$d5 .= "'" . $d['data_date'] . "',";
	// 		}

	// 		// Agregar los datos preparados al arreglo $data
	// 		$data['co2s'] = $d1;
	// 		$data['tempambs'] = $d2;
	// 		$data['hums'] = $d3;
	// 		$data['phs'] = $d4;
	// 		$data['dates'] = $d5;

	// 		// Agregar un mensaje de éxito
	// 		$data['mensaje'] = "¡Los datos se han cargado exitosamente!";
	// 	} else {
	// 		// Si no hay datos, mostrar un mensaje de error
	// 		$data['mensaje'] = "No se encontraron datos para mostrar.";
	// 	}

	// 	// Cargar las partes del panel y pasar los datos a las vistas
	// 	$this->load->view('head');
	// 	$this->load->view('scripts');
	// 	$this->load->view('open');
	// 	$this->load->view('header', $data);
	// 	$this->load->view('sidebar');
	// 	$this->load->view('contents/main', $data);
	// 	$this->load->view('close');
	// }
	
	public function index()
	{
		// Obtener el ID de usuario de la sesión
		$user_id = $this->session->userdata('user_id');

		// Obtener los dispositivos de este usuario
		$data['devices'] = $this->Devices_model->get_devices($user_id);

		// Obtener los datos del dispositivo seleccionado
		$data['device_data'] = $this->Main_model->get_data($user_id, $_SESSION['selected_device']);

		// Cargar las partes del panel y pasar los datos a las vistas
		$this->load->view('head');
		$this->load->view('scripts');
		$this->load->view('open');
		$this->load->view('header', $data);
		$this->load->view('sidebar');
		$this->load->view('contents/main', $data);
		$this->load->view('close');
	}


}
