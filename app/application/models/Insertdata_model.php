<?php
defined('BASEPATH') or exit('No direct script access allowed');

class Insertdata_model extends CI_Model
{
  
  public function insert( $device_sn , $data_1 , $data_2 , $data_3 , $data_4 , $data_5 , $data_6 , $data_7 , $data_8 , $data_9 , $data_10 ){


    $data = array(
      'data_device_sn' => $device_sn,
      'data_1' => $data_1,
      'data_2' => $data_2,
      'data_3' => $data_3,
      'data_4' => $data_4,
      'data_5' => $data_5,
      'data_6' => $data_6,
      'data_7' => $data_7,
      'data_8' => $data_8,
      'data_9' => $data_9,
      'data_10' => $data_10      
      
    );

    if ($this->db->insert('data', $data)){
      return "1";
    }else {
      return "0";
    }

  }
}
