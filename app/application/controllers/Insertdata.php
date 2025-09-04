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
			$data_1 = strip_tags($this->input->post('data_1'));
			$data_2 = strip_tags($this->input->post('data_2'));
			$data_3 = strip_tags($this->input->post('data_3'));
			$data_4 = strip_tags($this->input->post('data_4'));
			$data_5 = strip_tags($this->input->post('data_5'));
			$data_6 = strip_tags($this->input->post('data_6'));
			$data_7 = strip_tags($this->input->post('data_7'));
			$data_8 = strip_tags($this->input->post('data_8'));
			$data_9 = strip_tags($this->input->post('data_9'));
			$data_10 = strip_tags($this->input->post('data_10'));
            

			$result = $this->Insertdata_model->insert( $device_sn , $data_1 , $data_2 , $data_3 , $data_4 , $data_5 , $data_6 , $data_7 , $data_8 , $data_9 , $data_10 );
	

		}else{
			//si la clave no coincide...
			echo "access denied";
		}

  }

}
