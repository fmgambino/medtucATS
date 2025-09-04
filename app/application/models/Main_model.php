<?php
defined('BASEPATH') or exit('No direct script access allowed');

// class Main_model extends CI_Model
// {
//   //recuperamos los históricos del dispo seleccionado
//   public function get_data($user_id,$device_id)
//   {
//     $this->db->SELECT();
//     $this->db->FROM('devices_full');
//     $this->db->WHERE('device_id',$device_id);
//     $result =	$this->db->get()->result_array();
//     return $result;
//   }
// }

class Main_model extends CI_Model
{
  //recuperamos los históricos del dispo seleccionado
  // public function get_data($user_id,$device_id)
  // {
  //   $this->db->SELECT();
  //   $this->db->FROM('devices_full');
  //   $this->db->WHERE('device_id',$device_id);
  //   $result =	$this->db->get()->result_array();
  //   return $result;
  // }
  //----------------------------------------------------------------------
  public function get_data($user_id, $device_id)
  {
    // Ejecutar el procedimiento almacenado 
    $query = $this->db->query("CALL get_data('$user_id', '$device_id')");

    if ($query) {
      return $query->result(); // Devuelve los datos de la consulta
    } else {      
      $error = $this->db->error();
      log_message('error', 'Error al traer datos' . $error['message']);
      return array(); // Devolver un array vacío en caso de error
    }
  }

}
