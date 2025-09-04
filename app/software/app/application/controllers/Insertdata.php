<?php
defined('BASEPATH') OR exit('No direct script access allowed');

class Insertdata extends CI_Controller {

	public function __construct()
	{
		parent::__construct();
		//cargamos el modelo
		$this->load->model('Insertdata_model');
	}

  public function insert(){

		//nos llega la pass que nos pasa el dispositivo,
    $password = strip_tags($this->input->post('idp'));

		//si la pass coincide entonces si le permitimos al dispositivo insertar una fila en la tabla data
		if ($password == INSERT_DATA_PASSWORD){

			//recibimos los datos que nos envía el dispositivo, mediante post...
			$device_sn = strip_tags($this->input->post('sn'));
			$co2 = strip_tags($this->input->post('co2'));
			$tempamb = strip_tags($this->input->post('tempamb'));
			$hum = strip_tags($this->input->post('hum'));
            $ph = strip_tags($this->input->post('ph'));
            

			$result = $this->Insertdata_model->insert($device_sn, $co2, $tempamb, $hum, $ph );

		}else{
			//si la clave no coincide...
			echo "access denied";
		}

  }

}
